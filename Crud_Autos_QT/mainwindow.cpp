#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Leer marca y modelo desde QLineEdit
    QString marca = ui->lineEditMarca->text();
    QString modelo = ui->lineEditModelo->text();

    // Leer año desde QSpinBox
    int anio = ui->spinBoxAnio->value();

    // Leer precio desde QLineEdit y convertir a double
    bool ok;
    double precio = ui->lineEditPrecio->text().toDouble(&ok);
    if (!ok) {
        ui->labelMensaje->setText("Precio inválido. Por favor ingresa un número.");
        return;  // salir si precio inválido
    }

    // Validar año
    if (anio < 1950 || anio > 2025) {
        ui->labelMensaje->setText("Año inválido. Debe estar entre 1950 y 2025.");
        return;
    }

    // Crear vehículo nuevo
    vehiculos nuevo;
    nuevo.id = contadorID++;
    nuevo.marca = marca.toStdString();
    nuevo.modelo = modelo.toStdString();
    nuevo.año = anio;
    nuevo.precio = precio;
    nuevo.cantidad = 1;

    // Agregar a la lista global
    listaVehiculos.push_back(nuevo);

    // Mostrar mensaje en QLabel
    ui->labelMensaje->setText("Auto agregado con ID: " + QString::number(nuevo.id));

    // Limpiar campos para próxima entrada
    ui->lineEditMarca->clear();
    ui->lineEditModelo->clear();
    ui->spinBoxAnio->setValue(2025);
    ui->lineEditPrecio->clear();
}



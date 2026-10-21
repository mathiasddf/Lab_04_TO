#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("Países del mundo");
    resize(700, 420);

    auto *principal = new QVBoxLayout(ui->centralwidget);
    auto *titulo = new QLabel("INFORMACIÓN DE PAÍSES", ui->centralwidget);
    auto *contenido = new QHBoxLayout;

    titulo->setAlignment(Qt::AlignCenter);
    titulo->setStyleSheet("font-size: 22px; font-weight: bold; color: #1e3a8a;");

    ui->listaPaises->setMinimumHeight(250);
    ui->listaPaises->setStyleSheet(
        "QListWidget { background: white; border: 1px solid #cbd5e1; "
        "border-radius: 8px; padding: 6px; font-size: 15px; }"
        "QListWidget::item { padding: 8px; }"
        "QListWidget::item:selected { background: #2563eb; color: white; }"
        );

    ui->informacion->setMinimumSize(300, 250);
    ui->informacion->setAlignment(Qt::AlignCenter);
    ui->informacion->setWordWrap(true);
    ui->informacion->setStyleSheet(
        "background: white; color: #1e293b; border: 1px solid #cbd5e1; "
        "border-radius: 8px; padding: 16px; font-size: 18px;"
        );

    contenido->addWidget(ui->listaPaises, 1);
    contenido->addWidget(ui->informacion, 2);

    principal->addWidget(titulo);
    principal->addLayout(contenido);

    datosPaises = {
        {"Perú", "Capital: Lima\nIdioma: español"},
        {"Argentina", "Capital: Buenos Aires\nIdioma: español"},
        {"Brasil", "Capital: Brasilia\nIdioma: portugués"},
        {"Chile", "Capital: Santiago\nIdioma: español"},
        {"Francia", "Capital: París\nIdioma: francés"}
    };

    ui->listaPaises->addItems(datosPaises.keys());

    connect(
        ui->listaPaises,
        &QListWidget::itemClicked,
        this,
        &MainWindow::mostrarInformacion
        );
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::mostrarInformacion(QListWidgetItem *item) {
    ui->informacion->setText(datosPaises.value(item->text()));
}
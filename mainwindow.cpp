#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QFileDialog>
#include <QPushButton>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Batch Transcoder");
    worker = new Worker();
    populateEncoders();
    //    connect(ui->choosePath, &QPushButton::released, this, &MainWindow::choosePath);
}

void MainWindow::populateEncoders(){
    ui->audioEncoders->addItems(worker->getAudioEncoders());
    ui->videoEncoders->addItems(worker->getVideoEncoders());
}

void MainWindow::on_choosePath_released(){
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();
    ui->pathToInput->setText(fileNames.first());
    inDir = fileNames.first();
}

void MainWindow::on_chooseOutPath_released(){
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();
    ui->pathToOutput->setText(fileNames.first());
    outDir = fileNames.first();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete worker;
}


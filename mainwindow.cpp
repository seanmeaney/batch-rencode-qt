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
    audioEncoder = nullptr;
    vidEncoder = nullptr;
    //    connect(ui->choosePath, &QPushButton::released, this, &MainWindow::choosePath);
}

void MainWindow::populateEncoders(){
    ui->audioEncoders->clear();
    ui->videoEncoders->clear();

    if (ui->onlyRecomended->isChecked()){
        ui->audioEncoders->addItems(recommendedAudioCodecs.toSet().intersect(worker->getAudioEncoders().toSet()).toList());
        ui->videoEncoders->addItems(recommendedVideoCodecs.toSet().intersect(worker->getVideoEncoders().toSet()).toList());
    } else {
        ui->audioEncoders->addItems(worker->getAudioEncoders());
        ui->videoEncoders->addItems(worker->getVideoEncoders());
    }
}

void MainWindow::on_audioEncoders_currentTextChanged(const QString &text){
    audioEncoder = new Codec(text, 2);
}

void MainWindow::on_videoEncoders_currentTextChanged(const QString &text){
    vidEncoder = new Codec(text, 1);
}

void MainWindow::on_onlyRecomended_released(){
    populateEncoders();
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


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
    audioEncoder = nullptr;
    vidEncoder = nullptr;
}

void MainWindow::populateEncoders(){
    ui->audioEncoders->clear();
    ui->videoEncoders->clear();

    //kinda hacky but fine for now
    if (ui->onlyRecomended->isChecked()){
        ui->audioEncoders->addItems(recommendedAudioCodecs.toSet().intersect(worker->getAudioEncoders().toSet()).toList());
        ui->videoEncoders->addItems(recommendedVideoCodecs.toSet().intersect(worker->getVideoEncoders().toSet()).toList());
    } else {
        ui->audioEncoders->addItems(worker->getAudioEncoders());
        ui->videoEncoders->addItems(worker->getVideoEncoders());
    }
}

void MainWindow::on_startConversion_released(){
    for (const QString& vid : qAsConst(inVids)){
        QString outVid = vid;
        QString::iterator outI = outVid.end();

        //file is already known to have an exension so looking for . is safe
        while (outI != outVid.begin()){
            outI--;
            if (*outI == "."){
                outVid.chop(1);
                outVid.append("_rencoded.mkv");
                break;
            }
            outVid.chop(1);
        }
        worker->startConversion(inDir + QDir::separator() + vid, outDir + QDir::separator() + outVid, audioEncoder, vidEncoder);
    }
}

void MainWindow::on_audioEncoders_currentTextChanged(const QString &text){
    audioEncoder = worker->getCodec(text);
}

void MainWindow::on_videoEncoders_currentTextChanged(const QString &text){
    vidEncoder = worker->getCodec(text);
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

    inVids = worker->findVideos(inDir);

    if (inDir != nullptr && outDir != nullptr)
        ui->startConversion->setEnabled(true);
}

void MainWindow::on_chooseOutPath_released(){
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();
    ui->pathToOutput->setText(fileNames.first());
    outDir = fileNames.first();
    if (inDir != nullptr && outDir != nullptr)
        ui->startConversion->setEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete worker;
}


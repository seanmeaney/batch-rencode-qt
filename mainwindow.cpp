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
    findFFmpegPath();
    worker = new Worker(ffPath);
    worker->getSupportedCodecs();
//    worker->parseExtraCodecData();
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
    audioEncoder = (AudioCodec *) worker->getCodec("aac");
    vidEncoder = (VideoCodec *) worker->getCodec("libx264");
    for (const QString& vid : qAsConst(inVids)){
        QString outVid = QFileInfo(vid).completeBaseName() + "_rencoded.mkv";
        worker->startConversion(inDir + QDir::separator() + vid, outDir + QDir::separator() + outVid, audioEncoder, vidEncoder);
    }
}

void MainWindow::on_audioEncoders_currentTextChanged(const QString &text){
    audioEncoder = (AudioCodec *) worker->getCodec(text);
}

void MainWindow::on_videoEncoders_currentTextChanged(const QString &text){
    vidEncoder = (VideoCodec *) worker->getCodec(text);
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

bool MainWindow::findFFmpegPath(){
    QString path(std::getenv("PATH"));
#ifdef _WIN32
    QStringList pathSeperated = path.split(";");
    for (QString& s : pathSeperated){
        if (QDir(s).entryList().contains("ffmpeg.exe")){
            ffPath = s;
            ffPath.append("\ffmpeg.exe");
        }
    }
#else
    QStringList pathSeperated = path.split(":");
    for (QString& s : pathSeperated){
        if (QDir(s).entryList().contains("ffmpeg")){
            ffPath = s;
            ffPath.append("/ffmpeg");
        }
    }
#endif
    return !ffPath.isNull();
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


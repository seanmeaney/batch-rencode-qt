#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QPushButton>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Batch Transcoder");
    findFFmpegPath();
    worker = new Worker(ffPath);
    worker->getSupportedCodecs();
    populateEncoders();
    audioEncoder = nullptr;
    vidEncoder = nullptr;
    readCodecSupport();


    connect(ui->onlyRecomended, &QPushButton::released, this, &MainWindow::showTheseEncoders);
    connect(ui->audioEncoders, SIGNAL(currentTextChanged(QString)), this, SLOT(changeAudioEncoder(QString)));
    connect(ui->videoEncoders, SIGNAL(currentTextChanged(QString)), this, SLOT(changeVideoEncoder(QString)));
    connect(ui->startConversion, &QPushButton::released, this, &MainWindow::startTranscode);

    connect(ui->choosePath, &QPushButton::released, this, &MainWindow::updatePath);
    connect(ui->chooseOutPath, &QPushButton::released, this, &MainWindow::updatePath);
}

QJsonDocument MainWindow::readCodecSupport(){
    QFile file("/home/sean/batch-rencode-qt/codecSupport.json"); //change this
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray rawData = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(rawData);
    QJsonObject object = d.object();
    QJsonArray audioSupport = object.value(QString("audioCodecs")).toArray();
    QJsonArray videoSupport = object.value(QString("videoCodecs")).toArray();
    return d;
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

void MainWindow::startTranscode(){
    audioEncoder = (AudioCodec *) worker->getCodec("aac");
    vidEncoder = (VideoCodec *) worker->getCodec("libx264");
    for (const QString& vid : qAsConst(inVids)){
        QString outVid = QFileInfo(vid).completeBaseName() + "_rencoded.mkv";
        worker->startConversion(inDir + QDir::separator() + vid, outDir + QDir::separator() + outVid, audioEncoder, vidEncoder);
    }
}

void MainWindow::changeAudioEncoder(const QString &text){
    audioEncoder = (AudioCodec *) worker->getCodec(text);
}

void MainWindow::changeVideoEncoder(const QString &text){
    vidEncoder = (VideoCodec *) worker->getCodec(text);
}

void MainWindow::showTheseEncoders(){
    populateEncoders();
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

void MainWindow::updatePath(){
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();
    ui->pathToInput->setText(fileNames.first());

    if (sender() == ui->choosePath){
        inDir = fileNames.first();
        inVids = worker->findVideos(inDir);
    } else{
        outDir = fileNames.first();
    }

    if (inDir != nullptr && outDir != nullptr)
        ui->startConversion->setEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete worker;
}


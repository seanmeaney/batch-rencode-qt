/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *startConversion;
    QFrame *pathsFrame;
    QLineEdit *pathToInput;
    QLineEdit *pathToOutput;
    QPushButton *choosePath;
    QPushButton *chooseOutPath;
    QRadioButton *deleteInput;
    QLabel *label;
    QFrame *optionsFrame;
    QLabel *label_2;
    QComboBox *videoEncoders;
    QComboBox *audioEncoders;
    QRadioButton *overwriteOutput;
    QRadioButton *fastStart;
    QComboBox *comboBox;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QCheckBox *onlyRecomended;
    QMenuBar *menubar;
    QMenu *menuBatch_Transcoder;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        startConversion = new QPushButton(centralwidget);
        startConversion->setObjectName(QString::fromUtf8("startConversion"));
        startConversion->setGeometry(QRect(340, 510, 83, 25));
        pathsFrame = new QFrame(centralwidget);
        pathsFrame->setObjectName(QString::fromUtf8("pathsFrame"));
        pathsFrame->setGeometry(QRect(10, 10, 781, 191));
        pathsFrame->setFrameShape(QFrame::StyledPanel);
        pathsFrame->setFrameShadow(QFrame::Raised);
        pathToInput = new QLineEdit(pathsFrame);
        pathToInput->setObjectName(QString::fromUtf8("pathToInput"));
        pathToInput->setGeometry(QRect(40, 40, 301, 25));
        pathToInput->setReadOnly(true);
        pathToOutput = new QLineEdit(pathsFrame);
        pathToOutput->setObjectName(QString::fromUtf8("pathToOutput"));
        pathToOutput->setGeometry(QRect(40, 110, 301, 25));
        pathToOutput->setReadOnly(true);
        choosePath = new QPushButton(pathsFrame);
        choosePath->setObjectName(QString::fromUtf8("choosePath"));
        choosePath->setGeometry(QRect(370, 40, 83, 25));
        chooseOutPath = new QPushButton(pathsFrame);
        chooseOutPath->setObjectName(QString::fromUtf8("chooseOutPath"));
        chooseOutPath->setGeometry(QRect(370, 110, 83, 25));
        deleteInput = new QRadioButton(pathsFrame);
        deleteInput->setObjectName(QString::fromUtf8("deleteInput"));
        deleteInput->setGeometry(QRect(480, 80, 261, 23));
        label = new QLabel(pathsFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 10, 81, 17));
        optionsFrame = new QFrame(centralwidget);
        optionsFrame->setObjectName(QString::fromUtf8("optionsFrame"));
        optionsFrame->setGeometry(QRect(10, 210, 771, 281));
        optionsFrame->setFrameShape(QFrame::StyledPanel);
        optionsFrame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(optionsFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(320, 0, 131, 17));
        videoEncoders = new QComboBox(optionsFrame);
        videoEncoders->setObjectName(QString::fromUtf8("videoEncoders"));
        videoEncoders->setGeometry(QRect(30, 60, 171, 25));
        audioEncoders = new QComboBox(optionsFrame);
        audioEncoders->setObjectName(QString::fromUtf8("audioEncoders"));
        audioEncoders->setGeometry(QRect(30, 120, 171, 25));
        overwriteOutput = new QRadioButton(optionsFrame);
        overwriteOutput->setObjectName(QString::fromUtf8("overwriteOutput"));
        overwriteOutput->setGeometry(QRect(60, 210, 106, 23));
        fastStart = new QRadioButton(optionsFrame);
        fastStart->setObjectName(QString::fromUtf8("fastStart"));
        fastStart->setGeometry(QRect(250, 210, 331, 23));
        comboBox = new QComboBox(optionsFrame);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(240, 60, 86, 25));
        label_3 = new QLabel(optionsFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 30, 101, 17));
        label_4 = new QLabel(optionsFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(260, 30, 62, 17));
        label_5 = new QLabel(optionsFrame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(400, 30, 62, 17));
        lineEdit = new QLineEdit(optionsFrame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(360, 60, 113, 25));
        label_6 = new QLabel(optionsFrame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 100, 101, 17));
        label_7 = new QLabel(optionsFrame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(240, 100, 101, 17));
        lineEdit_2 = new QLineEdit(optionsFrame);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(230, 120, 113, 25));
        onlyRecomended = new QCheckBox(centralwidget);
        onlyRecomended->setObjectName(QString::fromUtf8("onlyRecomended"));
        onlyRecomended->setGeometry(QRect(500, 510, 241, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuBatch_Transcoder = new QMenu(menubar);
        menuBatch_Transcoder->setObjectName(QString::fromUtf8("menuBatch_Transcoder"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuBatch_Transcoder->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startConversion->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pathToInput->setText(QString());
        pathToInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Input Path", nullptr));
        pathToOutput->setText(QString());
        pathToOutput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Output Path", nullptr));
        choosePath->setText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        chooseOutPath->setText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        deleteInput->setText(QCoreApplication::translate("MainWindow", "delete input after transcode", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Media Paths", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "FFmpeg options", nullptr));
        overwriteOutput->setText(QCoreApplication::translate("MainWindow", "overwrite", nullptr));
        fastStart->setText(QCoreApplication::translate("MainWindow", "fast Start (only applies to certain containers)", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Video Encoder", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Preset", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Crf", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Audio Encoder", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Bitrate (kbps)", nullptr));
        onlyRecomended->setText(QCoreApplication::translate("MainWindow", "show only recomended encoders", nullptr));
        menuBatch_Transcoder->setTitle(QCoreApplication::translate("MainWindow", "temp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

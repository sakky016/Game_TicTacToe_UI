/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *lblMarker1;
    QLabel *lblMarker2;
    QGridLayout *gridLayout_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblUserMarker;
    QLineEdit *scoreUser;
    QHBoxLayout *horizontalLayout;
    QLabel *lblComputerMarker;
    QLineEdit *scoreComputer;
    QFrame *frame;
    QGridLayout *gridLayout;
    QPushButton *btnPos1;
    QFrame *line_5;
    QPushButton *btnPos6;
    QFrame *line_19;
    QFrame *line_18;
    QFrame *line;
    QPushButton *btnPos4;
    QFrame *line_4;
    QFrame *line_2;
    QFrame *line_3;
    QPushButton *btnPos2;
    QPushButton *btnPos7;
    QPushButton *btnPos3;
    QPushButton *btnPos5;
    QFrame *line_11;
    QPushButton *btnPos9;
    QPushButton *btnPos8;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnNewGame;
    QPushButton *btnQuit;
    QMenuBar *menubar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 269);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lblMarker1 = new QLabel(centralwidget);
        lblMarker1->setObjectName(QString::fromUtf8("lblMarker1"));
        lblMarker1->setGeometry(QRect(30, 50, 16, 16));
        QFont font;
        font.setPointSize(14);
        lblMarker1->setFont(font);
        lblMarker2 = new QLabel(centralwidget);
        lblMarker2->setObjectName(QString::fromUtf8("lblMarker2"));
        lblMarker2->setGeometry(QRect(190, 50, 16, 16));
        lblMarker2->setFont(font);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lblUserMarker = new QLabel(frame_2);
        lblUserMarker->setObjectName(QString::fromUtf8("lblUserMarker"));
        lblUserMarker->setFont(font);

        horizontalLayout_2->addWidget(lblUserMarker);

        scoreUser = new QLineEdit(frame_2);
        scoreUser->setObjectName(QString::fromUtf8("scoreUser"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe Print"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        scoreUser->setFont(font1);
        scoreUser->setReadOnly(true);

        horizontalLayout_2->addWidget(scoreUser);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lblComputerMarker = new QLabel(frame_2);
        lblComputerMarker->setObjectName(QString::fromUtf8("lblComputerMarker"));
        lblComputerMarker->setFont(font);

        horizontalLayout->addWidget(lblComputerMarker);

        scoreComputer = new QLineEdit(frame_2);
        scoreComputer->setObjectName(QString::fromUtf8("scoreComputer"));
        scoreComputer->setFont(font1);
        scoreComputer->setReadOnly(true);

        horizontalLayout->addWidget(scoreComputer);


        horizontalLayout_3->addLayout(horizontalLayout);


        gridLayout_2->addWidget(frame_2, 0, 0, 1, 2);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        frame->setFont(font2);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnPos1 = new QPushButton(frame);
        btnPos1->setObjectName(QString::fromUtf8("btnPos1"));
        btnPos1->setEnabled(false);
        QFont font3;
        font3.setFamily(QString::fromUtf8("MV Boli"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        btnPos1->setFont(font3);

        gridLayout->addWidget(btnPos1, 0, 0, 1, 1);

        line_5 = new QFrame(frame);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 2, 1, 1, 1);

        btnPos6 = new QPushButton(frame);
        btnPos6->setObjectName(QString::fromUtf8("btnPos6"));
        btnPos6->setEnabled(false);
        btnPos6->setFont(font3);

        gridLayout->addWidget(btnPos6, 2, 4, 1, 1);

        line_19 = new QFrame(frame);
        line_19->setObjectName(QString::fromUtf8("line_19"));
        line_19->setFrameShape(QFrame::VLine);
        line_19->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_19, 4, 3, 1, 1);

        line_18 = new QFrame(frame);
        line_18->setObjectName(QString::fromUtf8("line_18"));
        line_18->setFrameShape(QFrame::VLine);
        line_18->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_18, 0, 3, 1, 1);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 6);

        btnPos4 = new QPushButton(frame);
        btnPos4->setObjectName(QString::fromUtf8("btnPos4"));
        btnPos4->setEnabled(false);
        btnPos4->setFont(font3);

        gridLayout->addWidget(btnPos4, 2, 0, 1, 1);

        line_4 = new QFrame(frame);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 2, 3, 1, 1);

        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 3, 0, 1, 6);

        line_3 = new QFrame(frame);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 0, 1, 1, 1);

        btnPos2 = new QPushButton(frame);
        btnPos2->setObjectName(QString::fromUtf8("btnPos2"));
        btnPos2->setEnabled(false);
        btnPos2->setFont(font3);

        gridLayout->addWidget(btnPos2, 0, 2, 1, 1);

        btnPos7 = new QPushButton(frame);
        btnPos7->setObjectName(QString::fromUtf8("btnPos7"));
        btnPos7->setEnabled(false);
        btnPos7->setFont(font3);

        gridLayout->addWidget(btnPos7, 4, 0, 1, 1);

        btnPos3 = new QPushButton(frame);
        btnPos3->setObjectName(QString::fromUtf8("btnPos3"));
        btnPos3->setEnabled(false);
        btnPos3->setFont(font3);

        gridLayout->addWidget(btnPos3, 0, 4, 1, 1);

        btnPos5 = new QPushButton(frame);
        btnPos5->setObjectName(QString::fromUtf8("btnPos5"));
        btnPos5->setEnabled(false);
        btnPos5->setFont(font3);

        gridLayout->addWidget(btnPos5, 2, 2, 1, 1);

        line_11 = new QFrame(frame);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_11, 4, 1, 1, 1);

        btnPos9 = new QPushButton(frame);
        btnPos9->setObjectName(QString::fromUtf8("btnPos9"));
        btnPos9->setEnabled(false);
        btnPos9->setFont(font3);

        gridLayout->addWidget(btnPos9, 4, 4, 1, 1);

        btnPos8 = new QPushButton(frame);
        btnPos8->setObjectName(QString::fromUtf8("btnPos8"));
        btnPos8->setEnabled(false);
        btnPos8->setFont(font3);

        gridLayout->addWidget(btnPos8, 4, 2, 1, 1);


        gridLayout_2->addWidget(frame, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        btnNewGame = new QPushButton(centralwidget);
        btnNewGame->setObjectName(QString::fromUtf8("btnNewGame"));

        verticalLayout->addWidget(btnNewGame);

        btnQuit = new QPushButton(centralwidget);
        btnQuit->setObjectName(QString::fromUtf8("btnQuit"));

        verticalLayout->addWidget(btnQuit);


        gridLayout_2->addLayout(verticalLayout, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 21));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Tic Tac Toe", nullptr));
        lblMarker1->setText(QString());
        lblMarker2->setText(QString());
        lblUserMarker->setText(QApplication::translate("MainWindow", "You", nullptr));
        scoreUser->setText(QApplication::translate("MainWindow", "0", nullptr));
        lblComputerMarker->setText(QApplication::translate("MainWindow", "Computer", nullptr));
        scoreComputer->setText(QApplication::translate("MainWindow", "0", nullptr));
        btnPos1->setText(QApplication::translate("MainWindow", ".", nullptr));
        btnPos6->setText(QApplication::translate("MainWindow", ".", nullptr));
        btnPos4->setText(QApplication::translate("MainWindow", ".", nullptr));
        btnPos2->setText(QApplication::translate("MainWindow", ".", nullptr));
        btnPos7->setText(QApplication::translate("MainWindow", ".", nullptr));
        btnPos3->setText(QApplication::translate("MainWindow", ".", nullptr));
        btnPos5->setText(QApplication::translate("MainWindow", ".", nullptr));
        btnPos9->setText(QApplication::translate("MainWindow", ".", nullptr));
        btnPos8->setText(QApplication::translate("MainWindow", ".", nullptr));
        btnNewGame->setText(QApplication::translate("MainWindow", "New Game", nullptr));
        btnQuit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

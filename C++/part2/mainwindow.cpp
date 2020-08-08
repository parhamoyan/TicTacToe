#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QMouseEvent>
#include <iostream>
#include "TicTacToe.cpp"
#include <QMessageBox>

TicTacToe game;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Tic Tac Toe");
    setFixedSize(680,680);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
    
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            labels[i][j] = new QLabel(this);
        }
    }
    
    QPushButton resetButton;
    
}

MainWindow::~MainWindow()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            delete labels[i][j];
        }
    }
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    // WHITE, GRAY, BLUE, RED

    QColor white(234,234,234);
    colors.push_back(white);

    QColor gray(100,100,100);
    colors.push_back(gray);

    QColor blue(53,152,254);
    colors.push_back(blue);

    QColor red(255,51,52);
    colors.push_back(red);


    QPainter *painter =  new QPainter(this);
    QPen pen(colors[COLORS::GRAY]);
    pen.setWidth(0);
    painter->setPen(pen);
    painter->setBrush(colors[COLORS::GRAY]);

    QRect rect1(QPoint(220, 20), QSize(20, 640));
    painter->drawRect(rect1);

    QRect rect2(QPoint(440, 20), QSize(20, 640));
    painter->drawRect(rect2);

    QRect rect3(QPoint(20, 220), QSize(640, 20));
    painter->drawRect(rect3);

    QRect rect4(QPoint(20, 440), QSize(640, 20));
    painter->drawRect(rect4);

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(game.getPosPlayer(i, j)==1)
            {
                labels[i][j]->setGeometry(30+220*j,20+220*i,200,200);
                labels[i][j]->setPixmap(QPixmap("X_PLAYER.png").scaled(QSize(180, 180)));
            }
            else if(game.getPosPlayer(i, j)==2)
            {
                labels[i][j]->setGeometry(30+220*j,20+220*i,200,200);
                labels[i][j]->setPixmap(QPixmap("O_PLAYER.png").scaled(QSize(180, 180)));
            }
        }
    }
    delete painter;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(game.checkWin()==0)
    {
        if(game.choiceValidity((event->pos().y())/(680/3), (event->pos().x())/(680/3)))
        {
            game.play((event->pos().y())/(680/3), (event->pos().x())/(680/3));
            game.changePlayer();
            update();
        }
    }
    if(game.checkWin()!=0)
    {
        QMessageBox msgBox(this);
        msgBox.setDefaultButton(QMessageBox::Save);
        switch(game.checkWin())
        {
        case 1:
        {
            msgBox.setText("Player X has won !");
            msgBox.exec();
            break;
        }
        case 2:
        {
            msgBox.setText("Player O has won !");
            msgBox.exec();
            break;
        }
        case 3:
        {
            msgBox.setText("Draw");
            msgBox.exec();
            break;
        }
        default:
            break;
        }
    }
}

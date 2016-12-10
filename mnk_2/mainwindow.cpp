#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mnk.h"
#include <QDebug>
#include "qcustomplot.h"
using namespace std;
void MainWindow::draw(QVector<double>& x,QVector<double>& y)
{

        ui->widget->addGraph();
        //Говорим, что отрисовать нужно график по нашим двум массивам x и y
        ui->widget->graph(0)->setData(x, y);

        //Подписываем оси Ox и Oy
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");

        //Установим область, которая будет показываться на графике
        double maxx=*std::max_element(x.begin(),x.end());
        double minx=*std::min_element(x.begin(),x.end());
        ui->widget->xAxis->setRange(minx, maxx);//Для оси Ox

        //Для показа границ по оси Oy сложнее, так как надо по правильному
        //вычислить минимальное и максимальное значение в векторах
        double maxy=*std::max_element(y.begin(),y.end());
        double miny=*std::min_element(y.begin(),y.end());

        ui->widget->yAxis->setRange(miny,maxy);//Для оси Oy

        //И перерисуем график на нашем widget
        ui->widget->replot();

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    action_mnk(-5,5,3);
    ui->lineEdit->setText(QString::number(3));
    ui->lineEdit_2->setText(QString::number(-5));
    ui->lineEdit_3->setText(QString::number(5));





}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::action_mnk(double a, double b, int k)
{
    mnk test(a,b,k);
    QVector<double> x,y;
    for(int i=a;i<=b;i+=1)
    {
        x.push_back(i);
        y.push_back(test.func(i));
    }
    draw(x,y);


}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(100);
    ui->lineEdit->setText(QString::number(value));
    double a=ui->lineEdit_2->text().toDouble();
    double b=ui->lineEdit_3->text().toDouble();
    action_mnk(a,b,value);

}

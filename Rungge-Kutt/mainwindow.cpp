#include "mainwindow.h"
#include "ui_mainwindow.h"
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
double MainWindow::func(double x,double y)
{
    return x*x-2*y;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

        double y0=0,h=0.1,k1,k2,k3,k4;
        QVector<double> x,y;
        x.push_back(0);
        y.push_back(y0);
        for(double i=h;i<=20;i+=h)
        {
            k1=func(i,y0);
            k2=func(i+h/2,y0+h*k1/2);
            k3=func(i+h/2,y0+h*k2/2);
            k4=func(i+h,y0+h*k3);
            y0=y0+h/6*(k1+2*k2+2*k3+k4);
            x.push_back(i);
            y.push_back(y0);
            qDebug()<<i<<" "<<y0;
        }
        draw(x,y);
}

MainWindow::~MainWindow()
{
    delete ui;
}

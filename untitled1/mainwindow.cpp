#include "mainwindow.h"
#include "ui_mainwindow.h"

double MainWindow::c(int m, int n)
{
    return x[n]*exp(t[m]);
}
double MainWindow::fi(int m, int n)
{
    return sin(x[n])+x[n]*exp(t[m])*t[m]*cos(x[n]);;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


        len=100;
        x.resize(len);
        t.resize(len);
        y.resize(len);
        for(int i=0;i<len;i++)
            y[i].resize(len);
        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++)
                y[i][j]=0;


        for(int i=0;i<len;i++)
        {
            x[i]=i;
            t[i]=i;
            y[0][i]=i;
            y[i][0]=i;
        }
        xmin=x[0];
        xmax=x[0];
        for(int i=1;i<len;i++)
        {
            if(x[i]<xmin)
                xmin=x[i];
            if(x[i]>xmax)
                xmax=x[i];

        }
        y.resize(len);
        for(int i=0;i<len;i++)
            y[i].resize(len);
        for(int m=1;m<len-1;m++)
            for(int n=1;n<len;n++)
        {
                if (c(m,n)*(t[m+1]-t[m])<=(x[n]-x[n-1]))
            y[m+1][n]=(fi(m,n))-(c(m,n)/(x[n]-x[n-1])*(y[m][n]-y[m][n-1]))*(t[m+1]-t[m])+y[m][n];
                else
//                   y[m+1][n-1]=(fi(m,n))-(c(m,n)/(x[n]-x[n-1]))*(t[m+1]-t[m])+y[m][n-1];
                   y[m+1][n-1]=fi(m,n)-(1/(t[m+1]-t[m])*(y[m+1][n-1]-y[m][n-1]))*(x[n]-x[n-1])/c(m,n)+y[m+1][n-1];

        }

        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++)
    {
                QString temp = QString::number(y[i][j]);
                qDebug(temp.toStdString().data());
          }
        int k=30;
        ui->widget->clearGraphs();
        ui->widget->addGraph();
        ui->widget->graph(0)->setData(x, y[k]);

        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");

        ui->widget->xAxis->setRange(xmin, xmax-1);

        double ymin=y[k][0];
        double ymax=y[k][0];

        for(int i=1;i<len;i++)
        {
            if(y[k][i]<ymin)
                ymin=y[k][i];
            if(y[k][i]>ymax)
                ymax=y[k][i];

        }

//        double minY = y[0], maxY = y[0];
//        for (int i=1; i<5; i++)
//        {
//            if (y[i]<minY) minY = y[i];
//            if (y[i]>maxY) maxY = y[i];
//        }
        ui->widget->yAxis->setRange(ymin, ymax);

        ui->widget->replot();

        ui->horizontalSlider->setMinimum(0);
        ui->horizontalSlider->setMaximum(len-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    int k=ui->horizontalSlider->value();
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y[k]);

    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    ui->widget->xAxis->setRange(xmin, xmax-1);

    double ymin=y[k][0];
    double ymax=y[k][0];

    for(int i=1;i<len;i++)
    {
        if(y[k][i]<ymin)
            ymin=y[k][i];
        if(y[k][i]>ymax)
            ymax=y[k][i];

    }

    ui->widget->yAxis->setRange(ymin, ymax);

    ui->widget->replot();

    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(len-1);
    QString temp = QString::number(t[k]);

    ui->lineEdit->setText(temp);
}

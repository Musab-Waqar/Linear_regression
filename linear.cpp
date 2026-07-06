#include "linear.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
LinearRegression::LinearRegression()
{
    m=0;
    c=0;
}

void LinearRegression::adddata(double x,double y)
{
    xdata.push_back(x);
    ydata.push_back(y);
}

void LinearRegression::fit(){
    int n=xdata.size();
    double sumx=0;
    double sumy=0;
    double sumxy=0;
    double sumx2=0;

    for(int i=0; i<n ;i ++){
        sumx+=xdata[i];
        sumy+=ydata[i];
        sumxy+=xdata[i]*ydata[i];
        sumx2+=xdata[i]*xdata[i];
    }
    m=(n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);

    c=(sumy-m*sumx)/n;
}
double LinearRegression::predict(double x)
{

    return m*x+c;
}
double LinearRegression::rSquared(){
    int n=ydata.size();
    double meany=0;
    for (int i=0;i<n ;i++){
        meany+=ydata[i];
    }
    meany=meany/n;
    double ssres=0;
    double sstot=0;
    for (int i=0;i<n;i++){
        double predicted=predict(xdata[i]);
        ssres+=(ydata[i]-predicted)*(ydata[i]-predicted);
        sstot+=(ydata[i]-meany)*(ydata[i]-meany);
    }

    return 1-(ssres/sstot);
}

bool LinearRegression::loadFromCsv(const QString &filename)
{
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&file);

    xdata.clear();
    ydata.clear();
    bool firsline=true;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");

        if (parts.size() == 2) {
            double x = parts[0].toDouble();
            double y = parts[1].toDouble();
            adddata(x, y);
        }
    }

    file.close();
    return true;
}
QVector<double> LinearRegression::getX() const
{
    return xdata;
}

QVector<double> LinearRegression::getY() const
{
    return ydata;
}
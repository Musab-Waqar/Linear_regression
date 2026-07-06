#ifndef LINEAR_H
#define LINEAR_H

#include <QVector>
#include <QString>
class LinearRegression{
private:
    QVector<double> xdata;
    QVector<double> ydata;
    double m;
    double c;
public:
    QVector<double> getX() const;
    QVector<double> getY() const;
    LinearRegression();
    void adddata(double a ,double b);
    void fit();
    double predict(double x);
    double rSquared();
    bool loadFromCsv(const QString &filename);

};




#endif // LINEAR_H

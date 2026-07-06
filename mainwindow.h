#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QLineSeries>
#include <QMainWindow>
#include <QDragEnterEvent>
#include <QDropEvent>
#include "linear.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private slots:
    void on_btnCompute_clicked();
    void on_btnPredict_clicked();

private:
    Ui::MainWindow *ui;
    LinearRegression model;
     QChartView *chartView;
    void updateChart();
     bool hasPrediction = false;
     double predictedX = 0;
     double predictedY = 0;
};
#endif // MAINWINDOW_H

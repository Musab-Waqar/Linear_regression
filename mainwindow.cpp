#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMimeData>
#include <QUrl>
#include <QVBoxLayout>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    chartView=new QChartView(this);
    chartView->setRenderHint(QPainter::Antialiasing);
    QVBoxLayout *layout= new QVBoxLayout(ui->chartContainer);
    layout->addWidget(chartView);
    ui->chartContainer->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls()){
        event->acceptProposedAction();
    }
}
void MainWindow::dropEvent(QDropEvent *event)

{
    QList<QUrl> urls =event->mimeData()->urls();
    if(urls.isEmpty())  {return;}
    QString filePath=    urls.first().toLocalFile();
    bool success=model.loadFromCsv(filePath);
    if(success){
        ui->labelInstructions->setText("CSV loaded Successfully");

    }
    else{ui->labelInstructions->setText("failed to load csv");
    }
}

void MainWindow::on_btnCompute_clicked(){
    model.fit();
    double slope = model.predict(1) - model.predict(0); // just to get m directly if needed later
    double rsq = model.rSquared();

    ui->labelEquation->setText("computed");
    ui->labelRSquared->setText("R² = " + QString::number(rsq));
    updateChart();
}

void MainWindow::on_btnPredict_clicked()
{
    double x = ui->lineEditX->text().toDouble();
    double y = model.predict(x);

    ui->labelPrediction->setText("y:" + QString::number(y));
    predictedX=x;
    predictedY=y;
    hasPrediction=true;
    updateChart();
}
void MainWindow::updateChart()
{
    QScatterSeries *scatter = new QScatterSeries();
    scatter->setName("Data Points");

    QLineSeries *line = new QLineSeries();
    line->setName("Regression Line");

    QVector<double> xVals = model.getX();
    QVector<double> yVals = model.getY();

    int n = xVals.size();

    for (int i = 0; i < n; i++) {
        scatter->append(xVals[i], yVals[i]);
    }
  double minX = 0, maxX = 0;
    if (n > 0) {
        double minX = xVals[0];
        double maxX = xVals[0];

        for (int i = 1; i < n; i++) {
            if (xVals[i] < minX) minX = xVals[i];
            if (xVals[i] > maxX) maxX = xVals[i];
        }

         }
    if (hasPrediction) {
        if (predictedX < minX) minX = predictedX;
        if (predictedX > maxX) maxX = predictedX;
    }

    if (n > 0 || hasPrediction) {
        line->append(minX, model.predict(minX));
        line->append(maxX, model.predict(maxX));
    }


    QChart *chart = new QChart();
    chart->addSeries(scatter);
    chart->addSeries(line);
    if (hasPrediction) {
        QScatterSeries *predictedPoint = new QScatterSeries();
        predictedPoint->setName("Predicted Point");
        predictedPoint->setColor(Qt::red);
        predictedPoint->setMarkerSize(15.0);
        predictedPoint->append(predictedX, predictedY);
        chart->addSeries(predictedPoint);
    }
    chart->createDefaultAxes();
    chart->setTitle("Linear Regression");

    chartView->setChart(chart);
}
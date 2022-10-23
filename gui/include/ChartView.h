#pragma once

#include <QDateTime>
#include <QtCharts/QChartView>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

class ChartView : public QChartView {
    Q_OBJECT
  public:
    explicit ChartView(QChart* chart, QWidget* parent = nullptr)
        : QChartView(chart, parent),
          chart_(chart),
          axis_x_(new QDateTimeAxis()),
          axis_y_(new QValueAxis()),
          price_series_(new QLineSeries()) {
        min_dt_ = QDateTime::currentDateTime();

        chart->legend()->hide();
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->addSeries(price_series_);

        chart->addAxis(axis_x_, Qt::AlignBottom);
        chart->addAxis(axis_y_, Qt::AlignLeft);

        price_series_->attachAxis(axis_x_);
        price_series_->attachAxis(axis_y_);
    }
    void addPoint(double value) {
        auto update_range = [this]() {
            axis_y_->setRange(price_min_, price_max_);
        };

        const auto moment_time = QDateTime::currentDateTime();
        if (price_series_->count() == 0) {
            price_min_ = value - 1;
            price_max_ = value + 1;
        } else {
            price_min_ = std::min(price_min_, value - 1);
            price_max_ = std::max(price_max_, value + 1);
        }
        update_range();
        price_series_->append(moment_time.toMSecsSinceEpoch(), value);
        axis_x_->setRange(min_dt_, moment_time);
        qDebug() << "x y" << moment_time.toMSecsSinceEpoch() << value;
    }

  private:
    double price_min_;
    double price_max_;
    QDateTime min_dt_;
    QValueAxis* axis_y_;
    QDateTimeAxis* axis_x_;
    QChart* chart_;
    QLineSeries* price_series_;
};

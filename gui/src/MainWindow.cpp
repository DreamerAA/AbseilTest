#include "MainWindow.h"

MainWindow::MainWindow(IModel *imodel) : QMainWindow(), imodel_(imodel) {
    auto *settings = new SettingsWidget(imodel_, this);  // NOLINT
    auto *dock = new QDockWidget("Настройки", this);     // NOLINT
    dock->setWidget(settings);

    auto *chart = new QChart();          // NOLINT
    view_ = new ChartView(chart, this);  // NOLINT

    addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, dock);
    setCentralWidget(view_);
}

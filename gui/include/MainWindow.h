#pragma once
#include <IModel.h>

#include <QDockWidget>
#include <QMainWindow>
#include <QTimer>

#include "ChartView.h"
#include "SettingsWidget.h"

class MainWindow : public QMainWindow {
  public:
    explicit MainWindow(IModel* imodel_);

  private:
    IModel* imodel_;
    ChartView* view_;
};

#pragma once
#include <IModel.h>

#include <QDockWidget>
#include <QMainWindow>
#include <QTimer>

#include "ChartView.h"
#include "GuiModel.h"
#include "SettingsWidget.h"

class MainWindow : public QMainWindow {
  public:
    explicit MainWindow(GuiModel* imodel_);

  private:
    GuiModel* imodel_;
    ChartView* view_;
};

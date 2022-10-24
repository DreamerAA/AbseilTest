#pragma once
#include <GuiModel.h>

#include <QListView>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QWidget>

#include "WidgetUtils.h"
class SettingsWidget : public QWidget {
    Q_OBJECT
  public:
    explicit SettingsWidget(GuiModel *gui_model, QWidget *parent);

  private:
    GuiModel *gui_model_;
    QListView *list_view_;
    QStandardItemModel *list_model_;
    QHash<QUuid, QStandardItem *> items_;
};

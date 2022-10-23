#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H
#include <IModel.h>
#include <NetworkLayerStorage.h>
#include <UpdateCoinsLayer.h>

#include <QListView>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QWidget>

#include "WidgetUtils.h"
class SettingsWidget : public QWidget {
    Q_OBJECT
  public:
    explicit SettingsWidget(IModel *imodel, QWidget *parent);

  private:
    IModel *imodel_;
    QListView *list_view_;
    QStandardItemModel *list_model_;
    QHash<QUuid, QStandardItem *> items_;
    QVector<QSharedPointer<INetworkLayer>> layers_;
};

#endif  // SETTINGSWIDGET_H

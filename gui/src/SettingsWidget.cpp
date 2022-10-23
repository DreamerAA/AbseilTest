#include "SettingsWidget.h"

SettingsWidget::SettingsWidget(IModel *imodel, QWidget *parent)
    : QWidget(parent), imodel_(imodel) {
    list_model_ = new QStandardItemModel(this);
    list_view_ = new QListView(this);
    list_view_->setModel(list_model_);

    auto *pb_update = WidgetUtils::createPushButton("update", "");
    connect(pb_update, &QPushButton::clicked, this, [this]() {
        auto layer = new UpdateCoinsLayer(imodel_);
        layer->sendRequest();
        NetworkLayerStorage::instance().addLayer(layer);
    });

    auto *title = WidgetUtils::createLabel("Available exchange rates", "title");
    auto *layout_main = WidgetUtils::createLayout<QVBoxLayout>(this);
    layout_main->addWidget(title);
    layout_main->addWidget(list_view_);
    layout_main->addWidget(pb_update);

    connect(imodel, &IModel::newCurrency, this, [this](QUuid id) {
        const auto &cur = imodel_->currency(id);
        auto *item = new QStandardItem(cur->name_);
        items_.insert(id, item);

        auto cr = list_model_->rowCount();
        list_model_->setRowCount(cr + 1);
        list_model_->setItem(cr, item);
    });
    connect(imodel, &IModel::currencyChanged, this, [this](QUuid id) {
        const auto &cur = imodel_->currency(id);
        auto item = items_[id];
        item->setData(cur->icon_, Qt::DecorationRole);
        item->setData(cur->name_, Qt::DisplayRole);
    });
}

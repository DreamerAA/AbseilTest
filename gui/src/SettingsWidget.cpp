#include "SettingsWidget.h"

SettingsWidget::SettingsWidget(GuiModel *gui_model, QWidget *parent)
    : QWidget(parent), gui_model_(gui_model) {
    list_model_ = new QStandardItemModel(this);
    list_view_ = new QListView(this);
    list_view_->setModel(list_model_);

    auto imodel = gui_model_->imodel();

    auto *pb_update = WidgetUtils::createPushButton("update", "");
    connect(pb_update, &QPushButton::clicked, imodel, &IModel::needUpdate);

    auto *title = WidgetUtils::createLabel("Available exchange rates", "title");
    auto *layout_main = WidgetUtils::createLayout<QVBoxLayout>(this);
    layout_main->addWidget(title);
    layout_main->addWidget(list_view_);
    layout_main->addWidget(pb_update);
    connect(imodel, &IModel::newCurrency, this, [this](QUuid id) {
        auto imodel = gui_model_->imodel();
        const auto &cur = imodel->currency(id);
        auto *item = new QStandardItem(cur->name_);
        items_.insert(id, item);
        item->setCheckable(true);
        item->setCheckState(Qt::Unchecked);

        auto cr = list_model_->rowCount();
        list_model_->setRowCount(cr + 1);
        list_model_->setItem(cr, item);
    });

    connect(list_model_, &QStandardItemModel::itemChanged, this,
            [this](QStandardItem *item) {
                auto id = items_.key(item);
                gui_model_->setActive(id, item->checkState() == Qt::Checked);
            });

    connect(gui_model_, &GuiModel::iconChanged, this, [this](QUuid id) {
        const auto &data = gui_model_->guiData(id);
        auto item = items_[id];
        item->setData(data->icon_, Qt::DecorationRole);
    });
}

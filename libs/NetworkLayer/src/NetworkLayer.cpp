#include "NetworkLayer.h"

NetworkLayer &NetworkLayer::instance() {
    static NetworkLayer layer;
    return layer;
}

void NetworkLayer::setGuiModel(GuiModel *gui_model) {
    gui_model_ = gui_model;
    auto imodel = gui_model->imodel();
    connect(imodel, &IModel::newCurrency, this, [this](auto id) {
        auto imodel = gui_model_->imodel();
        const auto &currency = imodel->currency(id);
        IconLoadWorker::IconDTO dto{id,
                                    currency->meta_info_["iconUrl"].toString()};
        auto icon_loader = new IconLoadWorker(dto, gui_model_);
        icon_loader->sendRequest();
        NetworkWorkerStorage::instance().addWorker(icon_loader);
    });
    connect(imodel, &IModel::needUpdateSignal, this, [this]() {
        auto worker = new UpdateCoinsWorker(gui_model_->imodel());
        worker->sendRequest();
        NetworkWorkerStorage::instance().addWorker(worker);
    });
}

NetworkLayer::NetworkLayer(QObject *parent) : QObject(parent) {}

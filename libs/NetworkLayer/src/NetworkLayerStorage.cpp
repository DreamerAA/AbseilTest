#include "NetworkLayerStorage.h"

NetworkLayerStorage &NetworkLayerStorage::instance() {
    static NetworkLayerStorage storage;
    return storage;
}

void NetworkLayerStorage::addLayer(INetworkLayer *layer) {
    layer->setParent(this);
    layers_.insert(layer->id(), layer);
    connect(layer, &INetworkLayer::requestCompleted, this,
            &NetworkLayerStorage::removeLayerSlot);
}

NetworkLayerStorage::NetworkLayerStorage(QObject *parent) : QObject(parent) {}

void NetworkLayerStorage::removeLayerSlot() {
    auto layer = qobject_cast<INetworkLayer *>(sender());
    layers_.remove(layer->id());
    layer->deleteLater();
}

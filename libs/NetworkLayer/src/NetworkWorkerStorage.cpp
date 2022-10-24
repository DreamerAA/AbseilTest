#include "NetworkWorkerStorage.h"

NetworkWorkerStorage &NetworkWorkerStorage::instance() {
    static NetworkWorkerStorage storage;
    return storage;
}

void NetworkWorkerStorage::addWorker(INetworkWorker *worker) {
    worker->setParent(this);
    workers_.insert(worker->id(), worker);
    connect(worker, &INetworkWorker::requestCompleted, this,
            &NetworkWorkerStorage::removeWorkerSlot);
}

NetworkWorkerStorage::NetworkWorkerStorage(QObject *parent) : QObject(parent) {}

void NetworkWorkerStorage::removeWorkerSlot() {
    auto worker = qobject_cast<INetworkWorker *>(sender());
    workers_.remove(worker->id());
    worker->deleteLater();
}

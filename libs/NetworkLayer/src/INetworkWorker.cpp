#include "INetworkWorker.h"

INetworkWorker::INetworkWorker()
    : QObject(),
      id_(QUuid::createUuid()),
      manager_(new QNetworkAccessManager(this)) {
    connect(manager_, &QNetworkAccessManager::finished, this,
            &INetworkWorker::responseSlot);
}

void INetworkWorker::sendRequest() {
    auto request = createRequest();
    manager_->get(request);
}

QUuid INetworkWorker::id() const { return id_; }

void INetworkWorker::responseSlot(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << " --- Error:" << reply->errorString();
    } else {
        acceptResponse(reply);
    }
    emit requestCompleted();
}

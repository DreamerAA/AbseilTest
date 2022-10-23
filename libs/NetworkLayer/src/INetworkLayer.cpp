#include "INetworkLayer.h"

INetworkLayer::INetworkLayer(IModel *imodel)
    : QObject(),
      id_(QUuid::createUuid()),
      manager_(new QNetworkAccessManager(this)),
      imodel_(imodel) {
    connect(manager_, &QNetworkAccessManager::finished, this,
            &INetworkLayer::responseSlot);
}

void INetworkLayer::sendRequest() {
    auto request = createRequest();
    manager_->get(request);
}

IModel *INetworkLayer::model() { return imodel_; }

QUuid INetworkLayer::id() const { return id_; }

void INetworkLayer::responseSlot(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << " --- Error:" << reply->errorString();
    } else {
        acceptResponse(reply);
    }
    emit requestCompleted();
}

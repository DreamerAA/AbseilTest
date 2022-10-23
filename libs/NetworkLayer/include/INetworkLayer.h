#pragma once

#include <IModel.h>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>

class INetworkLayer : public QObject {
    Q_OBJECT
  public:
    explicit INetworkLayer(IModel *imodel);
    virtual QNetworkRequest createRequest() = 0;
    virtual void acceptResponse(QNetworkReply *reply) = 0;
    void sendRequest();
    IModel *model();
    [[nodiscard]] QUuid id() const;
  signals:
    void requestCompleted();

  private:
    QUuid id_;
    QNetworkAccessManager *manager_;
    IModel *imodel_;
  public slots:
    void responseSlot(QNetworkReply *reply);
};

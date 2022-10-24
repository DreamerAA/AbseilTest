#pragma once

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>

class INetworkWorker : public QObject {
    Q_OBJECT
  public:
    explicit INetworkWorker();
    virtual QNetworkRequest createRequest() = 0;
    virtual void acceptResponse(QNetworkReply *reply) = 0;
    void sendRequest();
    [[nodiscard]] QUuid id() const;
  signals:
    void requestCompleted();

  private:
    QUuid id_;
    QNetworkAccessManager *manager_;
  public slots:
    void responseSlot(QNetworkReply *reply);
};

#pragma once

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>

class NetworkLayer : public QObject {
    Q_OBJECT
  public:
    struct State {};

    explicit NetworkLayer(QObject *obj)
        : manager_(new QNetworkAccessManager()) {
        QObject::connect(manager_, &QNetworkAccessManager::finished, this,
                         [](QNetworkReply *reply) {
                             if (reply->error()) {
                                 qDebug() << reply->errorString();
                                 return;
                             }

                             QString answer = reply->readAll();

                             qDebug() << answer;
                         });
    }
    void updateState() {}

  private:
    QNetworkAccessManager *manager_;
};

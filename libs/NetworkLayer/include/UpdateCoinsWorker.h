#pragma once

#include <IModel.h>
#include <INetworkWorker.h>

class UpdateCoinsWorker : public INetworkWorker {
    Q_OBJECT
  public:
    explicit UpdateCoinsWorker(IModel *imodel_);
    QNetworkRequest createRequest() override;
    void acceptResponse(QNetworkReply *reply) override;

  private:
    IModel *imodel_;
};

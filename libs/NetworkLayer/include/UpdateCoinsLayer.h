#pragma once

#include <INetworkLayer.h>
#include <IconLoadLayer.h>
#include <NetworkLayerStorage.h>
class UpdateCoinsLayer : public INetworkLayer {
    Q_OBJECT
  public:
    explicit UpdateCoinsLayer(IModel *imodel_);
    QNetworkRequest createRequest() override;
    void acceptResponse(QNetworkReply *reply) override;
};

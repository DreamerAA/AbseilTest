#pragma once

#include "INetworkLayer.h"
class IconLoadLayer : public INetworkLayer {
    Q_OBJECT
  public:
    struct IconDTO {
        QUuid currency_id_;
        QString path_to_icon_;
        QIcon icon_;
    };
    explicit IconLoadLayer(IconDTO dto, IModel *imodel_);
    QNetworkRequest createRequest() override;
    void acceptResponse(QNetworkReply *reply) override;

  private:
    IconDTO dto_;
};

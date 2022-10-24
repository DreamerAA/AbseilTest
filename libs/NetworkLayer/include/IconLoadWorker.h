#pragma once

#include <GuiModel.h>

#include "INetworkWorker.h"

class IconLoadWorker : public INetworkWorker {
    Q_OBJECT
  public:
    struct IconDTO {
        QUuid currency_id_;
        QString path_to_icon_;
    };
    explicit IconLoadWorker(IconDTO dto, GuiModel *gui_model);
    QNetworkRequest createRequest() override;
    void acceptResponse(QNetworkReply *reply) override;

  private:
    GuiModel *gui_model_;
    IconDTO dto_;
};

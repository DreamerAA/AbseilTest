#include "IconLoadLayer.h"

IconLoadLayer::IconLoadLayer(IconDTO dto, IModel *imodel_)
    : INetworkLayer(imodel_), dto_(dto) {}

QNetworkRequest IconLoadLayer::createRequest() {
    return QNetworkRequest(dto_.path_to_icon_);
}

void IconLoadLayer::acceptResponse(QNetworkReply *reply) {
    auto img = QImage();
    img.loadFromData(reply->readAll());
    dto_.icon_ = QIcon(QPixmap::fromImage(img));
    model()->updateCurrency(dto_.currency_id_, [this](auto &currency) {
        currency->icon_ = dto_.icon_;
    });
}

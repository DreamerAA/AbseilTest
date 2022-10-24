#include "IconLoadWorker.h"

IconLoadWorker::IconLoadWorker(IconDTO dto, GuiModel *gui_model)
    : INetworkWorker(), gui_model_(gui_model), dto_(dto) {}

QNetworkRequest IconLoadWorker::createRequest() {
    return QNetworkRequest(dto_.path_to_icon_);
}

void IconLoadWorker::acceptResponse(QNetworkReply *reply) {
    auto img = QImage();
    img.loadFromData(reply->readAll());
    gui_model_->setIcon(dto_.currency_id_, QIcon(QPixmap::fromImage(img)));
}

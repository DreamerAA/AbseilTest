#include "UpdateCoinsWorker.h"

UpdateCoinsWorker::UpdateCoinsWorker(IModel *imodel)
    : INetworkWorker(), imodel_(imodel) {}

QNetworkRequest UpdateCoinsWorker::createRequest() {
    auto url = QUrl(
        "https://coinranking1.p.rapidapi.com/"
        "coins?referenceCurrencyUuid=yhjMzLPhuIDl&timePeriod=24h&tiers%5B0%5D="
        "1&orderBy=marketCap&orderDirection=desc&limit=50&offset=0");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "some/type");
    request.setRawHeader("X-RapidAPI-Key",
                         "1ad681d661mshf8847c7a2683e97p1dd7c5jsn3d76090790d7");
    request.setRawHeader("X-RapidAPI-Host", "coinranking1.p.rapidapi.com");
    return request;
}

void UpdateCoinsWorker::acceptResponse(QNetworkReply *reply) {
    auto doc = QJsonDocument::fromJson(reply->readAll());
    auto jobj = doc.object();
    auto jdata = jobj["data"].toObject();
    auto jarray = jdata["coins"].toArray();
    for (const auto &jel : jarray) {
        auto jcoin = jel.toObject();
        auto cur_id = QUuid::createUuid();
        imodel_->addCurrency(
            Currency{.id_ = cur_id,
                     .name_ = jcoin["name"].toString(),
                     .key_ = jcoin["uuid"].toString(),
                     .meta_info_ = jcoin.toVariantMap(),
                     .price_ = jcoin["price"].toString().toDouble()});
    }
}

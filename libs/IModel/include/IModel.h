#pragma once

#include <QHash>
#include <QIcon>
#include <QObject>
#include <QUuid>
#include <QVariantMap>
//#include <absl/conteiner/flat_hash_map.h>

/// @todo rewrite Qt structs to abseil containers
struct Currency {
    QUuid id_;
    QString name_;
    QString key_;
    QIcon icon_;
    QVariantMap meta_info_;
    double price_{0.};
};

class IModel : public QObject {
    Q_OBJECT
  public:
    explicit IModel(QObject *parent = nullptr) : QObject(parent) {}

    [[nodiscard]] QString nameCurrency(QUuid id) const {
        return currencies_[id]->name_;
    }

    [[nodiscard]] QIcon iconCurrency(QUuid id) const {
        return currencies_[id]->icon_;
    }

    [[nodiscard]] QStringList currencyNames() const {
        QStringList lstr;
        for (const auto &cur : currencies_) {
            lstr << cur->name_;
        }
        return lstr;
    }

    [[nodiscard]] QSharedPointer<Currency> currency(QUuid id) const {
        return currencies_[id];
    }

    void addCurrency(const Currency &cur) {
        currencies_.insert(cur.id_, QSharedPointer<Currency>::create(cur));
        emit newCurrency(cur.id_);
    }
    template <typename UpdateFunction>
    void updateCurrency(QUuid id, UpdateFunction function) {
        function(currencies_[id]);
        emit currencyChanged(id);
    }
  signals:
    void currencyChanged(QUuid);
    void newCurrency(QUuid);

  private:
    QHash<QUuid, QSharedPointer<Currency>> currencies_;
};

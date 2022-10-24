#ifndef GUIMODEL_H
#define GUIMODEL_H

#include "IModel.h"

class GuiModel : public QObject {
    Q_OBJECT
  private:
    struct GuiCurrencyData {
        GuiCurrencyData(QUuid id) : id_(id) {}
        QUuid id_;
        QIcon icon_;
        bool active_{false};
    };

  public:
    explicit GuiModel(IModel *imodel, QObject *parent = nullptr)
        : QObject(parent), imodel_(imodel) {
        connect(imodel_, &IModel::newCurrency, this, [this](auto id) {
            const auto &currency = imodel_->currency(id);
            auto data = QSharedPointer<GuiCurrencyData>::create(id);
            gui_data_.insert(id, data);
        });
    }
    IModel *imodel() { return imodel_; }
    [[nodiscard]] QSharedPointer<GuiCurrencyData> guiData(QUuid id) const {
        return gui_data_[id];
    }
    void setIcon(QUuid id, const QIcon &icon) {
        gui_data_[id]->icon_ = icon;
        Q_EMIT iconChanged(id);
    }
    void setActive(QUuid id, bool active) {
        gui_data_[id]->active_ = active;
        Q_EMIT activeChanged(id);
    }
  Q_SIGNALS:
    void iconChanged(QUuid);
    void activeChanged(QUuid);

  private:
    IModel *imodel_;
    QHash<QUuid, QSharedPointer<GuiCurrencyData>> gui_data_;
};

#endif  // GUIMODEL_H

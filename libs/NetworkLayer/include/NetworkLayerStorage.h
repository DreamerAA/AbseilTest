#ifndef NETWORKLAYERSTORAGE_H
#define NETWORKLAYERSTORAGE_H

#include "INetworkLayer.h"

class NetworkLayerStorage : public QObject {
    Q_OBJECT
  public:
    static NetworkLayerStorage& instance();
    void addLayer(INetworkLayer* layer);

  private:
    explicit NetworkLayerStorage(QObject* parent = nullptr);
    QHash<QUuid, INetworkLayer*> layers_;

  public slots:
    void removeLayerSlot();
};

#endif  // NETWORKLAYERSTORAGE_H

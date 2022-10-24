#pragma once

#include "INetworkWorker.h"

class NetworkWorkerStorage : public QObject {
    Q_OBJECT
  public:
    static NetworkWorkerStorage& instance();
    void addWorker(INetworkWorker* worker);

  private:
    explicit NetworkWorkerStorage(QObject* parent = nullptr);
    QHash<QUuid, INetworkWorker*> workers_;

  public slots:
    void removeWorkerSlot();
};

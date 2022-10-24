#pragma once

#include <GuiModel.h>
#include <IconLoadWorker.h>
#include <NetworkWorkerStorage.h>
#include <UpdateCoinsWorker.h>

#include <QObject>

class NetworkLayer : public QObject {
    Q_OBJECT
  public:
    static NetworkLayer &instance();
    void setGuiModel(GuiModel *gui_model);

  private:
    explicit NetworkLayer(QObject *parent = nullptr);

    GuiModel *gui_model_;
};

#pragma once
#include <IModel.h>

class Model : public IModel {
    Q_OBJECT
  public:
    explicit Model(QObject* parent = nullptr) : IModel(parent) {}
};

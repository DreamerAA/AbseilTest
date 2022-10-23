#ifndef WIDGETUTILS_H
#define WIDGETUTILS_H

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
class WidgetUtils {
  public:
    static QLabel* createLabel(const QString& text, const QString& type,
                               QWidget* parent = nullptr) {
        auto* lbl = new QLabel(text, parent);  // NOLINT
        lbl->setProperty("type", type);
        return lbl;
    }

    static QPushButton* createPushButton(const QString& text,
                                         const QString& type,
                                         const QPixmap& pix = QPixmap(),
                                         QWidget* parent = nullptr) {
        auto* pb = new QPushButton(QIcon(pix), text, parent);  // NOLINT
        pb->setProperty("type", type);
        return pb;
    }

    template <typename T>
    static T* createLayout(QWidget* wid) {
        auto* layout = new T(wid);  // NOLINT
        layout->setContentsMargins(0, 0, 0, 0);
        return layout;
    }
};

#endif  // WIDGETUTILS_H

#include <MainWindow.h>
#include <Model.h>

#include <QApplication>
#include <QtWidgets/QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Model model;
    MainWindow mw(&model);
    mw.showMaximized();
    return app.exec();
}

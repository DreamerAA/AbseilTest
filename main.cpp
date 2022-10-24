#include <MainWindow.h>
#include <Model.h>
#include <NetworkLayer.h>

#include <QApplication>
#include <QtWidgets/QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Model model;
    GuiModel gui_model(&model);
    NetworkLayer::instance().setGuiModel(&gui_model);

    MainWindow mw(&gui_model);
    mw.showMaximized();
    return app.exec();
}

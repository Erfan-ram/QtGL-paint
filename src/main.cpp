#include <QApplication>
#include "painter.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    QMainWindow paintWindow;
    Painter_app ui;
    ui.setupUi(&paintWindow);

    paintWindow.show();

    return app.exec();
}

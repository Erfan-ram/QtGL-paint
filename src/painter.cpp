#include "painter.hpp"
#include <QButtonGroup>

MaZe_Painter::MaZe_Painter() {
}

void MaZe_Painter::setupUi(QMainWindow *paint_window) {
    if (paint_window->objectName().isEmpty())
        paint_window->setObjectName(QString::fromUtf8("paint_window"));
    paint_window->setFixedSize(780, 500);

    QPalette palette;
    QBrush brush(QColor(255, 255, 255, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    QBrush brush1(QColor(36, 31, 49, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Button, brush1);
    QBrush brush2(QColor(54, 46, 73, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Light, brush2);
    QBrush brush3(QColor(45, 38, 61, 255));
    brush3.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
    QBrush brush4(QColor(18, 15, 24, 255));
    brush4.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
    QBrush brush5(QColor(24, 21, 33, 255));
    brush5.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
    palette.setBrush(QPalette::Active, QPalette::Text, brush);
    palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
    palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    QBrush brush6(QColor(0, 0, 0, 255));
    brush6.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Base, brush6);
    palette.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
    palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
    QBrush brush7(QColor(255, 255, 220, 255));
    brush7.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
    palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
    QBrush brush8(QColor(255, 255, 255, 128));
    brush8.setStyle(Qt::SolidPattern);
    paint_window->setPalette(palette);
    paint_window->setStyleSheet(QString::fromUtf8(""));

    centralwidget = new QWidget(paint_window);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));

    shapes_group = new QGroupBox(centralwidget);
    shapes_group->setObjectName(QString::fromUtf8("shapes_group"));
    shapes_group->setGeometry(QRect(10, 10, 101, 153));

    point_button = new QPushButton(shapes_group);
    point_button->setObjectName(QString::fromUtf8("point_button"));
    point_button->setGeometry(QRect(10, 30, 81, 27));
    point_button->setCheckable(true);

    line_button = new QPushButton(shapes_group);
    line_button->setObjectName(QString::fromUtf8("line_button"));
    line_button->setGeometry(QRect(10, 60, 81, 27));
    line_button->setCheckable(true);

    circle_button = new QPushButton(shapes_group);
    circle_button->setObjectName(QString::fromUtf8("circle_button"));
    circle_button->setGeometry(QRect(10, 90, 81, 27));
    circle_button->setCheckable(true);

    rectangle_button = new QPushButton(shapes_group);
    rectangle_button->setObjectName(QString::fromUtf8("rectangle_button"));
    rectangle_button->setGeometry(QRect(10, 120, 81, 27));
    rectangle_button->setCheckable(true);

    tools_group = new QGroupBox(centralwidget);
    tools_group->setObjectName(QString::fromUtf8("tools_group"));
    tools_group->setGeometry(QRect(10, 170, 101, 141));

    eraser_button = new QPushButton(tools_group);
    eraser_button->setObjectName(QString::fromUtf8("eraser_button"));
    eraser_button->setGeometry(QRect(10, 30, 81, 27));
    eraser_button->setCheckable(true);

    clear_all = new QPushButton(tools_group);
    clear_all->setObjectName(QString::fromUtf8("clear_all"));
    clear_all->setGeometry(QRect(10, 60, 81, 27));
    clear_all->setCheckable(true);


    color_group = new QGroupBox(centralwidget);
    color_group->setObjectName(QString::fromUtf8("color_group"));
    color_group->setGeometry(QRect(10, 320, 101, 132));

    color_red_button = new QPushButton(color_group);
    color_red_button->setObjectName(QString::fromUtf8("color_red_button"));
    color_red_button->setGeometry(QRect(10, 30, 41, 27));
    color_red_button->setStyleSheet("background-color: rgb(255, 0, 0);");
    color_red_button->setCheckable(true);

    color_blue_button = new QPushButton(color_group);
    color_blue_button->setObjectName(QString::fromUtf8("color_blue_button"));
    color_blue_button->setGeometry(QRect(53, 30, 41, 27));
    color_blue_button->setStyleSheet("background-color: rgb(0, 0, 255);");
    color_blue_button->setCheckable(true);

    color_green_button = new QPushButton(color_group);
    color_green_button->setObjectName(QString::fromUtf8("color_blue_button"));
    color_green_button->setGeometry(QRect(10, 60, 41, 27));
    color_green_button->setStyleSheet("background-color: rgb(0, 255, 0);");
    color_green_button->setCheckable(true);

    color_yellow_button = new QPushButton(color_group);
    color_yellow_button->setObjectName(QString::fromUtf8("color_blue_button"));
    color_yellow_button->setGeometry(QRect(53, 60, 41, 27));
    color_yellow_button->setStyleSheet("background-color: rgb(255, 255, 0);");
    color_yellow_button->setCheckable(true);

    color_purple_button = new QPushButton(color_group);
    color_purple_button->setObjectName(QString::fromUtf8("color_purple_button"));
    color_purple_button->setGeometry(QRect(10, 90, 41, 27));
    color_purple_button->setStyleSheet("background-color: rgb(128, 0, 128);");
    color_purple_button->setCheckable(true);

    color_black_button = new QPushButton(color_group);
    color_black_button->setObjectName(QString::fromUtf8("color_black_button"));
    color_black_button->setGeometry(QRect(53, 90, 41, 27));
    color_black_button->setStyleSheet("background-color: black;");
    color_black_button->setCheckable(true);



    sheet = new GLWidget(centralwidget);
    sheet->setObjectName(QString::fromUtf8("sheet"));
    sheet->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
    sheet->setGeometry(QRect(120, 0, 640, 480));

    paint_window->setCentralWidget(centralwidget);

    menubar = new QMenuBar(paint_window);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 1280, 24));

    menuFiles = new QMenu(menubar);
    menuFiles->setObjectName(QString::fromUtf8("menuFiles"));

    QPalette palette1;
    menuFiles->setPalette(palette1);

    menuView = new QMenu(menubar);
    menuView->setObjectName(QString::fromUtf8("menuView"));

    paint_window->setMenuBar(menubar);

    statusbar = new QStatusBar(paint_window);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    
    paint_window->setStatusBar(statusbar);

    menubar->addAction(menuFiles->menuAction());
    menubar->addAction(menuView->menuAction());

    retranslateUi(paint_window);

    QMetaObject::connectSlotsByName(paint_window);

    QButtonGroup* button_group = new QButtonGroup(this);
    button_group->setExclusive(true);
    button_group->addButton(point_button);
    button_group->addButton(line_button);
    button_group->addButton(circle_button);
    button_group->addButton(rectangle_button);
    button_group->addButton(eraser_button);
    button_group->addButton(clear_all);
    connect(button_group, QOverload<QAbstractButton*>::of(&QButtonGroup::buttonClicked),
            this, &MaZe_Painter::handleButtons);
            
    QButtonGroup* button_group2 = new QButtonGroup(this);
    button_group2->setExclusive(true);
    button_group2->addButton(color_purple_button);
    button_group2->addButton(color_red_button);
    button_group2->addButton(color_blue_button);
    button_group2->addButton(color_green_button);
    button_group2->addButton(color_black_button);
    button_group2->addButton(color_yellow_button);
    connect(button_group2, QOverload<QAbstractButton*>::of(&QButtonGroup::buttonClicked),
            this, &MaZe_Painter::handleColors);
}

void MaZe_Painter::retranslateUi(QMainWindow *paint_window) {
    paint_window->setWindowTitle(QCoreApplication::translate("paint_window", "MaZe Painter", nullptr));
    shapes_group->setTitle(QCoreApplication::translate("paint_window", "        Shapes", nullptr));
    color_group->setTitle(QCoreApplication::translate("paint_window", "     Color Box", nullptr));
    point_button->setText(QCoreApplication::translate("paint_window", "Point", nullptr));
    line_button->setText(QCoreApplication::translate("paint_window", "Line", nullptr));
    circle_button->setText(QCoreApplication::translate("paint_window", "Circle", nullptr));
    rectangle_button->setText(QCoreApplication::translate("paint_window", "Rectangle", nullptr));
    tools_group->setTitle(QCoreApplication::translate("paint_window", "         Tools ", nullptr));
    eraser_button->setText(QCoreApplication::translate("paint_window", "Eraser", nullptr));
    clear_all->setText(QCoreApplication::translate("paint_window", "Clear All", nullptr));
    menuFiles->setTitle(QCoreApplication::translate("paint_window", "Files", nullptr));
    menuView->setTitle(QCoreApplication::translate("paint_window", "View", nullptr));
}

void MaZe_Painter::handleButtons(QAbstractButton* init) {
    if (init == point_button){
        sheet->setPaintFlag("point");
    }
    else if (init == line_button){
        sheet->setPaintFlag("line");
    }
    else if (init == circle_button){
        sheet->setPaintFlag("circle");
    }
    else if (init == rectangle_button){
        sheet->setPaintFlag("rectangle");      
    }
    else if (init == eraser_button){
        sheet->setPaintFlag("erase");
    }
    else if (init == clear_all){
        sheet->setPaintFlag("clear");
    }
}

void MaZe_Painter::handleColors(QAbstractButton* init) {
    if (init == color_purple_button){
        sheet->setColor(128, 0, 128);
    }
    else if (init == color_black_button){
        sheet->setColor(0, 0, 0);
    }
    else if (init == color_red_button){
        sheet->setColor(255, 0, 0);
    }
    else if (init == color_blue_button){
        sheet->setColor(0, 0, 255);     
    }
    else if (init == color_yellow_button){
        sheet->setColor(255, 255, 0);
    }
    else if (init == color_green_button){
        sheet->setColor(0, 255, 0);
    }
}
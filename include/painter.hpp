#ifndef PAINTER_HPP
#define PAINTER_HPP

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <QMouseEvent>
#include <QButtonGroup>
#include <iostream>
#include "opengl.hpp"

class MaZe_Painter : public QObject {
    Q_OBJECT
    private :
        QWidget *centralwidget;
        QGroupBox *shapes_group;
        QPushButton *point_button;
        QPushButton *line_button;
        QPushButton *circle_button;
        QPushButton *rectangle_button;
        QPushButton *color_red_button;
        QPushButton *color_blue_button;
        QPushButton *color_green_button;
        QPushButton *color_yellow_button;
        QPushButton *color_purple_button;
        QPushButton *color_black_button;
        QGroupBox *tools_group;
        QGroupBox *color_group;
        QPushButton *eraser_button;
        QPushButton *clear_all;
        QMenuBar *menubar;
        QMenu *menuFiles;
        QMenu *menuView;
        QStatusBar *statusbar;
        GLWidget* sheet;

    public :
        MaZe_Painter();
        void updateSheet();
        void setupUi(QMainWindow *);
        void retranslateUi(QMainWindow *);
        void handleButtons(QAbstractButton*);
        void handleColors(QAbstractButton*);
};

#endif // PAINTER_HPP
#ifndef OPENGL_HPP
#define OPENGL_HPP

#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <iostream>
#include <vector>
#include <cmath>

struct Shape {
    std::string type;
    std::vector<QPoint> points;
    QColor color;
};

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT
    public:
        GLWidget(QWidget *parent = nullptr) : QOpenGLWidget(parent) {}
        void setPaintFlag(std::string);
        void setColor(float, float, float);

    protected:
        void initializeGL();

        void paintGL();

        void resizeGL(int width, int height);

        void mousePressEvent(QMouseEvent *event);

        void mouseMoveEvent(QMouseEvent *event);

        void mouseReleaseEvent(QMouseEvent *event);

    private:
        std::vector<Shape> shapes;
        std::string paintFlag = "None";
        std::vector<QPoint> currentPoint;
        QColor currentColor = QColor(0, 0, 0);
    
    bool isPointInsideCircle(const QPoint& point, const Shape& shape);
    bool isPointInsideRectangle(const QPoint& point, const Shape& shape);
};

#endif // OPENGL_HPP

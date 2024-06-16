#include "opengl.hpp"
#include <vector>
#include <string>
#include <cmath>

void GLWidget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void GLWidget::setPaintFlag(std::string flag) {
    if (flag == "clear") {
        shapes.clear();
        paintFlag = "None";
        update();
    } else if (flag == "erase") {
        paintFlag = "erase";
    } else {
        paintFlag = flag;
    }
}

void GLWidget::setColor(float r, float g, float b) {
    currentColor = QColor::fromRgbF(r, g, b);
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (const auto& shape : shapes) {
        glColor3f(shape.color.redF(), shape.color.greenF(), shape.color.blueF());
        if (shape.type == "line") {
            glBegin(GL_LINES);
            glVertex3f(shape.points[0].x(), shape.points[0].y(), 0.0);
            glVertex3f(shape.points[1].x(), shape.points[1].y(), 0.0);
            glEnd();
        } else if (shape.type == "rectangle") {
            glBegin(GL_QUADS);
            glVertex3f(shape.points[0].x(), shape.points[0].y(), 0.0);
            glVertex3f(shape.points[1].x(), shape.points[0].y(), 0.0);
            glVertex3f(shape.points[1].x(), shape.points[1].y(), 0.0);
            glVertex3f(shape.points[0].x(), shape.points[1].y(), 0.0);
            glEnd();
        } else if (shape.type == "circle") {
            float radius = std::hypot(shape.points[1].x() - shape.points[0].x(), shape.points[1].y() - shape.points[0].y());
            glBegin(GL_TRIANGLE_FAN);
            glVertex3f(shape.points[0].x(), shape.points[0].y(), 0.0);
            for (int i = 0; i <= 100; ++i) {
                float angle = 2.0f * M_PI * i / 100;
                glVertex3f(shape.points[0].x() + cos(angle) * radius, shape.points[0].y() + sin(angle) * radius, 0.0);
            }
            glEnd();
        } else if (shape.type == "point") {
            glPointSize(5.0f);
            glBegin(GL_POINTS);
            glVertex3f(shape.points[0].x(), shape.points[0].y(), 0.0);
            glEnd();
        
        } else if (shape.type == "ershape") {
            glPointSize(10.0f);
            glBegin(GL_POINTS);
            glVertex3f(shape.points[0].x(), shape.points[0].y(), 0.0);
            glEnd();
        }
    }

    if (!currentPoint.empty()) {
        if (paintFlag == "line") {
            glBegin(GL_LINES);
            glVertex3f(currentPoint[0].x(), currentPoint[0].y(), 0.0);
            glVertex3f(currentPoint[1].x(), currentPoint[1].y(), 0.0);
            glEnd();
        } else if (paintFlag == "rectangle") {
            glBegin(GL_QUADS);
            glVertex3f(currentPoint[0].x(), currentPoint[0].y(), 0.0);
            glVertex3f(currentPoint[1].x(), currentPoint[0].y(), 0.0);
            glVertex3f(currentPoint[1].x(), currentPoint[1].y(), 0.0);
            glVertex3f(currentPoint[0].x(), currentPoint[1].y(), 0.0);
            glEnd();
        } else if (paintFlag == "circle") {
            float radius = std::hypot(currentPoint[1].x() - currentPoint[0].x(), currentPoint[1].y() - currentPoint[0].y());
            glBegin(GL_TRIANGLE_FAN);
            glVertex3f(currentPoint[0].x(), currentPoint[0].y(), 0.0);
            for (int i = 0; i <= 100; ++i) {
                float angle = 2.0f * M_PI * i / 100;
                glVertex3f(currentPoint[0].x() + cos(angle) * radius, currentPoint[0].y() + sin(angle) * radius, 0.0);
            }
            glEnd();
        } else if (paintFlag == "point") {
            glPointSize(5.0f);
            glBegin(GL_POINTS);
            glVertex3f(currentPoint[0].x(), currentPoint[0].y(), 0.0);
            glEnd();
        }
    }

    glFlush();
}

void GLWidget::resizeGL(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void GLWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && paintFlag != "None") {
        if (paintFlag == "erase") {
            QPoint clickPos = event->pos();
            Shape shape;
            shape.type = "ershape";
            shape.points.push_back(clickPos);
            shape.color = QColor(255, 255, 255);
            shapes.push_back(shape);
            update();
        } else {
            currentPoint.clear();
            currentPoint.push_back(event->pos());
            if (paintFlag == "point") {
                Shape shape;
                shape.type = "point";
                shape.points = currentPoint;
                shape.color = currentColor;
                shapes.push_back(shape);
                currentPoint.clear();
                update();
            } else {
                currentPoint.push_back(event->pos());
            }
        }
    }
}

void GLWidget::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton && paintFlag != "None" && paintFlag != "point" && paintFlag != "erase") {
        currentPoint[1] = event->pos();
        update();
    }
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && paintFlag != "None" && paintFlag != "point" && paintFlag != "erase") {
        Shape shape;
        shape.type = paintFlag;
        shape.points = currentPoint;
        shape.color = currentColor;
        shapes.push_back(shape);
        currentPoint.clear();
        update();
    }
}

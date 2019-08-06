#ifndef QTCANVAS_H
#define QTCANVAS_H

#include <QPainter>
#include <QTimer>
#include <QWidget>
#include "application.h"
class QtCanvas:public QWidget,public Canvas{

Q_OBJECT
    QPainter* m_painter{};
    QTimer timer;
    Application*m_app{};

    // Canvas interface
public:
    QtCanvas(Application*app);

    void setBackground(int r, int g, int b)
    {
        ThrowIfNotDrawing();
        m_painter->fillRect(0,0,QWidget::width(),QWidget::height(),QColor(r,g,b));
    }

protected:
    void paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        m_painter = &painter;

/*
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(rect(), Qt::AlignCenter, "Qt");
*/
        m_app->draw(this);


        m_painter = nullptr;
    }

    // Canvas interface
protected:
    bool isDrawing() const
    {
        return m_painter;
    }

    // Canvas interface
public:
    void drawLine(int x1, int y1, int x2, int y2)
    {
        ThrowIfNotDrawing();
        m_painter->drawLine(x1,y1,x2,y2);
    }

    void setPen(int r,int g, int b){
        ThrowIfNotDrawing();
        m_painter->setPen({r,g,b});
    }

    int width()const{return QWidget::width();}
    int height()const{return QWidget::height();}


    // Canvas interface
public:
    void setBrush(int r, int g, int b)
    {
        ThrowIfNotDrawing();
        m_painter->setBrush(QBrush{QColor{r,g,b}});
    }
    void fillRect(int x, int y, int w, int h)
    {
        m_painter->fillRect(x,y,w,h,m_painter->brush());
    }

    void noLoop()override{
        timer.stop();
    }
};

#endif // QTCANVAS_H

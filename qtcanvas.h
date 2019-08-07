#ifndef QTCANVAS_H
#define QTCANVAS_H

#include <QPainter>
#include <QTimer>
#include <QWidget>
#include "application.h"

///
/// \brief The QtCanvas classimplements canvas with Qt
/// QPainter for Canvas drawing primitives
/// QTimer to refresh canvas
///
class QtCanvas:public QWidget,public Canvas{

Q_OBJECT
    QPainter* m_painter{};
    QTimer timer;
    Application*m_app{};

    // Canvas interface
public:
    QtCanvas(Application*app);


    //QWidget interface
protected:
    void paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        m_painter = &painter;

        m_app->draw(this);

        m_painter = nullptr;
    }


    // Canvas interface
public:
    void setBackground(int r, int g, int b)override
    {
        ThrowIfNotDrawing();
        m_painter->fillRect(0,0,QWidget::width(),QWidget::height(),QColor(r,g,b));
    }

    void drawLine(int x1, int y1, int x2, int y2)override
    {
        ThrowIfNotDrawing();
        m_painter->drawLine(x1,y1,x2,y2);
    }

    void setPen(int r,int g, int b)override{
        ThrowIfNotDrawing();
        m_painter->setPen({r,g,b});
    }

    int width()const override{return QWidget::width();}
    int height()const override{return QWidget::height();}

    void setBrush(int r, int g, int b)override
    {
        ThrowIfNotDrawing();
        m_painter->setBrush(QBrush{QColor{r,g,b}});
    }
    void fillRect(int x, int y, int w, int h)override
    {
        m_painter->fillRect(x,y,w,h,m_painter->brush());
    }

    void noLoop()override{
        timer.stop();
    }

protected:
    bool isDrawing() const override
    {
        return m_painter;
    }
};

#endif // QTCANVAS_H

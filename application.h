#ifndef APPLICATION_H
#define APPLICATION_H

#include <stdexcept>


struct Canvas{
    virtual ~Canvas()=default;
   // virtual void save()=0;
   // virtual void restore() =0;
    virtual void setBackground(int r,int g, int b)=0;

    virtual void setPen(int r,int g, int b)=0;
    virtual void setBrush(int r,int g, int b)=0;


    virtual void drawLine(int x1, int y1, int x2, int y2)=0;
    virtual void fillRect(int x1, int y1, int w, int h)=0;


    virtual int width()const=0;
    virtual int height()const=0;

    virtual void noLoop()=0;


protected:
    virtual bool isDrawing()const=0;
    void ThrowIfNotDrawing(){
        if( ! isDrawing()){
            throw std::runtime_error("try to draw when not in draw state");
        }
    }
};

class Application{

public:
    virtual void setup(int& width,int& height,int& framerate){}

    virtual void draw(Canvas* canvas)=0;
};
#endif // APPLICATION_H

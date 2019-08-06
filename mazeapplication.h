#ifndef MAZEAPPLICATION_H
#define MAZEAPPLICATION_H

#include <application.h>
#include "maze_generator.h"



Point startPoint(const Cell &cell_p, int w, int h);
Point startPoint(const Wall& wall_p, int w,int h);
Point endPoint(const Wall& wall_p,int w,int h);


void draw(const Wall& wall_p, Canvas*canvas,int w,int h);
void draw(const Cell& cell_p,Canvas* canvas,int col_number,int row_number);


class MazeApplication:public Application
{
    const int row_number        = 100;
    const int column_number     = 100;
    bool generate_before_show   = false;
    const int speed_factor  = 100;

    MazeGenerator generator;
public:
    MazeApplication()
        :generator({row_number,column_number})
    {
        while(generate_before_show &&  ! generator.finished()){
            generator.step();
        }
    }

    virtual ~MazeApplication()=default;

protected:

    void draw(Canvas *canvas)override
    {

        for(auto it: range(speed_factor)){
            if(generator.finished()){
                canvas->noLoop();
            }else{

                generator.step();
            }
        }
        std::cout<<"draw\n";
        canvas->setBackground(0,0,0);

        generator.forEach([=](const Cell& cell){
            ::draw(cell,canvas,column_number,row_number);
        });

        if(generator.finished()){
            canvas->drawLine(0,0,canvas->width(),canvas->height());
        }

    }

    void setup(int &width, int &height,int& framerate)override
    {
        width = height = 600;
        framerate = 30;
    }
};

#endif // MAZEAPPLICATION_H

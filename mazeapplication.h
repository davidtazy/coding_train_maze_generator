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
    const int CELL_ROW_NUMBER = 10;
    const int CELL_COL_NUMBER = 10;
    MazeGenerator generator;
public:
    MazeApplication()
        :generator(CELL_ROW_NUMBER,CELL_COL_NUMBER){
    }

    virtual ~MazeApplication()=default;

protected:

    void draw(Canvas *canvas)override
    {
        if(generator.finished()){
            std::cout<<"Finished\n";
            canvas->noLoop();
        }else{

            generator.step();
        }
        std::cout<<"draw\n";
        canvas->setBackground(0,0,0);

        generator.forEach([=](const Cell& cell){
            ::draw(cell,canvas,CELL_COL_NUMBER,CELL_ROW_NUMBER);
        });

    }

    void setup(int &width, int &height,int& framerate)override
    {
        width = height = 600;
        framerate = 10;
    }
};

#endif // MAZEAPPLICATION_H

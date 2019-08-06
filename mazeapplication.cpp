#include "mazeapplication.h"

void draw(const Cell &cell_p, Canvas *canvas, int col_number, int row_number){
    int w = canvas->width()/ col_number ;
    int h = canvas->height() /row_number ;

    bool highlight = false;
    if(cell_p.visited()){
        highlight = true;
        canvas->setBrush(255,0,255);
    }
    if(cell_p.current()){
        highlight = true;
        canvas->setBrush(255,0,0);
    }

    if(highlight){
        Point p1 = ::startPoint(cell_p,w,h);
        canvas->fillRect(p1.x,p1.y,w,h);
    }

    cell_p.forEachWall([&](const Wall& wall_p, WallP pos_p){
        ::draw(wall_p,canvas,w,h);
    });

}



Point startPoint(const Wall &wall_p, int w, int h){


    if(wall_p.isTop() || wall_p.isLeft()){
        return{
            wall_p.col*w,
                    wall_p.row*h
        };

    }
    if(wall_p.isBottom() || wall_p.isRight()){
        return{
            wall_p.col*w +w,
                    wall_p.row*h +h};

    }

    throw std::runtime_error("startPoint - weird wall!!");
}

Point endPoint(const Wall &wall_p, int w, int h){
    if(wall_p.isTop() || wall_p.isRight()){
        return{
            wall_p.col*w+w,
                    wall_p.row*h};
    }

    if(wall_p.isBottom() || wall_p.isLeft()){
        return{
            wall_p.col*w ,
                    wall_p.row*h +h};

    }
    throw std::runtime_error("endPoint - weird wall!!");
}



Point startPoint(const Cell &cell_p, int w, int h){
    return{
        cell_p.col*w,
                cell_p.row*h
    };
}

void draw(const Wall &wall_p, Canvas *canvas, int w, int h){
    if(wall_p.invalid){
        throw std::runtime_error("wall is invalid - cannot draw it");
    }
    if(!wall_p.visible){
        return;
    }

    auto start = ::startPoint(wall_p,w,h);
    auto end = ::endPoint(wall_p,w,h);
    canvas->setPen(255,255,255);
    canvas->drawLine(start.x,start.y,end.x,end.y);
}

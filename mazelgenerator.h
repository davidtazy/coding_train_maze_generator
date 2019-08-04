#ifndef MAZELGENERATOR_H
#define MAZELGENERATOR_H
#include <array>
#include <vector>
#include <iostream>
#include <functional>
#include "application.h"

enum class WallP{Top=0,Left,Bottom,Right};

const int CELL_ROW_NUMBER = 10;
const int CELL_COL_NUMBER = 10;

struct Wall{
    int col,row;
    WallP pos;
    int id;
    bool invalid{true};
    bool visible{true};

    Wall()=default;
    Wall(int col,int row,WallP pos):col(col),row(row),pos(pos),invalid(false){
    }

    void setVisible(bool v){visible = v;}

    struct Point{
        int x,y;
    };

    Point startPoint(int w,int h){
        Point p;
        switch (pos) {
        case WallP::Top:
        case WallP::Left:
            return{
                col*w,
                row*h};
        case WallP::Bottom:
        case WallP::Right:
            return{
                col*w +w,
                row*h +h};
        }
    }

    Point endPoint(int w,int h)const{
        Point p;
        switch (pos) {
        case WallP::Top:
        case WallP::Right:
            return{
                col*w+w,
                row*h};
        case WallP::Left:
        case WallP::Bottom:
            return{
                col*w ,
                row*h +h};
        }
    }


    void draw(Canvas*canvas,int w,int h){
        if(invalid){
            throw std::runtime_error("wall is invalid - cannot draw it");
        }
        if(!visible){
            return;
        }

        auto start = startPoint(w,h);
        auto end = endPoint(w,h);
        canvas->setPen(255,255,255);
        canvas->drawLine(start.x,start.y,end.x,end.y);
    }

    bool isTop()const{return pos== WallP::Top;}
    bool isBottom()const{return pos== WallP::Bottom;}
    bool isLeft()const{return pos== WallP::Left;}
    bool isRight()const{return pos== WallP::Right;}
};


std::vector<int> range(int begin,int end=-1);

struct Cell{
    int col,row;
    bool visited{false};
    bool current{false};

    std::array<Wall,4> walls;

    Cell(int col_p,int row_p):col(col_p),row(row_p){
        for(int index:range(walls.size()) ){
            walls.at(index) = Wall(col,row,static_cast<WallP>(index));
        }
    }

    void setVisited(){
        visited = true;
    }
    void setCurrent(bool c){current = c;}

    void draw(Canvas* canvas){
        int w = canvas->width()/ CELL_COL_NUMBER ;
        int h = canvas->height() /CELL_ROW_NUMBER ;

        if(visited){
            canvas->setBrush(255,0,255);
        }
        if(current){
            canvas->setBrush(255,0,0);
        }

        if(visited || current){
            Wall::Point p1 = walls.at(static_cast<int>(WallP::Top)).startPoint(w,h);
            canvas->fillRect(p1.x,p1.y,w,h);
        }
        for(auto& wall:walls){
            wall.draw(canvas,w,h);
        }
    }

    void remove(WallP wall_p){
        walls.at(static_cast<int>(wall_p)).setVisible(false);
    }
};

struct CurrentCell{
    //todo use constructor to set the first current cell

    std::reference_wrapper<Cell> m_cell;

    CurrentCell(Cell& cell):m_cell(cell)
    {
        m_cell.get().setCurrent(true);
        m_cell.get().setVisited();
    }

    void set(Cell& cell_p){

        m_cell.get().setCurrent(false);

        m_cell = cell_p;
        m_cell.get().setCurrent(true);
        m_cell.get().setVisited();
    }

    Cell& cell(){return m_cell;}
};

//void breakWall(Cell& a, Cell& b){

//}


class MazeGenerator:public Application
{
    std::vector<Cell> cells;
    CurrentCell current;
public:
    MazeGenerator()
        :cells{make_grid()}
        ,current(cells.at(0)){


    }

    std::vector<Cell> make_grid(){
        std::vector<Cell> grid;
        for(int i= 0;i< CELL_COL_NUMBER;i++){
            for(int j= 0;j< CELL_ROW_NUMBER;j++){
                grid.emplace_back(i,j);
            }
        }
        return grid;
    }


    virtual ~MazeGenerator()=default;

    Cell& FindUnvisitedNeighbor(){

    }


    void draw(Canvas *canvas)
    {
        std::cout<<"draw\n";
        canvas->setBackground(0,0,0);


        for(auto& cell:cells){
            cell.draw(canvas);
        }
        static int cpt=0;
        if(cpt<cells.size()-1) cpt++;
        current.set(cells.at(cpt));
    }

    // Application interface
public:
    void setup(int &width, int &height,int& framerate)override
    {
        width = height = 600;
        framerate = 10;
    }
};

#endif // MAZELGENERATOR_H

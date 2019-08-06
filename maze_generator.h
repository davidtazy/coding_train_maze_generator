#ifndef MAZELGENERATOR_H
#define MAZELGENERATOR_H
#include <array>
#include <vector>
#include <iostream>
#include <functional>
#include "application.h"

enum class WallP{Top=0,Left,Bottom,Right};


struct Point{
    int x,y;
};

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


    bool isTop()const{return pos== WallP::Top;}
    bool isBottom()const{return pos== WallP::Bottom;}
    bool isLeft()const{return pos== WallP::Left;}
    bool isRight()const{return pos== WallP::Right;}
};



std::vector<int> range(int begin,int end=-1);

struct Cell{
    int col,row;
    bool m_visited{false};
    bool m_current{false};

    std::array<Wall,4> m_walls;

    Cell(int col_p,int row_p):col(col_p),row(row_p){
        for(int index:range(m_walls.size()) ){
            m_walls.at(index) = Wall(col,row,static_cast<WallP>(index));
        }
    }

    void setVisited(){
        m_visited = true;
    }
    bool visited()const{return m_visited;}
    void setCurrent(bool c){m_current = c;}
    bool current()const{return m_current;}

    void forEach(std::function<void(const Wall&wall_p,WallP)>cb)const{
        for(int index:range(m_walls.size()) ){
            cb(m_walls.at(index),static_cast<WallP>(index));
        }
    }

    void remove(WallP wall_p){
        m_walls.at(static_cast<int>(wall_p)).setVisible(false);
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


struct MazeGenerator{

    const int m_nb_row ;
    const int m_nb_col;
    std::vector<Cell> cells;
    CurrentCell m_current;
    int m_iteration = 0;
public:
    MazeGenerator(int nb_row,int nb_col)
        :m_nb_row(nb_row)
        ,m_nb_col(nb_col)
        ,cells{make_grid()}
        ,m_current(cells.at(0)){
    }

    const CurrentCell& current()const{return m_current;}


    void step(){
        if(m_iteration<cells.size()-1) m_iteration++;
        m_current.set(cells.at(m_iteration));
    }

    bool finished()const{
        return m_iteration == cells.size()-1;
    }


    void forEach(std::function<void(const Cell&)> cb){
        for(const auto & cell:cells){
            for(int j= 0;j< m_nb_row;j++){
                cb(cell);
            }
        }
    }

    std::vector<Cell> make_grid()const{
        std::vector<Cell> grid;
        for(int i= 0;i< m_nb_col;i++){
            for(int j= 0;j< m_nb_row;j++){
                grid.emplace_back(i,j);
            }
        }
        return grid;
    }


};

#endif // MAZELGENERATOR_H

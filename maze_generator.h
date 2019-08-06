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

struct GridSize{
    int column;
    int row;
};

struct GridPosition{
    int column;
    int row;

    GridPosition LeftTo()const{
        return {column-1,row};
    }

    GridPosition RightTo()const{
        return {column+1,row};
    }

    GridPosition TopTo()const{
        return {column,row-1};
    }

    GridPosition BottomTo()const{
        return {column,row+1};
    }

    bool valid(GridSize size)const{
        return (column >=0 && row >=0 && column < size.column && row < size.row);
    }
};

struct Wall{
    GridPosition position;
    WallP pos;
    int id;
    bool invalid{true};
    bool visible{true};

    Wall()=default;
    Wall(GridPosition position_p,WallP pos):position(position_p),pos(pos),invalid(false){
    }

    void setVisible(bool v){visible = v;}


    bool isTop()const{return pos== WallP::Top;}
    bool isBottom()const{return pos== WallP::Bottom;}
    bool isLeft()const{return pos== WallP::Left;}
    bool isRight()const{return pos== WallP::Right;}
};



std::vector<int> range(int begin,int end=-1);

struct Cell{
    GridPosition m_position;
    bool m_visited{false};
    bool m_current{false};

    std::array<Wall,4> m_walls;

    Cell(GridPosition position_p)
        :m_position(position_p)
    {

        for(int index:range(m_walls.size()) ){
            m_walls.at(index) = Wall(m_position,static_cast<WallP>(index));
        }
    }

    void setVisited(){
        m_visited = true;
    }
    bool visited()const{return m_visited;}
    void setCurrent(bool c){m_current = c;}
    bool current()const{return m_current;}

    void forEachWall(std::function<void(const Wall&wall_p,WallP)>cb)const{
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
    const Cell& cell()const{return m_cell;}
};

class Grid{
    GridSize m_size;
    std::vector<Cell> m_cells;
public:
    Grid(GridSize size)
        :m_size(size)
        ,m_cells(make_grid()){

    }
    Cell& first(){
        return m_cells.at(0);
    }

    std::vector<Cell> make_grid()const{
        std::vector<Cell> grid;
        for(int i= 0;i< m_size.column;i++){
            for(int j= 0;j< m_size.row;j++){
                GridPosition pos;
                pos.column = i;
                pos.row = j;
                grid.emplace_back(pos);
            }
        }
        return grid;
    }

    void forEach(std::function<void(const Cell&)> cb)const{
        for(const auto & cell:m_cells){
            cb(cell);
        }
    }

    void forEachNeighbor(const Cell& cell_p,std::function<void(Cell&)> cb){

        auto pos = cell_p.m_position;

        for( auto neighbor:{pos.TopTo(),pos.LeftTo(),pos.BottomTo(),pos.RightTo()}){
            if(neighbor.valid(m_size)){
                cb(at(neighbor));
            }
        }
    }

    Cell& at(GridPosition pos_p){
        return m_cells.at(pos_p.column*m_size.column + pos_p.row);
    }
};


int random(int max);

#include <stack>
struct MazeGenerator{

    Grid m_grid;
    CurrentCell m_current;
    std::stack<std::reference_wrapper<Cell>> m_stack;
    bool m_finished{false};

public:
    MazeGenerator(GridSize size_p)
        :m_grid{size_p}
        ,m_current(m_grid.first())
    {
        m_stack.push(m_grid.first());
    }

    const CurrentCell& current()const{return m_current;}


    std::vector<std::reference_wrapper<Cell>> unvisitedNeighbors(){

        std::vector<std::reference_wrapper<Cell>> ret;


        m_grid.forEachNeighbor(m_current.cell(), [ &ret ] (Cell& cell_p){
            if(!cell_p.visited())  ret.push_back(cell_p);
        });

        return ret;
    }

    void step(){

        auto neighbors = unvisitedNeighbors();

        if( ! neighbors.empty()){
            int random_neighbor = random(neighbors.size());
            auto& next  = neighbors.at(random_neighbor);
            m_stack.push(next);
            m_current.set(next);
        }else if(m_stack.size()){
            auto & previous = m_stack.top();
            m_stack.pop();
            m_current.set(previous);
        }else{
            m_finished = true;
        }

    }

    bool finished()const{
        return m_finished;
    }


    void forEach(std::function<void(const Cell&)> cb){
        m_grid.forEach(cb);
    }



};

#endif // MAZELGENERATOR_H

#include <QObject>
#include <QTest>

#include "../maze_generator.h"

class testGrid:public QObject{

    Q_OBJECT

private slots:

    void can_iterate_all_grid_data(){
        QTest::addColumn<int>("row");
        QTest::addColumn<int>("col");

        QTest::newRow("line")<<1<<3;
        QTest::newRow("square")<<10<<10;
        QTest::newRow("column")<<10<<1;
        QTest::newRow("1 cell")<<1<<1;
        return;


    }

    void can_iterate_all_grid(){

        QFETCH(int,row);
        QFETCH(int,col);
        GridSize size;
        size.row = row;
        size.column = col;

        Grid g(size);

        for(int i =0;i<col;i++){
             for(int j =0;j<row;j++){
                GridPosition pos;
                pos.row = j;
                pos.column = i;
                auto& cell = g.at(pos);
                QVERIFY(cell.m_position == pos);
             }
        }
    }
};
QTEST_MAIN(testGrid)
#include "test_grid.moc"

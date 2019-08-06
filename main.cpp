#include <QApplication>

#include "qtcanvas.h"



#include "mazeapplication.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MazeApplication app;
    QtCanvas canvas(&app);


    canvas.show();

    return a.exec();
}

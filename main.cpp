#include <QApplication>

#include "qtcanvas.h"



#include "mazelgenerator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MazelGenerator app;
    QtCanvas canvas(&app);


    canvas.show();

    return a.exec();
}

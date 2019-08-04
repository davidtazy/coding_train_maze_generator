#include "qtcanvas.h"


QtCanvas::QtCanvas(Application *app)
    :m_app(app)
{
    int w=600,h=400,fr=0;

    app->setup(w,h,fr);
    resize(w,h);

    if (fr>0){
        timer.setInterval(1000/fr);
        timer.setTimerType(Qt::PreciseTimer);
        timer.start();
       // connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
        connect(&timer,&QTimer::timeout,this,[this](){
            this->update();
        });
    }
}

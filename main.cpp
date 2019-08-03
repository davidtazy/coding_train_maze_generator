#include <QApplication>
#include <QPainter>
#include <QWidget>

struct Canvas{
    virtual ~Canvas()=default;
   // virtual void save()=0;
   // virtual void restore() =0;
    virtual void setBackground(int r,int g, int b)=0;

   // virtual void drawLine(int x1, int y1, int x2, int y2)=0;


protected:
    virtual bool isDrawing()const=0;
    void ThrowIfNotDrawing(){
        if( ! isDrawing()){
            throw std::runtime_error("try to draw when not in draw state");
        }
    }
};

class Application{

public:
    virtual void setup(int& width,int& height)=0;

    virtual void draw(Canvas* canvas)=0;
};

class QtCanvas:public Canvas,public QWidget{

    QPainter* m_painter{};
    Application*m_app{};

    // Canvas interface
public:
    QtCanvas(Application*app)
        :m_app(app)
    {
        int w=600,h=400;
        app->setup(w,h);
        resize(w,h);
    }

    void setBackground(int r, int g, int b)
    {
        ThrowIfNotDrawing();
        m_painter->fillRect(0,0,width(),height(),QColor(r,g,b));
    }

protected:
    void paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        m_painter = &painter;


        m_app->draw(this);
        painter.setPen(Qt::blue);
            painter.setFont(QFont("Arial", 30));
            painter.drawText(rect(), Qt::AlignCenter, "Qt");



        m_painter = nullptr;
    }

    // Canvas interface
protected:
    bool isDrawing() const
    {
        return m_painter;
    }
};

struct MyApp:Application{


    // Application interface
public:
    void draw(Canvas *canvas)
    {
        canvas->setBackground(255,0,0);
    }

    // Application interface
public:
    void setup(int &width, int &height)
    {
    }
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyApp app;
    QtCanvas canvas(&app);


    canvas.show();

    return a.exec();
}

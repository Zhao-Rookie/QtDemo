#include "MainWindow.h"
#include <QApplication>
#include <QGraphicsView>
#include "Item/InstrumentItem.h"
#include "InstrumentScene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 创建场景和视图
    InstrumentScene *scene = new InstrumentScene();
    QGraphicsView *view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);

    // 创建第一个测试仪器
    InstrumentItem *instrument1 = new InstrumentItem(QRectF(0, 0, 100, 50), "Instrument 1");
    instrument1->addPort(0, 20, "input");
    instrument1->addPort(90, 20, "output");
    scene->addItem(instrument1);scene->update();
//    instrument1->setFlag(InstrumentItem::ItemIsMovable,false);

    // 创建第二个测试仪器
    InstrumentItem *instrument2 = new InstrumentItem(QRectF(150, 0, 100, 50), "Instrument 2");
    instrument2->addPort(0, 20, "input");
    scene->addItem(instrument2);scene->update();

    view->setGeometry(100, 100, 800, 600);
    view->show();


    return a.exec();
}

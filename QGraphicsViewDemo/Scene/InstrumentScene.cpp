#include "InstrumentScene.h"
#include "Item/PortItem.h"
#include "Item/ConnectionLineItem.h"
#include "Item/InstrumentItem.h"
InstrumentScene::InstrumentScene(QObject *parent)
    : QGraphicsScene(parent)
    , line(nullptr)
    , startPort(nullptr)
{

}


void InstrumentScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem *item = itemAt(event->scenePos(), QTransform());
    PortItem *port = dynamic_cast<PortItem *>(item);
    qDebug() <<event->scenePos() << port << "mousePressEvent=======================" << endl;
    // 如果点击了输出端口，开始绘制连接线
    if (port) {
        if (port->getPortType() == "output") {
            startPort = port;
            line = addLine(QLineF(port->rect().center(), port->rect().center()), QPen(Qt::black, 2));
        }
    }
    else
    {
        // 如果点击了仪器，允许移动
        QGraphicsScene::mousePressEvent(event);
    }

}

void InstrumentScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if (line) {
        // 动态更新连接线的终点为鼠标当前位置
        QLineF newLine(line->line().p1(), event->scenePos());
        line->setLine(newLine);
    }

    // 移动仪器
    QGraphicsScene::mouseMoveEvent(event);
}

void InstrumentScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem *item = itemAt(event->scenePos(), QTransform());

    QList<QGraphicsItem*> itemsUnderMouse = items(event->scenePos());

    // 遍历项，查找是否有输入端口
    PortItem* endPort = nullptr;
    for (QGraphicsItem* item : itemsUnderMouse) {
        if (PortItem* port = dynamic_cast<PortItem*>(item)) {
            if (port->getPortType() == "input") {
                endPort = port;
                break;  // 找到输入端口后可以停止
            }
        }
    }

    if (endPort)
    {
        // 如果找到了输入端口，则创建连接线
        addItem(new ConnectionLineItem(startPort, endPort));
    }
    else
    {
        // 移除临时绘制的线
        removeItem(line);
        delete line;
        line = nullptr;
        startPort = nullptr;
    }

    QGraphicsScene::mouseReleaseEvent(event);
}

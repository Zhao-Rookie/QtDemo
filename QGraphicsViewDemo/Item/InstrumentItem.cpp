#include "InstrumentItem.h"
#include "PortItem.h"
#include <QDebug>

InstrumentItem::InstrumentItem(const QRectF &rect, const QString &name): QGraphicsRectItem(rect), name(name)
{
    setPen(QPen(Qt::black, 2));
    setBrush(QBrush(Qt::lightGray));
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
}

void InstrumentItem::addPort(qreal x, qreal y, const QString &portType)
{
    qDebug() << this->x() << this->y() << this->rect() << endl;


    PortItem *port = new PortItem(this, this->rect().x() + x, this->rect().y() + y, portType);
    ports.push_back(port);
}

#include "ConnectionLineItem.h"
#include "PortItem.h"

ConnectionLineItem::ConnectionLineItem(PortItem *startPort, PortItem *endPort) : startPort(startPort), endPort(endPort)
{
    setPen(QPen(Qt::blue, 2));
    updatePosition();
}

void ConnectionLineItem::updatePosition()
{
    QPointF start = startPort->rect().center();
    QPointF end = endPort->rect().center();
    setLine(QLineF(start, end));
}

void ConnectionLineItem::advance(int phase)
{
    if (phase == 0)
        return;
    updatePosition();
}

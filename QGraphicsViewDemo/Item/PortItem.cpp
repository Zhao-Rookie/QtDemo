#include "PortItem.h"
#include "InstrumentItem.h"

PortItem::PortItem(InstrumentItem *parent, qreal x, qreal y, const QString &portType)
    : QGraphicsRectItem(QRectF(x, y, 10, 10), parent), portType(portType)
{
    setBrush(portType == "input" ? Qt::green : Qt::red);
}

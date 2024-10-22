#ifndef PORTITEM_H
#define PORTITEM_H
#include <QGraphicsRectItem>
#include <QPen>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>

class InstrumentItem;
class PortItem : public QGraphicsRectItem
{
public:
    PortItem(InstrumentItem *parent, qreal x, qreal y, const QString &portType);

    QString getPortType() const { return portType; }

private:
    QString portType;
};

#endif // PORTITEM_H

#ifndef INSTRUMENTITEM_H
#define INSTRUMENTITEM_H
#include <QGraphicsRectItem>
#include <QPen>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>

class PortItem;
class InstrumentItem: public QGraphicsRectItem
{
public:
    InstrumentItem(const QRectF &rect, const QString &name);

    void addPort(qreal x, qreal y, const QString &portType);

    QString getName() const { return name; }

    std::vector<PortItem *> getPorts() { return ports; }

private:
    QString name;
    std::vector<PortItem *> ports;
};

#endif // INSTRUMENTITEM_H

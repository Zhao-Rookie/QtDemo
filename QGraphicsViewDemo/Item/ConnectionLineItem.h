#ifndef CONNECTIONLINEITEM_H
#define CONNECTIONLINEITEM_H
#include <QGraphicsLineItem>
#include <QPen>
#include <QPointF>

class PortItem;
class ConnectionLineItem : public QGraphicsLineItem
{
public:
    ConnectionLineItem(PortItem *startPort, PortItem *endPort);

    void updatePosition();

    void advance(int phase) override;

private:
    PortItem *startPort;
    PortItem *endPort;
};

#endif // CONNECTIONLINEITEM_H

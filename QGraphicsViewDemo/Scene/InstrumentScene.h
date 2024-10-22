#ifndef INSTRUMENTSCENE_H
#define INSTRUMENTSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QDebug>

class PortItem;
class InstrumentScene : public QGraphicsScene {
    Q_OBJECT

public:
    InstrumentScene(QObject *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QGraphicsLineItem *line;  // 正在绘制的连线
    PortItem *startPort;      // 连接线起始端口
};

#endif // INSTRUMENTSCENE_H

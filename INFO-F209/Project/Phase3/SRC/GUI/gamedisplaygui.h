#ifndef GAMEDISPLAYGUI_H
#define GAMEDISPLAYGUI_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCloseEvent>

#include "towerpanel.h"
#include "showinfogame.h"
#include "messageingamepanel.h"

class GameDisplayGui : public QWidget
{
    Q_OBJECT
public:
    explicit GameDisplayGui(QWidget *parent = 0);
    void setWindow(int gameMode);
    ~GameDisplayGui();
signals:
    void quitSignalGame();
private:
        QGraphicsPixmapItem pixItem;
        QGraphicsScene scene;
        QGraphicsView view;
        TowerPanel towerPanel;
        MessageInGamePanel messagePanel;
        ShowInfoGame infoGame;
        QVBoxLayout V1;
        QVBoxLayout V2;
        QHBoxLayout hGenral;
        QPixmap pixmapSrc;
private slots:
    void closeEvent(QCloseEvent *event);


};

#endif // GAMEDISPLAYGUI_H

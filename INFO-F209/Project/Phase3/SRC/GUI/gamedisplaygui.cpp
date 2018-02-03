#include "gamedisplaygui.h"
GameDisplayGui::GameDisplayGui(QWidget *parent) : QWidget(parent)
{
}

GameDisplayGui::~GameDisplayGui(){
	delete this;
}

void GameDisplayGui::setWindow(int gameMode){
    if(gameMode == 1){
        pixmapSrc.load("../GUI/map_team.png");
    }
    else if(gameMode == 2){
        pixmapSrc.load("../GUI/map_time.png");
    }
    else if(gameMode == 3){
        pixmapSrc.load("../GUI/map_vs.png");
    }
    pixItem.setPixmap(pixmapSrc);
    scene.addItem(&pixItem);
    view.setScene(&scene);
    V1.addWidget(&view);
    V1.addWidget(&messagePanel);
    V2.addWidget(&towerPanel);
    V2.addWidget(&infoGame);
    hGenral.addLayout(&V1);
    hGenral.addLayout(&V2);
    this->setLayout(&hGenral);
}

void GameDisplayGui::closeEvent(QCloseEvent *event){
    emit quitSignalGame();
    QWidget::closeEvent(event);
}
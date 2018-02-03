#include "showinfogame.h"
#include "ui_showinfogame.h"

ShowInfoGame::ShowInfoGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowInfoGame)
{
    ui->setupUi(this);
}

ShowInfoGame::~ShowInfoGame()
{
    delete ui;
}

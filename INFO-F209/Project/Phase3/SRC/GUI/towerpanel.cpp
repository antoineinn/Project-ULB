#include "towerpanel.h"
#include "ui_towerpanel.h"

TowerPanel::TowerPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TowerPanel)
{
    ui->setupUi(this);
}

TowerPanel::~TowerPanel()
{
    delete ui;
}

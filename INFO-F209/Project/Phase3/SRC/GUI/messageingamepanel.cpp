#include "messageingamepanel.h"
#include "ui_messageingamepanel.h"

MessageInGamePanel::MessageInGamePanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageInGamePanel)
{
    ui->setupUi(this);
}

MessageInGamePanel::~MessageInGamePanel()
{
    delete ui;
}

#ifndef MESSAGEINGAMEPANEL_H
#define MESSAGEINGAMEPANEL_H

#include <QDialog>

namespace Ui {
class MessageInGamePanel;
}

class MessageInGamePanel : public QDialog
{
    Q_OBJECT

public:
    explicit MessageInGamePanel(QWidget *parent = 0);
    ~MessageInGamePanel();

private:
    Ui::MessageInGamePanel *ui;
};

#endif // MESSAGEINGAMEPANEL_H

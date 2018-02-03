#ifndef SHOWINFOGAME_H
#define SHOWINFOGAME_H

#include <QDialog>

namespace Ui {
class ShowInfoGame;
}

class ShowInfoGame : public QDialog
{
    Q_OBJECT

public:
    explicit ShowInfoGame(QWidget *parent = 0);
    ~ShowInfoGame();

private:
    Ui::ShowInfoGame *ui;
};

#endif // SHOWINFOGAME_H

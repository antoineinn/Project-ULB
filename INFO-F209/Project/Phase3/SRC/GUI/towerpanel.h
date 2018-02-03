#ifndef TOWERPANEL_H
#define TOWERPANEL_H

#include <QDialog>

namespace Ui {
class TowerPanel;
}

class TowerPanel : public QDialog
{
    Q_OBJECT

public:
    explicit TowerPanel(QWidget *parent = 0);
    ~TowerPanel();

private:
    Ui::TowerPanel *ui;
};

#endif // TOWERPANEL_H

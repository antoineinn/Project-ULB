#ifndef MENUOPTION_H
#define MENUOPTION_H

#include <QDialog>
#include <QCloseEvent>
#include <QRadioButton>
#include <QMovie>

namespace Ui {
class MenuOption;
}

class MenuOption : public QDialog
{
    Q_OBJECT

public:
    explicit MenuOption(QWidget *parent = 0);
    ~MenuOption();
signals:
    void showFriend();
    void showProfil();
	void showRanking();
    void signalLogOut();
	void playSignal(int);
private:
    Ui::MenuOption *ui;
	int gameMode;
    void resetRadioButton();
    void handleRadioButton(QRadioButton *button);
	QMovie *movie ;
    QMovie *movie2 ;

private slots:
    void on_showFriendButton_clicked();
    void on_showProfilButton_clicked();
	void on_showRankingButton_clicked();
    void on_leaveButton_clicked();
    void closeEvent(QCloseEvent *event);
	void on_playButton_clicked();
	void on_vsButton_toggled();
    void on_teamButton_toggled();
    void on_timeButton_toggled();
};

#endif // MENUOPTION_H

#ifndef PROFILVIEW_H
#define PROFILVIEW_H

#include <QDialog>
#include <QCloseEvent>
#include <QMovie>
#include <string>
namespace Ui {
class ProfilView;
}

class ProfilView : public QDialog
{
    Q_OBJECT

public:
    explicit ProfilView(QWidget *parent = 0);
    ~ProfilView();
    void setPlayerLineEdit(std::string);
    void setBestScoreLabel(std::string);
    void setFriendLabel(std::string);

signals:
	void showMenuOption();

private:
    Ui::ProfilView *ui;
	QMovie *movie;
private slots:
	void on_QuitButton_clicked();
	void closeEvent(QCloseEvent *event);
};

#endif // PROFILVIEW_H

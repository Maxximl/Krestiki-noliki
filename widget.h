#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QtWidgets>
namespace Ui {
class Widget;
}

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void checkWin();
    void changePlName();
    ~Widget();

private:
    Ui::Widget *ui;
    QPushButton *btn_tl;
    QPushButton *btn_tm;
    QPushButton *btn_tr;
    QPushButton *btn_ml;
    QPushButton *btn_mm;
    QPushButton *btn_mr;
    QPushButton *btn_bl;
    QPushButton *btn_bm;
    QPushButton *btn_br;
    QPushButton *btn_clear;
      QLabel *player_name1;

public slots:

    void clear();
    void buttonpressed(int xo);
};

#endif // WIDGET_H

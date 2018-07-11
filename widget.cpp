#include "widget.h"
#include "ui_widget.h"
#include <QtWidgets>
#include <QMessageBox>
Widget::Widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Создаем кнопки
    btn_tl = new QPushButton;
    btn_tm = new QPushButton;
    btn_tr = new QPushButton;
    btn_ml = new QPushButton;
    btn_mm = new QPushButton;
    btn_mr = new QPushButton;
    btn_bl = new QPushButton;
    btn_bm = new QPushButton;
    btn_br = new QPushButton;



    btn_clear = new QPushButton("Очистить поле");
    //Создаем ярлык
     player_name1 = new QLabel;
     player_name1->setText("Player 1");
     QFont font("Arial",16);
     player_name1->setFont(font);

     //Создаем сетку
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(player_name1,0,0,1,3,Qt::AlignCenter);
    grid->addWidget(btn_tl,1,0);
    grid->addWidget(btn_tm,1,1);
    grid->addWidget(btn_tr,1,2);
    grid->addWidget(btn_ml,2,0);
    grid->addWidget(btn_mm,2,1);
    grid->addWidget(btn_mr,2,2);
    grid->addWidget(btn_bl,3,0);
    grid->addWidget(btn_bm,3,1);
    grid->addWidget(btn_br,3,2);

    grid->addWidget(btn_clear,4,0,1,3,Qt::AlignCenter);
    QWidget * centralWidget = new QWidget(this);
    centralWidget->setLayout(grid);
    setCentralWidget(centralWidget);

    //Размер и название окна
    resize(300,300);
    setWindowTitle("Крестики-нолики");
    //Задаем политику размера
    btn_tl->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btn_tm->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btn_tr->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btn_ml->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btn_mm->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btn_mr->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btn_bl->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btn_bm->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btn_br->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btn_clear->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    //Создаем маппер
    QSignalMapper *maper = new QSignalMapper(this);
    connect (btn_tl,SIGNAL(clicked()),maper,SLOT(map())); //1
    connect (btn_tm,SIGNAL(clicked()),maper,SLOT(map())); //2
    connect (btn_tr,SIGNAL(clicked()),maper,SLOT(map())); //3
    connect (btn_ml,SIGNAL(clicked()),maper,SLOT(map())); //4
    connect (btn_mm,SIGNAL(clicked()),maper,SLOT(map())); //5
    connect (btn_mr,SIGNAL(clicked()),maper,SLOT(map())); //6
    connect (btn_bl,SIGNAL(clicked()),maper,SLOT(map())); //7
    connect (btn_bm,SIGNAL(clicked()),maper,SLOT(map())); //8
    connect (btn_br,SIGNAL(clicked()),maper,SLOT(map())); //9
    connect (btn_clear,SIGNAL(clicked()),this,SLOT(clear()));

    maper->setMapping(btn_tl,1);
    maper->setMapping(btn_tm,2);
    maper->setMapping(btn_tr,3);
    maper->setMapping(btn_ml,4);
    maper->setMapping(btn_mm,5);
    maper->setMapping(btn_mr,6);
    maper->setMapping(btn_bl,7);
    maper->setMapping(btn_bm,8);
    maper->setMapping(btn_br,9);

    connect (maper,SIGNAL(mapped(int)),this,SLOT(buttonpressed(int)));

}







void Widget::clear(){
btn_tl->setText("");
btn_tm->setText("");
btn_tr->setText("");
btn_ml->setText("");
btn_mm->setText("");
btn_mr->setText("");
btn_bl->setText("");
btn_bm->setText("");
btn_br->setText("");
changePlName();
}

void Widget::buttonpressed(int xo) {
    if (player_name1->text()=="Player 1"){
      switch(xo){
      case 1: if(btn_tl->text().isEmpty()){
              btn_tl->setText("X");
              checkWin();
            player_name1->setText("Player 2"); }//теперь первым ходит второй игрок
          break;
      case 2: if(btn_tm->text().isEmpty()){
              btn_tm->setText("X");
              checkWin();
           player_name1->setText("Player 2"); }//теперь первым ходит второй игрок
          break;
      case 3: if(btn_tr->text().isEmpty()){
              btn_tr->setText("X");
              checkWin();
           player_name1->setText("Player 2");} //теперь первым ходит второй игрок
          break;
      case 4: if(btn_ml->text().isEmpty()){
              btn_ml->setText("X");
              checkWin();
           player_name1->setText("Player 2");} //теперь первым ходит второй игрок
          break;
      case 5: if(btn_mm->text().isEmpty()){
              btn_mm->setText("X");
              checkWin();
           player_name1->setText("Player 2");} //теперь первым ходит второй игрок
          break;
      case 6: if(btn_mr->text().isEmpty()){
              btn_mr->setText("X");
              checkWin();
           player_name1->setText("Player 2");} //теперь первым ходит второй игрок
          break;
      case 7: if(btn_bl->text().isEmpty()){
              btn_bl->setText("X");
           player_name1->setText("Player 2");} //теперь первым ходит второй игрок
          break;
      case 8: if(btn_bm->text().isEmpty()){
              btn_bm->setText("X");
              checkWin();
           player_name1->setText("Player 2");} //теперь первым ходит второй игрок
          break;
      case 9: if(btn_br->text().isEmpty()){
              btn_br->setText("X");
              checkWin();
           player_name1->setText("Player 2");} //теперь первым ходит второй игрок
          break;
      }



    }
    else {
        switch(xo){
        case 1: if(btn_tl->text().isEmpty()){
                btn_tl->setText("O");
                checkWin();
             player_name1->setText("Player 1");}

            break;
        case 2: if(btn_tm->text().isEmpty()){
                btn_tm->setText("O");
                checkWin();
             player_name1->setText("Player 1");}
            break;
        case 3: if(btn_tr->text().isEmpty()){
                btn_tr->setText("O");
                checkWin();
             player_name1->setText("Player 1");}
            break;
        case 4: if(btn_ml->text().isEmpty()){
                btn_ml->setText("O");
                checkWin();
             player_name1->setText("Player 1");}
            break;
        case 5: if(btn_mm->text().isEmpty()){
                btn_mm->setText("O");
                checkWin();
             player_name1->setText("Player 1");}
            break;
        case 6: if(btn_mr->text().isEmpty()){
                btn_mr->setText("O");
                checkWin();
             player_name1->setText("Player 1");}
            break;
        case 7: if(btn_bl->text().isEmpty()){
                btn_bl->setText("O");
                checkWin();
             player_name1->setText("Player 1");}
            break;
        case 8: if(btn_bm->text().isEmpty()){
                btn_bm->setText("O");
                checkWin();
             player_name1->setText("Player 1");}
            break;
        case 9: if(btn_br->text().isEmpty()){
                btn_br->setText("O");
                checkWin();
             player_name1->setText("Player 1");}
            break;
            }
         }

}


void Widget::checkWin()
{
    if(((btn_tl->text() == "X")&&(btn_tm->text() == "X")&&(btn_tr->text() == "X"))
            || ((btn_tl->text() == "X") && (btn_mm->text() == "X") && (btn_br->text() == "X"))
            || ((btn_bl->text() == "X") && (btn_mm->text() == "X") && (btn_tr->text() == "X"))
            || ((btn_mr->text() == "X") && (btn_mm->text() == "X") && (btn_ml->text() == "X")))
    {
        QMessageBox::information(this,"Поздравляю!","Вы выиграли!");
        clear();
    }
    else
    {
        changePlName();
    }

}

void Widget::changePlName()
{
    if(player_name1->text() == "Player 1"){
    player_name1->setText("Player 2");
   }
    else if(player_name1->text() == "Player 2"){
    player_name1->setText("Player 1");
    }
}

Widget::~Widget()
{
    delete ui;
}

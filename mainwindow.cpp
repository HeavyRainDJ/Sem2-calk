#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "operations.h"
#define ERROR 98765e-99
#define range 20
// работа после экспоненты
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_num_0,SIGNAL(clicked()),this, SLOT(click_num()));
    connect(ui->btn_num_1,SIGNAL(clicked()),this, SLOT(click_num()));
    connect(ui->btn_num_2,SIGNAL(clicked()),this, SLOT(click_num()));
    connect(ui->btn_num_3,SIGNAL(clicked()),this, SLOT(click_num()));
    connect(ui->btn_num_4,SIGNAL(clicked()),this, SLOT(click_num()));
    connect(ui->btn_num_5,SIGNAL(clicked()),this, SLOT(click_num()));
    connect(ui->btn_num_6,SIGNAL(clicked()),this, SLOT(click_num()));
    connect(ui->btn_num_7,SIGNAL(clicked()),this, SLOT(click_num()));
    connect(ui->btn_num_8,SIGNAL(clicked()),this, SLOT(click_num()));
    connect(ui->btn_num_9,SIGNAL(clicked()),this, SLOT(click_num()));

    connect(ui->btn_plus, SIGNAL(clicked()),this, SLOT(btn_click_operation()));
    connect(ui->btn_minus, SIGNAL(clicked()),this, SLOT(btn_click_operation()));
    connect(ui->btn_mult, SIGNAL(clicked()),this, SLOT(btn_click_operation()));
    connect(ui->btn_div, SIGNAL(clicked()),this, SLOT(btn_click_operation()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow:: condition_Button_Number(bool statement)
{
    ui->btn_num_0->setEnabled(statement);
    ui->btn_num_1->setEnabled(statement);
    ui->btn_num_2->setEnabled(statement);
    ui->btn_num_3->setEnabled(statement);
    ui->btn_num_4->setEnabled(statement);
    ui->btn_num_5->setEnabled(statement);
    ui->btn_num_6->setEnabled(statement);
    ui->btn_num_7->setEnabled(statement);
    ui->btn_num_8->setEnabled(statement);
    ui->btn_num_9->setEnabled(statement);
}
void MainWindow :: condition_Button_Options(bool statement)
{
    ui->btn_mult->setEnabled(statement);
    ui->btn_plus->setEnabled(statement);
    ui->btn_div->setEnabled(statement);
    ui->btn_minus->setEnabled(statement);
    ui->btn_equall->setEnabled(statement);
}

void MainWindow:: click_num()
{
    //ui наш вид виджета посылаем запрос на лабел инсер на котором если 0 то текст просто становится,  либо дописывается - либо заменяется на новое число которое будет дописыватся
    QPushButton *btn = (QPushButton *) sender(); //sender тип данных QObject* (класс, вокруг которого построена объектная модель Qt)
    ui->btn_negative->setEnabled(false);
    condition_Button_Options(true);
    //ui->btn_dot->setEnabled(false);
    if((ui->insert_label->text()).size()>range)
        QMessageBox::information(this,"ERROR","Calck dont state big number, calk need low number, under twenty, please reset");
    else{
        if(ui->insert_label->text()=="0"){
            ui->insert_label->setText(btn->text());
        }else if( ui->insert_label->text()=="-0"){
            ui->insert_label->setText( "-" + btn->text());
        } else{
            ui->insert_label->setText(ui->insert_label->text() + btn->text());
        }
        if(!ui->insert_label->text().contains("."))
            ui->btn_dot->setEnabled(true);
    }
}
void MainWindow::btn_click_operation(){
    QPushButton *btn =(QPushButton*)sender();
    //ui->btn_dot->setEnabled(false);
    ui->btn_negative->setEnabled(true);
    condition_Button_Number(true);
    ui->btn_del->setEnabled(true);
    QString temp = ui->insert_label->text();
    operation=btn->text();
    if(num1!=""){
        num1=actions(num1,ui->insert_label->text(),operation);

    }else{
        num1=temp;
    }
    ui->insert_label->setText("");
}
void MainWindow::on_btn_del_clicked()
{
    QString str = ui ->insert_label->text(); //запись в стр строку текста с лейбла
    str.chop(1); // удаляет символ с конца строки
    if(str.isEmpty()){ // если строка пуста то блокировки негатив и дот
        ui->btn_negative->setEnabled(true);
        //ui->btn_dot->setEnabled(false);
        condition_Button_Options(false);
    }
    ui->insert_label->setText(str); // вывод строки на экран после стирания строки с конца + иф если лейбл не содержит точки то разблокирует кнопку точки
    if(!ui->insert_label->text().contains(".")){
        ui->btn_dot->setEnabled(true);
    }
}

void MainWindow::on_btn_negative_clicked()
{
    ui->insert_label->setText(ui->insert_label->text()+"-");//вывод на экран минуса
    ui->btn_negative->setEnabled(false);
}

// QmessageBox - класс позволяющий предоставлять диалог с пользователем
void MainWindow::on_btn_help_clicked()
{
    QMessageBox::information(this,tr("Helper"), tr("1)Dont to divide by zero\n"
                                                   "2)Dont insert number upper twenty signs\n"
                                                   "3)Boop--boop\n"),
                             tr("close"));// information c целью информирования а this указатель на экземпляр класса
}

void MainWindow::on_btn_clear_clicked()
{
    ui->insert_label->setText("");
    num1="";
    operation="";
    ui->btn_equall->setEnabled(true);
    ui->btn_dot->setEnabled(true);
    ui->btn_negative->setEnabled(true);
    condition_Button_Options(true);
    condition_Button_Number(true);
}

QString MainWindow::actions(QString num1, QString num2, QString operation){
    struct options options;
    options.num1=num1.toDouble();
    options.num2=num2.toDouble();
    QByteArray var = operation.toLatin1();
    options.operation= var.data();
    double result=operate(options);
    if(result==ERROR){
        QMessageBox::information(this,"Error code", "I dont div by zero");
        this->on_btn_clear_clicked();
    }
    else
        num1=QString::number(result);
    return num1;
}

void MainWindow::on_btn_dot_clicked()
{
    if(!ui->insert_label->text().contains("."))
        ui->insert_label->setText(ui->insert_label->text()+".");
    ui->btn_dot->setEnabled(false);
    //condition_Button_Options(false);
}


void MainWindow::on_btn_equall_clicked()
{
    ui->btn_equall->setEnabled(false);
    num1=actions(num1,ui->insert_label->text(),operation);
    ui->insert_label->setText(num1);
    if(ui->insert_label->text().contains("e")){
        ui->btn_del->setEnabled(false);
        condition_Button_Number(false);
        ui->btn_dot->setEnabled(false);
    }
    if(ui->insert_label->text().contains("inf")){
        ui->btn_del->setEnabled(false);
        condition_Button_Number(false);
        condition_Button_Options(false);
        ui->btn_dot->setEnabled(false);
        ui->btn_negative->setEnabled(false);

    }
    num1="";
}


void MainWindow::on_btn_mc_clicked()
{
    memory="0";
}


void MainWindow::on_btn_MR_clicked()
{
    ui->insert_label->setText(memory);
}


void MainWindow::on_btn_M_clicked()
{
    memory=ui->insert_label->text();
}


void MainWindow::on_btn_Mplus_clicked()
{
    QString num = ui->insert_label->text();
    memory= QString::number(memory.toDouble()+num.toDouble());
}


void MainWindow::on_btn_Mminus_clicked()
{
    QString num = ui->insert_label->text();
    memory= QString::number(memory.toDouble()-num.toDouble());
}


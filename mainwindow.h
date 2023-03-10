#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void  click_num();
    void btn_click_operation();
    void on_btn_del_clicked();
    void on_btn_negative_clicked();

    void condition_Button_Options(bool statement);
    void condition_Button_Number(bool statement);

    void on_btn_help_clicked();
    void on_btn_clear_clicked();
    void on_btn_dot_clicked();
    void on_btn_equall_clicked();



    void on_btn_mc_clicked();
    void on_btn_MR_clicked();
    void on_btn_M_clicked();
    void on_btn_Mplus_clicked();
    void on_btn_Mminus_clicked();

private:
    Ui::MainWindow *ui;
    QString num1;
    QString memory="0";
    QString operation;

    QString actions(QString num1, QString num2, QString operation);
};
#endif // MAINWINDOW_H

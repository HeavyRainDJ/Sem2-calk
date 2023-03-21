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
    //nullptr - задает константу пустого указателя которая может быть преобразована в любой необработанный тип указателя
// атрибут  - переменная связанная с классом или объектом
// методы - это функции позволяющие взаимодействовать с атрибутами изменять их( метод функция отвечающие за взаимодейств с класс)
private slots:

    void  click_num();
    void btn_click_operation();


private:
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
    Ui::MainWindow *ui;
    QString num1;
    QString memory="0";
    QString operation;
    QString actions(QString num1, QString num2, QString operation);
// класс представляющий стандартную строку символов
// конструктор - выделение  динамическое памяти под метод
// дизструктор - очищение памяти
// Класс - абстракция множества предметов все предметы в этом множестве имееют одинаковые хар-ки и у всех них соглас. линии поведения
};
#endif // MAINWINDOW_H

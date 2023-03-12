#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <QMainWindow>
#include <stdio.h>
#define error 98765e-99;
struct options{
    double num1;
    double num2;
    char* operation;
};
struct result{
    double value;
    int code;
};
double operate(struct options options);
#endif // OPERATIONS_H

#ifndef OPERATIONS_H
#define OPERATIONS_H
#define error 98765e-99;
struct options{
    double num1;
    double num2;
    char* operation;
};
double operate(struct options options);
#endif // OPERATIONS_H

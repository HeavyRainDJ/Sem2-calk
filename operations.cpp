#include "operations.h"

#include "mainwindow.h"

double operate(struct options options){
    double res=0;
    std::string operate = options.operation;
    if(operate=="+")
        res=options.num1+options.num2;
    else if(operate=="-")
        res=options.num1-options.num2;
    else if(operate=="*")
        res=options.num1*options.num2;
    else if(operate=="/" && (options.num2!=0))
        res=options.num1/options.num2;
    else if(operate=="/" && (options.num2==0)) {
        res=error;
    } else
        res = options.num2;
    return res;
}


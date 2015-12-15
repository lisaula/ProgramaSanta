#include "widget.h"
#include <QApplication>
#include<iostream>
using namespace std;

static int fibonacci(int n ){
    if(n > 1){
        return fibonacci(n-1 )+ fibonacci(n-2);
    }
    return n;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}


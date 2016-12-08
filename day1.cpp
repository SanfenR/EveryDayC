#include <iostream>
#include <stdlib.h>
using namespace std;

//
// Created by sanfen on 16/12/8.
//


//题目：求1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字以及条件判断语句（A?B:C）。

//----->fun1 start
//使用函数指针

typedef int (*fun)(int);
int func1(int n){
    return 0;
}
int func2(int n){
    fun f[2]={func1,func2};
    return n+f[(n != 0)](n - 1);
}

void function1(){
    cout<<func2(10) << endl;
}
//----->fun2 end


//----->fun2 start
//使用静态变量
class test{
    static int N;
    static int sum;
public :
    test(){
        sum += ++N;
    }
    static void reset(){
        N = sum = 0;
    }
    static int getSum(){
        return sum;
    }
};

int test::N = 0;
int test::sum = 0;

void function2(){
    test::reset();
    test *p=new test[10];
    cout<<test::getSum() << endl;
    delete []p;
}
//--->fun2 end


//----->fun3 start
//使用虚函数的编译多态性

class A{
public:
    virtual int sum(int n){return 0;};
};
class B:public A
{
public:
    int sum(int n){
        A a;B b;
        A *p[2]={&a,&b};
        return n+p[(n - 1 != 0)]->sum(n - 1);}
};

void function3(){
    B b;
    cout<<b.sum(10) << endl;
}

//----->fun3 end


int main(){
    function1();
    function2();
    function3();
    return 0;
}
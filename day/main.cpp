#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

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

int main(){
    test::reset();
    test *p=new test[10];
    cout<<test::getSum();
    delete []p;
    return 0;
}


//
// Created by sanfen on 16/12/12.
//

//题目: 求整数的2进制表示中1的个数

#include <iostream>
#include <stdlib.h>

using namespace std;

//整数 右移 相与
int function1(int i) {
    int count = 0;
    while(i) {
        if(i & 1)
            count ++;
        i = i >> 1;
    }
    return count;
}


//flag 左移 相与
int function2(int i) {
    int count = 0;
    unsigned int flag = 1;
    while(flag){
        if(i & flag){
            count ++;
        }
        flag = flag << 1;
    }
    return count;
}

int function3(int i) {
    int count = 0;
    while (i) {
        ++ count;
        i = (i - 1) & i;
    }
    return count;
}

int function4(unsigned int x)
{
    int n=0;
    while((x+1))
    {
        n++;
        x=x|(x+1);
    }
    return n;
}

int main() {
    cout << function1(6) << endl;
    cout << function2(6) << endl;
    cout << function3(6) << endl;
    cout << function4(6) << endl;
    return 0;
}
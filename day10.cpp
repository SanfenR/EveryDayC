//
// Created by sanfen on 2017/1/20.
//

#include day.h

void printMax(char *number, int i, const int &n);

using namespace std;

//题目：打印1到最大的n位数。如n=4，打印1-9999。

//思路：如果直接使用循环会导致int或者long都不够存储，因此使用string来存储数据，这里涉及到字符串以及字符串的加法。


void print(const int &n) {
    if (n <= 0) {
        return;
    }

    char *number = new char[n + 1];
    memset(number, '0', (n + 1) * sizeof(char));
    number[n] = '\0';

    printMax(number, 0, n);

    delete[] number;
}

void printMax(char *number, const int index, const int size) {
    if (!number)
        return;
    if (index == size) {//嵌套截止条件
        cout << number << endl;
        return;
    }
    for (int i = 0; i < 10; i++) {
        number[index] = (char) (i + '0');//index---当前调整的位数
        printMax(number, index + 1, size);
    }
}




int main() {
    print(4);
    return 0;
}

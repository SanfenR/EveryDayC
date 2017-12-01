//
// Created by sanfen on 2017/12/1.
//

//http://acm.hdu.edu.cn/showproblem.php?pid=1001
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    unsigned long long end, sum;
    while(cin  >> end) {
        sum = (1 + end) * (end) / 2;
        cout << sum << endl << endl;
    }
    return 0;
}
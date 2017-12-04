//
// Created by sanfen on 2017/12/2.
//
//http://acm.hdu.edu.cn/showproblem.php?pid=1003
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;


int main() {

    int n = 0;
    cin >> n;
    int size;
    for (int i = 0; i < n; ++i) {
        cin >> size;
        int *aValue = new int[size];
        for (int j = 0; j < size; ++j) {
            cin >> aValue[j];
        }

        int result = aValue[0];
        int resultStart = 1;
        int resultEnd = 1;
        int sum = aValue[0];
        int start = 1;
        int end = 1;

        for (int k = 1; k < size; ++k) {
            if (sum >= 0) {
                sum += aValue[k];
            } else {
                sum = aValue[k];
                start = k + 1;
            }
            end = k + 1;
            if (sum > result) {
                result = sum;
                resultStart = start;
                resultEnd = end;
            }
        }
        cout << "Case " << i + 1 << ":" << endl << result << " " << resultStart << " " << resultEnd << endl;
        if (i != n - 1) {
            cout << endl;
        }
    }
    return 0;
}
//
// Created by fen san on 2018/1/8.
//

//http://acm.hdu.edu.cn/showproblem.php?pid=1009

#include <iostream>

using namespace std;

//5 3
//7 2
//4 3
//5 2
int main() {
    int a, b;
    while (cin >> a >> b && a != -1 && b != -1) {
        float jb[b][3];
        for (int i = 0; i < b; ++i) {
            cin >> jb[i][0] >> jb[i][1];
            jb[b][2] = jb[i][1] / jb[i][0];
        }

        for (int i = 1; i < b; i++) {
            float temp = jb[i];
            int j = i - 1;
            while (temp < arr[j]) {
                arr[j + 1] = arr[j];
                j--;
                if (j == -1) {
                    break;
                }
            }
            arr[j + 1] = temp;
        }

        for (int j = 0; j < b; ++j) {
            index[]


        }


    }


    return 0;
}



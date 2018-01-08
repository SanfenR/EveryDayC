//
// Created by fen san on 2018/1/8.
//

#include <iostream>

using namespace std;

//http://acm.hdu.edu.cn/showproblem.php?pid=1008

int main() {
    int a;
    while (cin >> a && a != 0) {
        int b, c = 0, dex, n = 0;
        for (int i = 0; i < a  && cin >> b ; i ++) {
            dex = b - c;
            if (dex < 0) {
                dex = abs(dex) * 4;
            } else {
                dex = abs(dex) * 6;
            }
            n += dex;
            n += 5;
            c = b;
        }
        cout << n << endl;
    }
    return 0;
}

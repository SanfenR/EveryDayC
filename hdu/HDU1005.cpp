//
// Created by sanfen on 2017/12/5.
//

//http://acm.hdu.edu.cn/showproblem.php?pid=1005

#include <iostream>
#include <vector>

using namespace std;

int calculate(int a, int b, int one, int two) {
    return (a * one + b * two) % 7;
}

int main() {
    int a, b, n;
    while (cin >> a >> b >> n && (a + b + n)) {
        int v[50];
//        v[1] = 1;
//        v[2] = 1;
//        int i;
//        for (i = 3; i <= 48; i++)
//        {
//            v[i] = (a*v[i - 1] + b*v[i - 2]) % 7;
//        }
//        n = n % 48;
//        v[0] = v[48];
//        printf("%d\n", v[n]);

        v[0] = 1;
        v[1] = 1;
        int i;
        for (i = 2; i < 48; ++i) {
            v[i] = (a*v[i - 1] + b*v[i - 2]) % 7;
            if (v[i] == 1 && v[i-1] == 1) {
                break;
            }
            i ++;
        }
        int size = i - 1;
        cout << v[(n - 1) % size] << endl;
    }
    return 0;
}
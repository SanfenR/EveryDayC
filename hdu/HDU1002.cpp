//
// Created by sanfen on 2017/12/1.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

template <class T>
string convertToString(T value){
    stringstream ss;
    ss << value;
    return ss.str();
}

int main() {
    string a, b;
    while (cin >> a >> b) {
        int aList[a.length()];
        int bList[b.length()];

        for (int i = 0; i < a.length(); ++i) {
            aList[a.length() - 1 - i] = atoi(&a[i]);
        }

        for (int j = 0; j < b.length(); ++j) {
            bList[b.length() - 1 - j] = atoi(&a[j]);
        }

        int index;
        if (b.length() > a.length()) {
            index = (int) b.length();
        } else {
            index = (int) a.length();
        }

        int sumList[index];
        int carry = 0;
        for (int k = 0; k < index; ++k) {
            int a1 = 0, b1 = 0, sum = 0;
            if (k < a.length()) {
                a1 = a[k];
            }
            if (k < b.length()) {
                b1 = b[k];
            }
            sum = a1 + b1;
            sumList[index - 1 - k] = sum / 10 + carry;
            carry = sum % 10;
        }

        string sum;

        if (carry != 0) {
            sum += convertToString(carry);
        }

        for (int l = 0; l < index; ++l) {
            sum += convertToString(&sumList[l]);
        }
        cout << sum << endl;
    }
    return 0;
}


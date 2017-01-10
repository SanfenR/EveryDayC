//
// Created by sanfen on 2017/1/10.
//

// 题目：输入一个正数n，输出所有和为n 连续正数序列。
// 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，
// 所以输出3 个连续序列1-5、4-6 和7-8。

// 思路
// (1)对于固定的left.当前sum值小于目标Sum，则right一直后移
// (2).sum==Sum。则输出序列，且将right后移
// (3)对于固定的right.,sum>Sum时，始终将left左移动

#include"iostream"

using namespace std;


void print(const int &left, const int &right) {
    static int flag = 0;
    cout << "NO:" << ++flag << "--";
    for (int i = left; i <= right; ++i) {
        cout << i << " ";
    }
    cout << endl;
}


//void findSequence(const int &Sum) {
//    int left = 1, right = 1, sum = 1;
//    while (left <= Sum / 2) {
//        if (sum == Sum) {
//            print(left, right);
//            right++;
//            sum += right;
//        } else if (sum > Sum) {
//            sum -= left;
//            left++;
//        } else {
//            right++;
//            sum += right;
//        }
//    }
//
//}

/**
 * 简单写法
 * @param Sum
 */
void findSequence(const int& Sum) {
    int left =1, right = 1, sum = 1;
    while(left <= Sum/2) {
        while (sum > Sum) {
            sum -= left;
            left ++;
        }
        if (sum == Sum) {
            print(left, right);
        }

        right ++;
        sum += right;
    }
}


int main() {
    findSequence(15);
    return 0;
}
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

#include <list>
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
void findSequence(const int &Sum) {
    int left = 1, right = 1, sum = 1;
    while (left <= Sum / 2) {
        while (sum > Sum) {
            sum -= left;
            left++;
        }
        if (sum == Sum) {
            print(left, right);
        }

        right++;
        sum += right;
    }
}

// 题目：输入两个整数n和m，从数列1,2,3...n中随意取几个数，使其和等于m，要求列出所有的组合。


list<int> list1;

void find_factor(int sum, int n) {
    //递归出口
    if (n <= 0 || sum < 0)
        return;
    //输出找到的数
    if (sum == n) {
        list1.reverse();
        for (list<int>::iterator iter = list1.begin(); iter != list1.end(); iter++)
            cout << *iter << " + ";
        cout << n << endl;
        list1.reverse();
    }
    list1.push_front(n);
    find_factor(sum - n, n - 1);//n参与查找
    list1.pop_front();
}


int main() {
    findSequence(15);

    find_factor(15, 5);

    return 0;
}
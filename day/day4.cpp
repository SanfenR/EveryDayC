//
// Created by sanfen on 16/12/15.
//

//问题描述：一个整型数组里除了两个数字之外，其他的数字都出现了两次。
// 请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

//
//  1.思路
// (1)全部元素异或，结果一定不为0，且结果为只出现1次的元素的异或。
// (2)以第结果的第一个非0位(假设第N位)来看，所有元素在该位置的0,1都出现了奇数次。
// (3)以N为基准，为0的分为一组，为1的分为一组。则这两个数分别分到2组。
// (4)对这两组分别异或，结果即为所求。




#include <iostream>
#include <stdlib.h>

using namespace std;


//函数功能 ： 找出数组中两个只出现一次的数字
//函数参数 ： arr为源数组，len为数组元素个数，result用来存放结果
void function1(int *arr, int len, int *result) {
    int i, all = 0, flag = 1;
    for (int i = 0; i < len; ++i) { //所有数异或
        all ^= arr[i];
    }
    while (!all & flag) {
        flag <<= 1;
    }
    result[0] = result[1] = 0;
    //利用过滤位区分
    for (i = 0; i < len; i++) {
        if (flag & arr[i])
            result[0] ^= arr[i];
        else
            result[1] ^= arr[i];
    }
}

int main() {
    int arr[] = {1, 2, 2, 1, 3, 4};
    int result[2];
    function1(arr, 6, result);
    for (int i = 0; i < 2; ++i) {
        cout << result[i] << endl;
    }
}

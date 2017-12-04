//
// Created by sanfen on 2016/12/23.
//

// 题目：在数组中，数字减去它右边的数字得到一个数对之差。求所有数对之差的最大值。
// 例如在数组{2, 4, 1, 16, 7, 5, 11, 9}中，
// 数对之差的最大值是11，是16 减去5 的结果。


// 思路
//Solution1: 将其转换成求最大子数组问题。引入辅助数组diff，长度为n-1。diff[i]=dif[i]-diff[i+1]。
// 求出最大子数组以及位置low,high。则对应最大差为data[low]-data[high+1]。
//Solution2: 使用动态规划法。假设data[i]减去某个数，其最大的数对差为currentMax。
// 则data[i-1]的最大数对差为data[i-1]-data[i]和data[i-1]-data[i]+currentMax中的较大的那一个。
// 从后往前遍历数组，记录最大的currentMax以及对应的low、high输出即可。
//时间复杂度O(n),空间复杂度O(1)。

#include"iostream"

using namespace std;

void fun(int data[], int size, int &low, int &high) {

    int max = data[size - 1] - data[size - 2];//最大的数对差
    int currentMax = data[size - 1] - data[size - 2];//当前的数对差

    int l = size - 2;
    int h = size - 1;
    low = l;//被减数位置
    high = h;//减数位置
    for (int i = size - 3; i >= 0; i--) {
        if (currentMax > 0) {
            currentMax = data[i] - data[i + 1] + currentMax;
            l--;
        } else {
            currentMax = data[i] - data[i + 1];
            l = i;
            h = i + 1;
        }
        if (currentMax > max) {
            low = l;
            high = h;
            max = currentMax;
        }
    }
}

void main() {
    int data[] = {2, 4, 1, 16, 7, 5, 11, 9};
    int low, high;
    fun(data, sizeof(data) / sizeof(int), low, high);
    cout << "the max is " << data[low] - data[high] << endl;

}
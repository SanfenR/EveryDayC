//
// Created by sanfen on 16/12/20.
//

// 题目：输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
// 例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”。

//
// 最简单的。设source长n，key 长m(n>>m)，则使用简单的遍历查找需要n*m次(n个字符，查找m次)，且每次删除对应元素需要O(1)时间(元素移动)。时间复杂度为O(n.^2);
// 以下思路。查找时间复杂度为O(n),删除时间复杂度为O(n)。即O(n)的时间内完成。
// 1)建立长度为256(char元素总数)的hash数组(类似基排序)，遍历key。即需要在source中删除的字符在hashtable上不为0。复杂度O(m)。
// 2)设定指针 temp和needDelete，初始化指向source.
// 3)temp用来遍历source，任何时候指向不需要删除的字符。needDelete指向当前需要删除的第一个字符。
// 4)使用间接删除法。即将temp的值赋给source。
// 5)任何一轮循环。needDelete--temp-1的字符都可以被删除(即替代)。temp之前不需要删除的字符，都已经挪到needDelete之前。
// 6）以temp为空位结束条件。最后给needDelete赋空。
// 整体思路,从第一个删除的位置开始，依次把后面不需要删除的字符向前赋值

#include <stdlib.h>
#include <iostream>

using namespace std;

char *deleteStr(char *source, const char *key) {
    if (!source || !key)
        return NULL;
    const char *temp = key;
    //static int hashTable[256];
    int *hashTable = new int[256];
    memset(hashTable, 0, 256 * sizeof(int));

    while (*temp)
        hashTable[*temp++]++;
    temp = source;
    char *needDelete = source;
    while (*temp) {
        if (!hashTable[*temp]) {//不需要删除的字符，前移赋值
            *needDelete = *temp;
            needDelete++;
        }
        temp++;
    }
    *needDelete = '\0';
    delete[]hashTable;
    return source;
}


int main() {

    char *source = new char[255];
    string s = "hello";
    strcpy(source ,s.c_str());

    char * key = new char[255];
    string k  = "el";
    strcpy(key, k.c_str());


    char * del = deleteStr(source, key);

    cout << del << endl;




    delete[] source;
    source = NULL;

    delete[] key;
    key = NULL;

    return 0;
}
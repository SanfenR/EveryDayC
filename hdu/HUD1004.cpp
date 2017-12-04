//
// Created by fen san on 2017/12/4.
//

//http://acm.hdu.edu.cn/showproblem.php?pid=1004

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

void max(int n, vector<string> &v, map<string, int> &m) {
    for (int i = 0; i < n; ++i) {
        auto mc = m.find(v[i]);
        if(mc->second == 0) {
            m[v[i]] = 1;
        } else {
            m[v[i]] ++;
        }
    }
}

int main() {
    int n = 0;
    while (cin >> n) {
        vector<string> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        map<string, int> m;
        max(n, v, m);

        string more = v[0];
        int index = 1;

        for (auto &i : m) {
            if(i.second > index) {
                more = i.first;
                index = i.second;
            }
        }
        cout << more << endl;
    }
    return 0;
}
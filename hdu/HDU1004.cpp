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
    int n;
    while (cin >>n && n != 0) {
        map<string, int> m;
        string sca;
        for (int i = 0; i < n; ++i) {
            cin >> sca;
            auto mc = m.find(sca);
            if(mc->second == 0) {
                m[sca] = 1;
            } else {
                m[sca] ++;
            }
        }
        int index = 1;
        string more = m.begin()->first;
        for(map<string,int >::iterator iter = m.begin(); iter != m.end(); iter.operator++()) {
            if(iter->second > index) {
                more = iter->first;
                index = iter->second;
            }
        }
        cout << more << endl;
        m.clear();
    }
}
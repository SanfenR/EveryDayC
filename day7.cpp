//
// Created by sanfen on 16/12/22.
//

// 题目：输入一个整数和一棵二元树。从树的根结点开始往下访问一直到叶结点所经过的所有结点形成一条路径。打印出和与输入整数相等的所有路径。
// 例如输入整数22 和如下二元树

//      10
//     /  \
//    5   12
//   / \
//  4   7

//则打印出两条路径：10, 12 和10, 5, 7。

//思路
// 使用递归和栈结构。将当前路径保留在vector中。
// (1)对于空节点，返回false；
// (2)对于叶子节点，判断当前和是否为给定值，是则遍历输出栈中保存路径且返回true，否则返回false。
// (3) 对于非叶子节点，将当前根节点入栈，先后递归左、右子树。且递归完后，要弹出栈中保存的当前路径。

#include"iostream"
#include"vector"
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};


bool decision(Node * head, int sum, vector<int> &v){
    if(!head){
        return false;
    } else if (!head->left && !head->right){
        sum -= head->value;
        if(sum == 0){
            for (int i = 0; i < v.size(); i++) {
                cout << v[i] << endl;
            }
            cout << head->value << "\n" << endl;
        }
        return false;
    } else {
        v.push_back(head->value);
        sum -= head->value;
        bool left = decision(head->left, sum, v);
        bool right = decision(head->right, sum, v);
        v.pop_back();
        if (left || right){
            return true;
        }
    }
    return false;

}

int main(){
    Node n4={4,NULL,NULL};
    Node n5={7,NULL,NULL};
    Node n3={12,NULL,NULL};
    Node n2={5,&n4,&n5};
    Node n1={10,&n2,&n3};

    vector<int> v;
    decision(&n1,22,v);
    return 0;
}
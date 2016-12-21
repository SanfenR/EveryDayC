//
// Created by sanfen on 16/12/21.
//

// 题目：输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只调整指针的指向。比如将二元查找树
//      10
//     / \
//    6   14
//   / \  / \
//  4  8 12 16
// 转换成双向链表4=6=8=10=12=14=16

#include"iostream"
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

bool createList(Node* head, Node* &left, Node* &right){
    left = head;
    right = head;
    if(!head){
        return false;
    } else {
        Node *l1, *r1, *l2, *r2;
        l1 = NULL;
        r1 = NULL;
        l2 = NULL;
        r2 = NULL;
        if(createList(head->left, l1, r1)){
            head->left = r1;
            r1->right = head;
            left = l1;
        }

        if(createList(head->right, l2, r2)){
            head->right=l2;
            l2->left=head;
            right = r2;
        }
        return true;
    }
}


int main(){
    Node n4={4,NULL,NULL};
    Node n5={8,NULL,NULL};
    Node n6={12,NULL,NULL};
    Node n7={16, NULL, NULL};
    Node n2={6,&n4,&n5};
    Node n3={14,&n6,&n7};
    Node n1={10,&n2,&n3};

    Node*Left=NULL;
    Node*Right=NULL;

    createList(&n1,Left,Right);

    while(Left){
        cout<<Left->value<<endl;
        Left=Left->right;
    }

    return 0;
}
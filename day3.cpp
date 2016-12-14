//
// Created by sanfen on 16/12/14.
//

#include <iostream>
#include <stdlib.h>

using namespace std;


// 假设链表......---A--B--C--D....，要删除B。一般的做法是遍历链表并记录前驱节点，
// 修改指针，时间为O(n)。删除节点的实质为更改后驱指针指向。
// 这里，复制C的内容至B(此时B，C同时指向D)，删除节点C，即达到间接删除节点B的目的。
// 倘若B是链尾节点。则需要线性遍历寻找前驱节点。
// 以上思路，时间复杂度为O(1)。

struct ListNode {
    int m_nKey;
    ListNode *m_pNext;
};

void deleteNode(ListNode* pListHead, ListNode* pToBeDeleted) {
    if (!pListHead || !pToBeDeleted) {
        return;
    }

    if (pListHead == pToBeDeleted){
        delete pListHead;
        pListHead = NULL;
        pToBeDeleted = NULL;
    } else if (pToBeDeleted->m_pNext != NULL) {
        ListNode *pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nKey = pNext->m_nKey;
        pToBeDeleted->m_pNext = pNext->m_pNext;
        delete[] pNext;
        pNext = NULL;
    } else {
        ListNode* pNode = pListHead;
        while(pNode->m_pNext != pToBeDeleted) {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}


void printList(ListNode* listHead){
    ListNode* pNode = listHead;
    while (pNode->m_pNext != NULL){
        cout << pNode->m_nKey << endl;
        pNode = pNode->m_pNext;
    }
    cout << pNode->m_nKey << endl;
}

int main(){
    ListNode *head = new ListNode();
    ListNode *next1 = new ListNode();
    ListNode *next2 = new ListNode();
    ListNode *end = new ListNode();

    head->m_nKey = 1;
    head->m_pNext = next1;

    next1->m_nKey = 2;
    next1->m_pNext = next2;

    next2->m_nKey = 3;
    next2->m_pNext = end;

    end->m_nKey = 4;
    end->m_pNext = NULL;

    printList(head);

    deleteNode(head, next1);

    printList(head);

}


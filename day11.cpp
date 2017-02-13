//
// Created by sanfen on 2017/2/13.
//

#include "day.h"


// 合并已经排序的2条链表



struct ListNode {
    int value;
    ListNode* next;
};


ListNode * mergeList(ListNode* list1, ListNode* list2){
    if(!list1) return list2;
    if(!list2) return list1;
    ListNode* head;
    ListNode* tail = new ListNode();
    head = tail;
    while(list1 || list2) {
        if(!list2 || list1->value < list2->value) {
            tail->next = list1;
            tail=tail->next;
            list1=list1->next;
        } else {
            tail->next=list2;
            tail=tail->next;
            list2=list2->next;
        }
    }

    return head->next;

}


int main() {
    ListNode* list1 = new ListNode();
    ListNode* node1 = new ListNode();
    ListNode* node2 = new ListNode();
    ListNode* node3 = new ListNode();
    list1->value = 1;
    list1->next = node1;
    node1->value = 3;
    node1->next = node2;
    node2->value = 5;
    node2->next = node3;
    node3->value = 7;


    ListNode* list2 = new ListNode();
    ListNode* node21 = new ListNode();
    ListNode* node22 = new ListNode();
    ListNode* node23 = new ListNode();
    list2->value = 1;
    list2->next = node21;
    node21->value = 3;
    node21->next = node22;
    node22->value = 5;
    node22->next = node23;
    node23->value = 7;


    ListNode* p =  mergeList(list1, list2);

    while(p) {
        cout << p->value << endl;
        p = p->next;
    }
    return 0;
}
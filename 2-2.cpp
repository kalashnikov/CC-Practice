#include<iostream>
// 
// Find teh n-th last element in linked list 
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};


ListNode *lastN(ListNode* list, int num){
    if(list==nullptr) return nullptr;
    ListNode *ptr = list, *tptr = list;
    while(ptr->next!=nullptr&&num!=0) ptr=ptr->next,num--;
    if(num!=0) return nullptr;
    while(ptr) {
        ptr=ptr->next;
        tptr=tptr->next;
    }
    return tptr;
}

int main(){
  
    ListNode* itr;

    ListNode* list1 = new ListNode(1);
    ListNode* lnptr = new ListNode(2);
    list1->next = lnptr;
    lnptr->next = new ListNode(3);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(4);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(5);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(3);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(2);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(4);
    lnptr = lnptr->next;

    lnptr->next = nullptr;

    itr = list1;
    printf("Before: ");
    while(itr!=nullptr){
        printf("%d ",itr->val);
        itr = itr->next; 
    }
    printf("\n");

    printf("%d\n",lastN(list1,3)->val);

    return 0;
}

#include<iostream>
// 
// Reverse Order Linked List Number Sum 
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};


ListNode *add(ListNode *list1, ListNode*list2){
    if(list1==nullptr || list2==nullptr) return nullptr;

    int m=0, n=0;
    int tmp = 0, carry = 0;
    ListNode *ptr1=list1, *ptr2=list2;
    while(ptr1->next!=nullptr) { ptr1=ptr1->next;m++; }
    while(ptr2->next!=nullptr) { ptr2=ptr2->next;n++; }
    
    if(n>m) return add(list2, list1);
    else { 
        ptr1=list1;
        ptr2=list2;
        while(ptr2) { 
            tmp       = ptr1->val + ptr2->val + carry;
            carry     = tmp/10;
            ptr1->val = tmp%10;
            ptr1      = ptr1->next;
            ptr2      = ptr2->next;
        }
        
        tmp       = ptr1->val + carry;
        carry     = tmp/10;
        ptr1->val = tmp%10;
        while(carry==1&&ptr1->next!=nullptr){
            ptr1      = ptr1->next;
            tmp       = ptr1->val + carry;
            carry     = tmp/10;
            ptr1->val = tmp%10;
        }
        if(carry==1){ 
            ptr1->next = new ListNode(1);
            ptr1->next->next = nullptr;
            carry = 0;
        }
        
        return list1;
    }
}

int main(){
  
    ListNode* itr;

    ListNode* list1 = new ListNode(2);
    ListNode* lnptr = new ListNode(0);
    list1->next = lnptr;
    lnptr->next = new ListNode(3);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(2);
    lnptr = lnptr->next;
    lnptr->next = nullptr;

    ListNode* list2 = new ListNode(8);
    lnptr = new ListNode(9);
    list2->next = lnptr;
    lnptr->next = new ListNode(6);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(7);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(9);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(9);
    lnptr = lnptr->next;
    lnptr->next = nullptr;

    itr = list1;
    printf("After: ");
    while(itr!=nullptr){
        printf("%d ",itr->val);
        itr = itr->next; 
    }
    printf("\n");
    
    itr = list2;
    printf("After: ");
    while(itr!=nullptr){
        printf("%d ",itr->val);
        itr = itr->next; 
    }
    printf("\n");

    lnptr = add(list1, list2); 

    itr = lnptr;
    printf("After: ");
    while(itr!=nullptr){
        printf("%d ",itr->val);
        itr = itr->next; 
    }
    printf("\n");

    return 0;
}

#include<iostream>
// 
// Remove duplicateds from an unsorted linked list 
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};


void removeDup(ListNode* list){
    if(list==nullptr) return ;
    
    int i,j;
    ListNode *ptr, *tptr, *pre_ptr, *ttptr;
   
    ptr = list;
    while(ptr->next!=nullptr){
        pre_ptr = ptr;
        tptr    = ptr->next;
        while(pre_ptr!=nullptr && tptr!=nullptr){
            if(tptr->val==ptr->val){
                pre_ptr->next = tptr->next;
                delete tptr;
                tptr = pre_ptr->next;
            } else { 
                pre_ptr = tptr;
                tptr    = tptr->next;
            }
        }
        ptr = ptr->next;
    }
    return ;
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

    removeDup(list1);
    
    itr = list1;
    printf("After: ");
    while(itr!=nullptr){
        printf("%d ",itr->val);
        itr = itr->next; 
    }
    printf("\n");

    return 0;
}

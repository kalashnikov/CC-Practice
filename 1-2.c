#include<stdio.h>

void swap(char *c, char *d){
    *c^=*d;
    *d^=*c;
    *c^=*d;
}

void reverseString(char a[]){
    char t;
    int i=0,j=0;
    while(a[j]) j++;
    j--;
    while(i<j){
        swap(&(a[i++]),&(a[j--]));
    }
}

int main(){
    int i;
    char a[]="abcdefg";
    int size=sizeof(a)/sizeof(a[0]);
    printf("%s\n",a);
    reverseString(a);
    printf("%s\n",a);
    return 0;
}

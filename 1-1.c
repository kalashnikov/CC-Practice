#include<stdio.h>

//
// 1.1 
// Implement an algorithm to determine if a string has all unique characters. 
// What if you can not use additional data structures?
// 2014.6.21
//
// Need to check the string type 
// UTF or unicode encoding string.
//
// ASCII or [a-zA-Z]
//

int checkUnique(char a[], int size){
    if (size<1) return 1;
    
    int i=0,j;
    while(i<size){
        j=i+1;
        while(j<size){
            if(a[i]==a[j++])
                return 0;
        }
        i++;
    }
    return 1;
}

// For ASCII, use int[8] 
// Use v/32 and v%32 for check
int isUnique2(char s[],int len)
{
    int a[8];
    memset(a, 0, sizeof(a));
    for(int i=0; i < len; ++i)
    {
        int v = (int)s[i];
        int idx = v/32, shift=v%32;
        if(a[idx] & (1 << shift)) return 0;
        a[idx] |= (1 << shift);
    }
    return 1;
}

int main(){
    char a[]="arbdyY";
    int size=sizeof(a)/sizeof(a[0]);
    printf("%d\n",checkUnique(a,size));
    printf("%d\n",isUnique2(a,size));
    return 0;
}

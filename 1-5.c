#include<stdio.h>
#include<stdlib.h> // for malloc
//
// 1-5 Replace Space with %2d
//

char *replaceSpace(char a[], int size){
    char *ptr=a;
    int newSize = size;
    while(*ptr)
        if(*ptr++==' ')
            newSize+=2;

    //printf("%d %d\n",size, newSize);

    char *b=malloc(sizeof(char)*newSize+1);
    char *ptrb=b;
    ptr=a;
    while(*ptr){
        if(*ptr==' '){
            *ptrb='%';
            *(ptrb+1)='2';
            *(ptrb+2)='d';
            ptrb+=3;
            ptr++;
        } else { 
            *ptrb++=*ptr++;
        } 
    }
    *ptrb='\0';
    return b;
}

int main(){
    char a[]="a b c d";
    int size=sizeof(a)/sizeof(a[0]);
    printf("%s\n",replaceSpace(a,size));
    return 0;
}

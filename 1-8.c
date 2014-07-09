#include<stdio.h>

int isSubstring(char a[], char b[]){
    int i=0,j=0;
    while(*(a+i)){
        j = 0;
        char *ptra = a+i;
        while(*(ptra+j)==*(b+j)) j++;
        if(*(b+j)=='\0') return 1;
        else i++;
    }
    return 0;
}

// Check rotation by using isSubstring(a+a,b)
int isRotation(char a[], char b[]){

    int i,size=0;

    // Get size
    while(*(a+size)) size++;

    // Create a+a string
    char c[2*size+1];
    for(i=0;i<size*2;i++)
        c[i]=a[i%size];
    c[2*size]='\0';
    
    return isSubstring(c,b);
}

int main(){
    char a[]="aabbcc";
    char b[]="caabbc";
    printf("%d\n",isRotation(a,b));
    return 0;
}

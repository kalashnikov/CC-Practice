#include <stdio.h>
// 
// 1-4 Anagrams
// 2014.6.22
//  

#define swap(a,b,t) ((t)=(a),(a)=(b),(b)=(t))
int partition(char a[], int lo, int hi){
    char t;
    char pivot = a[(lo+hi)/2];
    while(lo<=hi){
        while(a[lo]<pivot) lo++;
        while(pivot<a[hi]) hi--;
        if(lo<=hi){
            swap(a[lo],a[hi],t);
            lo++;hi--;
        }
    }
    return lo;
}

void qsort(char a[], int lo, int hi){
    int index = partition(a,lo,hi);
    if( lo < index-1 )
        qsort(a, lo, index-1);
    if( index < hi ) 
        qsort(a, index, hi);
}

int com(const char a[],const char b[]){

    int ca=0,cb=0;
    const char *pa=a;
    const char *pb=b;
    while(*pa++) ca++;
    while(*pb++) cb++;
    if (ca!=cb) return 0;

    while(*a){
        if (*a++ != *b++){
            return 0;
        }
    }
    return 1;
}

int main(){
    int i;
    //int a[]={7,44,52372,1432,8486,382,94,2,1525};
    char a[]="abscd";
    char b[]="bscade";
    int size=sizeof(a)/sizeof(a[0]);
    qsort(a,0,size-2);
    printf("%s\n",a);
    qsort(b,0,size-2);
    printf("%s\n",b);
    printf("%d\n",com(a,b));
    return 0;
}


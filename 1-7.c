#include<stdio.h>
#include<string.h>
#define S 4
// 
// Reset Column & Row if value is zero 
// Ref: http://blog.csdn.net/wangxiaojun911/article/details/18939871 
//

void resetByZero(int a[][S]){
    int i,j,t;
    int rowset=0;
    int colset=0;

    for(i=0;i<S;i++)
        if(a[i][0]==0){
            colset=1;
            break;
        }
   
    for(j=0;j<S;j++)
        if(a[0][j]==0){
            rowset=1;
            break;
        }

    // Store flag in first row/col
    // O(n^2)
    for(i=0;i<S;i++){
        for(j=0;j<S;j++){
            if(a[i][j]==0){
                a[i][0]=0;
                a[0][j]=0;
            }
        }
    }
   
    // Scan from inner matrix 
    // O(n^2)
    for(i=1;i<S;i++)
        for(j=1;j<S;j++)
            if(a[i][0]==0 || a[0][j]==0)
                a[i][j]=0;

    if(colset)
        for(i=0;i<S;i++)
            a[i][0]=0;
    
    if(rowset)
        for(j=0;j<S;j++)
            a[0][j]=0;
}

int main(){
    int i,j;
    int a[S][S]={{1,0,3,4},
                 {5,6,7,8},
              {9,0,11,12},
             {13,14,15,16}};

    resetByZero(a);

    for(i=0;i<S;i++){
        for(j=0;j<S;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

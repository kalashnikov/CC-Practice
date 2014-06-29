#include<stdio.h>
#define S 4
// 
// Counter-clock rotate martix by 90 degree
// Ref: http://hawstein.com/posts/1.6.html
//

void rotate(int a[][S]){
    int i,j,t;

    // Mirror on Axis
    for(i=0;i<S;i++){
        for(j=i+1;j<S;j++){
            t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
        }
    }

    // Swap by Line
    for(i=0;i<S/2;i++){
        for(j=0;j<S;j++){
            t=a[i][j];
            a[i][j]=a[S-1-i][j];
            a[S-1-i][j]=t;
        }
    }
}

int main(){
    int i,j;
    int a[S][S]={{1,2,3,4},
                 {5,6,7,8},
              {9,10,11,12},
             {13,14,15,16}};

    rotate(a);

    for(i=0;i<S;i++){
        for(j=0;j<S;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

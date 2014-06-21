#include<stdio.h>

// 
// Remove Duplicate Character in Non-Sorted Char Array
// In-line replace
//
void removeDuplicate(char a[])
{
    int i=0,j=1,k=0,l;
    while(a[k++]);
    k--;
    if(k<2) return;

    // O(n^2)
    for(i=0;i<k;i++){
        // Swap non-null char to front
        if(!a[i]){
            l=i+1;
            while(l<k){
                if (a[l]){
                    a[i]=a[l];
                    a[l]='\0';
                    break;
                }
                l++;
            }
        }
           
        // Clear duplicate char
        j=i+1;
        while(j<k){
            if(a[i]==a[j])
                a[j]='\0';
            j++;
        }
    }

    a[i]='\0';
}

int main(){
    char a[]="aaesgesbsesdgde";
    printf("%s\n",a);
    removeDuplicate(a);
    printf("%s\n",a);
    return 0;
}

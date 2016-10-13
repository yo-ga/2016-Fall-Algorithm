#include<bits/stdc++.h>
using namespace std;
int num,len,swp,tmp;
int bub[50];
int main(){
    scanf("%d",&num);
    for(int n=0;n<num;n++){
        swp=0;
        scanf("%d",&len);
        for(int l=0;l<len;l++){
            scanf("%d",&bub[l]);
        }
        for(int i=0;i<len;i++){
            for(int j=1;j<len-i;j++){
                if(bub[j-1]>bub[j]){
                    swp++;
                    tmp=bub[j-1];
                    bub[j-1]=bub[j];
                    bub[j]=tmp;
                }
            }
        }
        printf("Optimal swapping takes %d swaps.\n",swp);
    }
    return 0;
}

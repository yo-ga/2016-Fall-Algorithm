#include<bits/stdc++.h>
#define MAX_DIGIT 2500
using namespace std;
int num;
int m,n;
int bm[MAX_DIGIT],bn[MAX_DIGIT];
void printBig(int *num){
    bool zero = true;
    for(int i=MAX_DIGIT-1;i>=0;i--){
        if(num[i]==0 && zero)
            continue;
        zero = false;
        printf("%d",num[i]);
    }
    printf("\n");
}
void pow2(int *num,int m){
    if(m==0)
        return;
    for(int i=0;i<m;i++){
        for(int j=0;j<MAX_DIGIT-1;j++){
            num[j]*=2;
        }
        num[MAX_DIGIT-1]*=2;
        for(int j=0;j<MAX_DIGIT-1;j++){
            if(num[j]>9){
                num[j+1]+=num[j]/10;
                num[j]%=10;
            }
        }
    }
}
void plusBig(int* m,int* n){
    for(int j=0;j<MAX_DIGIT-1;j++){
        m[j]+=n[j];
        if(m[j]>9){
            m[j+1]+=m[j]/10;
            m[j]%=10;
        }
    }
    m[MAX_DIGIT-1]+=n[MAX_DIGIT];
}
int main(){
    scanf("%d",&num);
    for(int t=0;t<num;t++){
        scanf("%d %d",&m,&n);
        bm[0]=1;
        bn[0]=1;
        for(int i=1;i<MAX_DIGIT;i++){
            bm[i]=0;
            bn[i]=0;
        }
        //printBig(bm);
        pow2(bm,m);
        //printBig(bn);
        pow2(bn,n);
        plusBig(bm,bn);
        printBig(bm);
    }
    return 0;
}

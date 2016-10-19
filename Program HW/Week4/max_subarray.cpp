#include<bits/stdc++.h>
using namespace std;
int n,num,tem,Max;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        tem=0;
        Max=0;
        for(int j=0;j<10;j++){
            scanf("%d",&num);
            tem+=num;
            if(tem>Max)
                Max=tem;
            else if(tem<0){
                Max=0;
                tem=0;
            }
        }
        printf("%d",Max);
    }
    return 0;
}

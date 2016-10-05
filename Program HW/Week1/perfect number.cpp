#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int num;
    unsigned long all,n;
    scanf("%d",&num);
    for(int i = 0;i<num;i++){
        all = 1;
        scanf("%d",&n);
        unsigned long per=n;
        for(unsigned long i=2;i<sqrt(per);i++){
            if(per%i==0)
                if(per/i>i)
                    all += per/i+i;
                else
                    all += i;
        }
        if(all==per)
            printf("%d ",all);
    }
}

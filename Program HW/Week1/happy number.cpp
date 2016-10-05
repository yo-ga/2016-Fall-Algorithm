#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    scanf("%d",&num);
    for(int i = 0;i<num;i++){
        int n;
        scanf("%d",&n);
        while(n>9){
            int temp =0;
            while(n>0){
                temp+=(n%10)*(n%10);
                n/=10;
            }
            n = temp;
        }
        printf("%s\n",n==1?"Happy":"Not Happy");
    }
}

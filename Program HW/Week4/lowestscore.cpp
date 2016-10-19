#include <bits/stdc++.h>
using namespace std;
int k[100005];
int main(){
    int n,num,p_a,p_b,pivo;
    scanf("%d",&n);
    for(int s=0;s<n;s++){
        scanf("%d",&num);
        for(int m=0;m<num;m++){
            scanf("%d",&k[m]);
        }
        for(int m=0;m+1<num;m++){
            if(k[m+1]-k[m]<0){
                pivo=m;
                break;
            }
        }
        p_a=0;
        p_b=pivo+1;
        for(int m=0;m<3;m++){
            if(p_a<=pivo&&p_b<num)
                if(k[p_a]<k[p_b]){
                    printf("A");
                    p_a++;
                }
                else{
                    printf("B");
                    p_b++;
                }
            else if(p_a>pivo&&p_b>=num)
                break;
            else if(p_a>pivo){
                printf("B");
                p_b++;
            }
            else{
                printf("A");
                p_a++;
            }
        }
        printf("\n");
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    int box[6],all,need;
    while(scanf("%d%d%d%d%d%d",&box[0],&box[1],&box[2],&box[3],&box[4],&box[5])){
        if(box[0]+box[1]+box[2]+box[3]+box[4]+box[5]==0)
            break;
        all=0;
        for(int i=0;i<6;i++){
            all+=box[i]*(i+1)*(i+1);
        }
        need=all/36;
        if(all%36!=0)
            need++;
        printf("%d\n",need);
    }
    return 0;
}

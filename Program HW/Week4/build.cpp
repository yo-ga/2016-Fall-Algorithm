#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int p,n;
int main(){
    scanf("%d",&p);
    for(int i=0;i<p;i++){
        scanf("%d",&n);
        int floor[n];
        for(int f=0;f<n;f++){
            scanf("%d",&floor[f]);
        }
        for(int s=0;s<n-1;s++){
            for(int t=0;t<n-s-1;t++){
                if(abs(floor[t])<abs(floor[t+1])){
                    int tem= floor[t];
                    floor[t]=floor[t+1];
                    floor[t+1]=tem;
                }
            }
        }
        for(int f=0;f<n;f++){
            printf("%d ",floor[f]);
        }
        printf("\n");
        int tem=0;
        int Max=0;
        bool pivo=(floor[0]>0)?false:true;
        for(int f=0;f<n;f++){
            if((floor[f]>0)!=pivo)
                tem++;
            pivo=(floor[f]<0)?false:true;
        }
        printf("%d\n",(Max<tem)?tem:Max);
    }
    return 0;
}

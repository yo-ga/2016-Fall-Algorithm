#include<bits/stdc++.h>
using namespace std;
int s[102][2];
char str[102][55];
int main(){
    int num,len,ged,sum,tem;
    scanf("%d",&num);
    for(int n=0;n<num;n++){
        scanf("%d %d",&len,&ged);
        for(int g=0;g<ged;g++){
            scanf("%s",&str[g]);
        }
        for(int g=0;g<ged;g++){
            sum=0;
            for(int l=0;l<len-1;l++){
                for(int p=l;p<len;p++){
                    if(str[g][l]>str[g][p]){
                        sum++;
                    }
                }
            }
            s[g][0]=g;
            s[g][1]=sum;
        }
        for(int g=0;g<ged-1;g++){
            for(int h=0;h<ged-1-g;h++){
                if(s[h][1]>s[h+1][1]){
                    tem=s[h][1];
                    s[h][1]=s[h+1][1];
                    s[h+1][1]=tem;
                    tem=s[h][0];
                    s[h][0]=s[h+1][0];
                    s[h+1][0]=tem;
                }
            }
        }
        for(int g=0;g<ged;g++){
            printf("%s\n",str[s[g][0]]);
        }
        printf("\n");
    }
}

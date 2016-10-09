#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define MAX_PRIME 40000
static int prime[MAX_PRIME];
void make_prime(){
	prime[0]=2;
	for(int i=3,j =1;j<MAX_PRIME;i++){
        for(int s=0;s<j;s++){
            if(i%prime[s]!=0){
                if(s==j-1){
                    prime[j]=i;
                    j++;
                }
            }
            else
                break;
        }
    }
	return;
}
void print_prime(long long num,int innum[MAX_PRIME]){
	printf("%lld=",num);
	int n=1,p=0,pt;
	bool first=true;
	for(int i=0;i<MAX_PRIME;i++){
		if(innum[i]!=0){
			printf("%s%d%s",(first?"":"*"),(prime[i]),((innum[i]!=1)?"^":""));
            if(innum[i]>1)
                printf("%d",innum[i]);
			first=false;
		}
	}
	printf("\n");
	return;
}

int main(){
	make_prime();
	int n_prime[MAX_PRIME];
	long long tem,n =0,i;
	scanf("%lld",&n);
    tem=n;
    i=0;
    for(int k=0;k<MAX_PRIME;k++){
        n_prime[k]=0;
    }
    while(tem!=1){
        if(tem%prime[i]==0){
            tem/=prime[i];
            n_prime[i]++;
            if(tem%prime[i]==0){
                i--;
            }
        }
        i++;
    }
    print_prime(n,n_prime);
	return 0;
}

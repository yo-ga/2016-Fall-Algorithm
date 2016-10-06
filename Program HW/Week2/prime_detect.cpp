#include <bits/stdc++>
#include <quene>
using namespace std;
global int prime[130];
void make_prime(){
	for(int i =2,j=0;j<130;j++){
		k=2;
		while(k*k<=i){
			if(i%k==0)
				break;
			k++;
		}
		if(k*k>i){
			prime[j]=i;
		}
	}
	return;
}
void print_prime(int num;int innum[130]){
	printf("%d=",num);
	int n=1,p=0,pt;
	bool first=true;
	for(int i=0;i<130;i++){
		if(innum[i]!=0){
			printf("%s%d%s%d\n",(first?"":"*"),prime[i],(innum[i]!=1?"^":""),(innum[i]>1?innum[i]) );
			first=false;
		}
	}
	return;
}
int main(){
	make_prime();
	int n_prime[130];
	int tem,n =0,i;
	while(scanf("%d",&n)){
		tem=n;
		i=0;
		n_prime={};
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
		print_prime(n_prime);
	}
	return 0;
}
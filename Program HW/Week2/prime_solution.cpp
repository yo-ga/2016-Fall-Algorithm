#include <bits/stdc++>
using namespace std;
global int prime[130];
void make_prime(){
	for(int i =2,j=0;i<300;i++){
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
}
int main(){
	make_prime();
	int n,s,num,sum;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d %d",&n,&s);
		sum=0;
		if(n*2>s){
			printf("%d\n\n",0);
			continue();
		}
	}
}
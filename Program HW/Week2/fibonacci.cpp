#include <bits/stdc++.h>
using namespace std;
long fibonacci(long n){
	if(n==0 || n==1)
		return n;
	else
		return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
	int num=0;
	long fibo=0;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%lld",&fibo);
		printf("%lld\n",fibonacci(fibo));
	}
	return 0;
}
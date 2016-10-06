#include <bits/stdc++.h>
using namespace std;
long fibonacci(long n){
	long ans =0;
	if(n==0 || n==1)
        ans=n;
	else
		ans= fibonacci(n-1)+fibonacci(n-2);
    return ans;
}
int main(){
	long num=1;
	long fibo;
	scanf("%ld",&num);
	for(int i=0;i<num;i++){
		scanf("%ld",&fibo);
		printf("%ld\n",fibonacci(fibo));
	}
	return 0;
}

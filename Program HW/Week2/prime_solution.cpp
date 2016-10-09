#include <bits/stdc++.h>
#include <stack>
using namespace std;
void make_prime(bool* prime,int len){
    prime[0]=false;
	prime[1]=false;
	for(int i =2;i<len-1;i++){
		for(int j=i+1;j<len;j++){
            if(prime[j]){
                if(j%i==0){
                    prime[i]=false;
                }
            }
		}
	}
	return;
}
void print_stack(stack<int> sol){
    stack<int> temp;
    int num;
    while(!sol.empty()){
        num=sol.top();
        sol.pop();
        printf("%d%s",num,(sol.empty()?"\n":" "));
        temp.push(num);
    }
    while(!temp.empty()){
        num=temp.top();
        temp.pop();
        sol.push(num);
    }
}
int main(){
	int n,s,num,sum;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d %d",&n,&s);
        bool prime[s+1];
        for (int x=0;x<s+1;x++){
            prime[x]=true;
        }

        printf("\n");
	}
	return 0;
}

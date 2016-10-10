#include <bits/stdc++.h>
#include <stack>
using namespace std;
int make_prime(bool* prime,int len){
    int num=0;
    prime[0]=false;
	prime[1]=false;
	for(int i =2;i<len-1;i++){
		int j=2;
		while(j*i<len){
            prime[j*i]=false;
            j++;
        }
	}
	for(int i=0;i<len;i++)
        if(prime[i])
            num++;
	return num;
}
bool check_stack(stack<int> sol,int sum){
    int tem=0,t=0;
    bool small = true;
    while(!sol.empty()){
        if(t>sol.top())
            small=false;
        t=sol.top();
        sol.pop();
        tem+=t;
    }
    return sum==tem && small;
}
void print_stack(stack<int> sol){
    stack<int> temp;
    int num;
    while(!sol.empty()){
        num=sol.top();
        sol.pop();
        printf("%d%s",num,(sol.empty()?"\n":" "));
    }
}
int main(){
	int n,s,num,sum;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d %d",&n,&s);
        bool prime[s+1],found=false;
        for (int x=0;x<s+1;x++){
            prime[x]=true;
        }
        int t=make_prime(prime,s+1);
        int pm[t];
        for(int x=2,y=0;x<s+1;x++){
            if(prime[x]){
                pm[y]=x;
                y++;
            }
        }
        if(2*n<=s){
            for(int x=0;x<pow(t,(n));x++){
                stack<int> bag;
                for(int y=0;y<n;y++){
                    int p=(int)(pow(t,y));
                    bag.push(pm[(x/p)%t]);
                }
                //print_stack(bag);
                //printf("\n");
                if(check_stack(bag,s)){
                    print_stack(bag);
                    found=true;
                }
            }
        }
        if(!found)
            printf("%d\n",0);
        printf("\n");
	}
	return 0;
}

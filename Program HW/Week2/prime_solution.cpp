#include <bits/stdc++.h>
#include <stack>
using namespace std;
void make_prime(bool* prime,int len){
    prime[0]=false;
	prime[1]=false;
	for(int i =3;i<=len;i++){
		for(int j=0;j<i;j++){
            if(prime[j]){
                if(i%j==0){
                    prime[i]=false;
                    break;
                }
            }
		}
	}
	return;
}
void print_stack(stack<int> bag){
    stack<int> pool;
    while(!bag.empty()){
        pool.push(bag.top());
        bag.pop();
        printf("%d%s",pool.top(),bag.empty()?"\n":" ");
    }
}
void put_in_bag(bool prime[],int sum,int bsize){
    stack<int> mybag;
    bool ispare=false;
    int pt=sum,t_sum=0;
    while(true){
        while(!prime[pt]){
            if(pt>1)
                pt--;
            else
                break;
        }
        if(pt*(bsize-mybag.size())+t_sum<sum)
            if(mybag.empty())
                break;
            else{
                pt=mybag.top();
                mybag.pop();
                t_sum-=pt;
                pt--;
            }
        else if(bsize*2>sum)
            break;
        if(pt+t_sum<sum&&mybag.size()<bsize-1){
            mybag.push(pt);
            t_sum+=pt;
        }
        else if(pt+t_sum==sum&&mybag.size()==bsize-1){
            mybag.push(pt);
            print_stack(mybag);
            ispare=true;
            mybag.pop();
            pt--;
        }
        else{ //pt+t_sum<sum&&mybag.size()==bsize-1
            pt--;
        }
    }
    if(ispare)
        printf("\n");
    else
        printf("0\n\n");
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
        make_prime(prime,s);
        put_in_bag(prime,s,n);
        printf("\n");
	}
}

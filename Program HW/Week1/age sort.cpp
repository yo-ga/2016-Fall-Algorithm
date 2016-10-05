#include <bits/stdc++.h>
using namespace std ;
int main(){
	int num = 0;
	while(true){
		scanf("%d",&num);
		if(num<=0)
			break;
		vector<int> people(num);
		for(int i=0;i<num;i++){
			scanf("%d",&people[i]);
		}
		sort(people.begin(),people.end());
		for(int i=0;i<num;i++){
			cout<<((i==0)?"":" ")<<people[i];
		}
		cout<<"\n";
	}
}

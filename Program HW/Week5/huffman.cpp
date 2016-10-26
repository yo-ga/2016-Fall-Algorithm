#include<bits/stdc++.h>
#include<queue>
#include<string>
using namespace std;
struct huff{
        huff *left;
        char alpha;
        int value;
        huff *right;
};
int main(){
    char cipher[105]={};
    int ciph[27]={};
    scanf("%s",&cipher);
    for(int i=0;i<105;i++){
        ciph[(int)(cipher[i]-'a')]++;
    }
    int n=0;
    huff* node[11];
    for(int i=0;i<27;i++){
        if(ciph[i]>0){
            node[n]=new huff();
            node[n]->value=ciph[i];
            node[n]->alpha=(char)('a'+i);
            node[n]->left=NULL;
            node[n]->left=NULL;
            n++;
        }
    }
    huff* temp;
    int MIN1=105,MIN2=105;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(node[j]->value<node[j+1]->value){
                temp=new huff();
                temp=node[j+1];
                node[j+1]=node[j];
                node[j]=temp;
            }
        }
    }
    for(int i=n-1;i>0;i--){
        huff* root=new huff();
        root->value=node[i]->value+node[i-1]->value;
        root->left=node[i];
        root->right=node[i-1];
        root->alpha='@';
        node[i-1]=root;
        for(int j=i-1;j>0;j++){
            if(node[j]->value>node[j-1]->value){
                temp=new huff();
                temp=node[j-1];
                node[j-1]=node[j];
                node[j]=temp;
            }
            else
                break;
        }
    }
    queue<huff*>  read;
    read.push(node[0]);
    queue<string> path;
    path.push("");
    while(!read.empty()){
        huff* r=read.front();
        read.pop();
        string p(path.front());
        path.pop();
        if(r->alpha=='@'){
            read.push(r->left);
            path.push(p+"0");
            read.push(r->right);
            path.push(p+"1");
        }
        else{
            printf("%c:%s\n",r->alpha,p.c_str());
        }
    }
    return 0;
}

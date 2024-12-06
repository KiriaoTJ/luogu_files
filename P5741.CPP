#include<bits/stdc++.h>
using namespace std;
typedef struct{
    string name;
    int a,b,c,all,index;
}s;
int n;
int main(){
    cin>>n;
    s e[n];
    for(int i=0;i<n;i++){
        cin>>e[i].name>>e[i].a>>e[i].b>>e[i].c;
        e[i].all=e[i].a+e[i].b+e[i].c;
        e[i].index=i;
    }
    vector<int> v;
    for(int i=0;i<n-1;i++){//双循环逐步遍历找到每一组
        for(int j=i+1;j<n;j++){
            if(abs(e[i].a-e[j].a)<=5&&abs(e[i].b-e[j].b)<=5&&abs(e[i].c-e[j].c)<=5&&abs(e[i].all-e[j].all)<=10){
                cout<<e[i].name<<' '<<e[j].name<<endl;
            }
        }
    }
    return 0;
}
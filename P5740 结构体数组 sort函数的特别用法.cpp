#include<bits/stdc++.h>
using namespace std;
typedef struct{
    string name;
    int a,b,c,all,index;
}s;
int n;
bool compare(s &a,s &b){
    return a.all>b.all||(a.all==b.all&&a.index<b.index);
}
int main(){
    cin>>n;
    s e[n];
    for(int i=0;i<n;i++){
        cin>>e[i].name>>e[i].a>>e[i].b>>e[i].c;
        e[i].all=e[i].a+e[i].b+e[i].c;
        e[i].index=i;
    }
    sort(e,e+n,compare);
    cout<<e[0].name<<' '<<e[0].a<<' '<<e[0].b<<' '<<e[0].c;
    return 0;
}

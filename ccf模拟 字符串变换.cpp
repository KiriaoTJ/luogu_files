#include<bits/stdc++.h>
using namespace std;
int n,m;
string s0,temp,s1;
int main(){
    getline(cin,s0);
    cin>>n;
    cin.ignore();
    map<char,char> f;
    for(int i=32;i<=122;i++){
        f[i]=i;
    }
    for(int i=1;i<=n;i++){
        getline(cin,temp);
        f[temp[1]]=temp[2];
        cout<<temp;
    }
    cin>>m;
    cin.ignore();
    int k[m+5];
    for(int i=1;i<=m;i++){
        cin>>k[i];
    }
    for(int i=1;i<=m;i++){ //变换m个查询
        s1=s0;
        for(int j=1;j<=k[i];j++){ //每个查询变换k[i]次
            //对字符串s1进行变换
            for(int t=1;t<s1.length()-1;t++){
                s1[t]=f[s1[t]];
            }
        }
        cout<<s1<<endl;
    }
    return 0;
}
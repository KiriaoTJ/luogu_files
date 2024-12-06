#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){
    if(n==1) return false;
    if(n==2||n==3) return true;
    if(n%2==0) return false;
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    string a;
    cin>>a;
    int b[200];
    memset(b,0,sizeof(b));
    for(int i=0;i<a.length();i++){
        b[a[i]]++;
    }
    int maxn=0,minn=a.length();
    for(int i='a';i<='z';i++){
        if(b[i]>maxn) maxn=b[i];
    }
    for(int i='a';i<='z';i++){
        if(b[i]<minn&&b[i]!=0) minn=b[i];
    }
    if(isprime(maxn-minn)) {
        cout<<"Lucky Word"<<endl;
        cout <<maxn-minn;
    }
    else{
        cout<<"No Answer"<<endl;
        cout<<0;
    }
    return 0;
}
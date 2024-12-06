#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int t[34];
    memset(t,0,sizeof(t));
    for(int i=0;i<7;i++){
        int k;
        cin>>k;
        t[k]=1;
    }
    int a[n][7];
    for(int i=0;i<n;i++){
        for(int j=0;j<7;j++){
            cin>>a[i][j];
        }
    }
    int g[8];
    memset(g,0,sizeof(g));
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<7;j++){
            if(t[a[i][j]]) count++;
        }
        g[count]++;
    }
    for(int i=7;i>=1;i--){
        cout<<g[i]<<" ";
    }
    return 0;
}
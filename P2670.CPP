#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[105][105];//输入的图

int main(){
    cin>>n>>m;
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            c[i][j]='?';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int count=0;
            if(c[i][j]=='*'){
                cout<<'*';
            }
            else{
                if(c[i-1][j-1]=='*') count++;
                if(c[i-1][j]=='*') count++;
                if(c[i-1][j+1]=='*') count++;
                if(c[i][j-1]=='*') count++;
                if(c[i][j+1]=='*') count++;
                if(c[i+1][j-1]=='*') count++;
                if(c[i+1][j]=='*') count++;
                if(c[i+1][j+1]=='*') count++;
                cout<<count;
            }
        }
        if(i!=n) cout<<endl;
    }
    return 0;
}
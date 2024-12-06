#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    double b[n]={};
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
        sort(arr[i],arr[i]+m);
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=1;j<m-1;j++){
            sum+=arr[i][j];
        }
        b[i]=(double)sum/(m-2);
    }
    sort(b,b+n);
    printf("%.2f",b[n-1]);
    return 0;
}
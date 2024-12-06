#include<bits/stdc++.h>
using namespace std;
int n,p=1,a[1050][1050];
//定义一个可以取出来左上角矩阵的函数
//通过递归来实现，
// 每次递归将左上方的正方形清零，
// 并再次递归剩余的三个正方形，
// 当正方形的边长为2时结束递归。
void di(int x,int r,int s){
    if(x==2){
        a[r][s]=0;
        return;
    }
    for(int i=r;i<=r+x/2-1;i++){
        for(int j=s;j<=s+x/2-1;j++){
            a[i][j]=0;//将左上方的正方形清零
        }
    }
    di(x/2,r+x/2,s);
    di(x/2,r,s+x/2);
    di(x/2,r+x/2,s+x/2);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        p*=2;
    }
    for(int i=1;i<=p;i++){
        for(int j=1;j<=p;j++){
            a[i][j]=1;
        }
    }
    di(p,1,1);
    for(int i=1;i<=p;i++){
        for(int j=1;j<=p-1;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<a[i][p]<<endl; //我去，这个竟然可以避免行尾空格，学习一下
    }
    return 0;
}
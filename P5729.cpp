#include<bits/stdc++.h>
using namespace std;
//给出的数据是有可能重复切到同一块地方的，这里最好还是使用布尔数组吧
int main(){
    int w,x,h,q,count=0;
    cin>>w>>x>>h;
    cin>>q;
    int block[w+1][x+1][h+1]={};
    for(int i=0;i<w+1;i++){
            for(int j=0;j<x+1;j++){
                for(int k=0;k<h+1;k++)
                 block[i][j][k]=1;
            }
    }    
    //读取了两个点的坐标之后，就需要把这个三位数组中对应的地方全部设置为0
    //所以只需要这样的一个循环就可以了
    for(int r=0;r<q;r++){
        int x1,y1,z1,x2,y2,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                for(int k=z1;k<=z2;k++){
                    if(block[i][j][k]==1){
                        block[i][j][k]=0;
                        count++;
                    }
                }
            }
        }
    }
    cout<<w*x*h-count;
    return 0;
}
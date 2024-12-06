//用结构体数组会更好 不需要定义两个映射

#include<bits/stdc++.h>
using namespace std;
int n,m,a,s;
int main(){
    cin>>n>>m;
    map<string,int> mp1; //记录职业与朝向
    map<int,string> mp2; //记录职业与职业所处序号
    for(int i=1;i<=n;i++){ //记录职业与朝向
        int temp;
        string t;
        cin>>temp>>t;
        mp1[t]=temp;
        mp2[i]=t;
    }
    int count=1; //用来记录执行指令之后当前的位置
    for(int i=1;i<=m;i++){ //读取指令
        cin>>a>>s;
        //顺时针走s步相当于逆时针走n-s步
        if((a==0&&mp1[mp2[count]]==0)||(a==1&&mp1[mp2[count]]==1)){
            if((count+n-s)%n!=0) count=(count+n-s)%n;
            else count=n;   
        }
        else if((a==0&&mp1[mp2[count]]==1)||(a==1&&mp1[mp2[count]]==0)){
            if((count+s)%n!=0) count=(count+s)%n;
            else count=n;
        }
    }
    cout<<mp2[count];   
    return 0;
}
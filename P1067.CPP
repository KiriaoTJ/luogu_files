#include<bits/stdc++.h>
using namespace std;
int n;
string s[105];
int len[105];
//先读取n
//然后一个循环读取各项的符号、系数
//之后特判第一项、系数=1的项、最后一项
int main(){
    cin>>n;
    for(int i=n;i>=0;i--){
        cin>>s[i];
        len[i]=s[i].length();
    }
    if(n==0){
        cout<<s[0];
    }
    else if(n==1){ //先输出一次项，再输出常数项
        if(s[1][0]=='-'){
            s[1].erase(s[1].begin());
            cout<<'-'<<s[1]<<'x';;
        }
        else{
            cout<<s[1]<<'x';
        }
        if(s[0][0]=='-'){
            s[0].erase(s[0].begin());
            cout<<'-'<<s[0];
        }
        else{
            cout<<'+'<<s[0];
        }
    }
    else{
        if(s[n][0]=='0'){
    }
    else{
        if(s[n][0]=='-'){//先特判最高次项：如果符号为正不需要输出
        if(s[n][1]=='1'&&len[n]==2){ //判断是不是1的方法
            cout<<"-x^"<<n;
        }
        else{
            s[n].erase(s[n].begin());
            cout<<'-'<<s[n]<<"x^"<<n;
        }
        }
        else{ //系数为正数
            if(s[n][0]=='1'&&len[n]==1){ //系数为1
                cout<<"x^"<<n;
            }
            else{ //系数为非1正数
                cout<<s[n]<<"x^"<<n;
            }
        }
    }
    
    for(int i=n-1;i>=2;i--){
        if(s[i][0]=='0'){
        }
        else{
            if(s[i][0]=='-'){
                if(s[i][1]=='1'&&len[i]==2){
                    cout<<"-x^"<<i;
                    }
                else{
                    s[i].erase(s[i].begin());
                    cout<<'-'<<s[i]<<"x^"<<i;
                }
            }
            else{
                if(s[i][0]=='1'&&len[i]==1){
                    cout<<"+x^"<<i;
                }
                else{
                    cout<<'+'<<s[i]<<"x^"<<i;
                }
            }
        }   
    }
    if(s[1][0]=='0'){
    }
    else{
        if(s[1][0]=='-'){
        if(s[1][1]=='1'&&len[1]==2){
            cout<<"-x";
            }
        else{
            s[1].erase(s[1].begin());
            cout<<'-'<<s[1]<<"x";
            }
        }
        else{
            if(s[1][0]=='1'&&len[1]==1){
                cout<<"+x";
            }
            else{
                cout<<'+'<<s[1]<<"x";
            }
        }
    }
    if(s[0][0]=='0'){
    }
    else{
        if(s[0][0]=='-'){
            cout<<s[0];
        }
        else{
            cout<<'+'<<s[0];
        }
    }
    }
    
    return 0;
}
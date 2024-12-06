#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2,s3,s4;
    getline(cin,s1);
    getline(cin,s2);
    getline(cin,s3);
    getline(cin,s4);
    string s=s1+s2+s3+s4;
    int t[100]; //记录字母出现的次数
    memset(t,0,sizeof(t));
    for(int i=0;i<s.length();i++){
        t[s[i]]++;
    }
    int m=t[65];
    for(int i=66;i<=90;i++){ //找到最大的出现次数
        if(m<t[i]) m=t[i];
    }
    char arr[100][100];
    int count=0;
    for(int i=65;i<=90;i++){
        if(count<25){
            for(int j=1;j<=m-t[i];j++){
                arr[j][i+count]=' ';
                arr[j][i+count+1]=' ';
            }
            for(int j=m-t[i]+1;j<=m;j++){
                arr[j][i+count]='*';
                arr[j][i+count+1]=' ';
            }
            arr[m+1][i+count]=i;
            arr[m+1][i+count+1]=' ';
            count++;
        }
        else{
            for(int j=1;j<=m-t[i];j++){
                arr[j][i+count]=' ';
            }
            for(int j=m-t[i]+1;j<=m;j++){
                arr[j][i+count]='*';
            }
        }
    }
    for(int i=1;i<=m+1;i++){
        for(int j=65;j<=90+25;j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
    return 0; //记得换行
}

//A对应65
//Z对应90
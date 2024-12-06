

#include<bits/stdc++.h>
using namespace std;
//要分类：不需要加，或者需要加
int main(){
    int n;
    cin>>n;
    getchar();
    string s;
    cin>>s;
    string t="VK";
    int a=0; //记录VK
    for(int i=0;i<s.length()-1;i++){//把所有的VK都替换成11
        if(s[i]=='V'&&s[i+1]=='K'){
            a++;
            s[i]='1';
            s[i+1]='1';
        }
    }
    //之后再寻找VV KK KV
    for(int i=0;i<s.length()-1;i++){
        if((s[i]=='V'&&s[i+1]=='V')||(s[i]=='K'&&s[i+1]=='K')){
            a++;
            break;
        }
    }
    cout<<a;
    return 0;    
}
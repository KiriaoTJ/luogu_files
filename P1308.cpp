#include<bits/stdc++.h>
using namespace std;
/*如何界定“找到一个单词”？
首先由于不区分大小写，应该先把s1和s2中的字符全部变成小写*/ 
void upper_to_lower(string &s){
    for(int i=0;i<s.length();i++){
        if(isupper(s[i])) s[i]+=32;
    }
}
/*给s1，s2的两侧插两个空格，然后找单词除了第一个单词以外的单词就不需要特判了*/
void insert_space(string &s){
    s.insert(0," ");
    //s.insert(s.length()," "); 不好，最好用pushback
    s.push_back(' ');
}
/*之后运用find函数即可*/
int main(){
    string s1,s2;
    int count=0;
    cin>>s1;
    getchar();
    getline(cin,s2);
    upper_to_lower(s1);
    upper_to_lower(s2);
    insert_space(s1);
    insert_space(s2);
    int firstpos=-1;
    if(s2.find(s1)!=string::npos){
        firstpos=s2.find(s1);
        int i=firstpos;
        while(i!=string::npos){
            count++;
            i=s2.find(s1,i+s1.length()-1);
        }
    }
    if(count!=0){
        cout<<count<<" "<<firstpos;
    }
    else{
        cout<<firstpos;
    }
    return 0;
}

/*to be or not to be that is a question*/
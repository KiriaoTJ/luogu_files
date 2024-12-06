#include<bits/stdc++.h>
using namespace std;
/*这里存在四种情况：整数，小数，分数，百分数
但是事实上用的都是一套逻辑：对于整数的反转+对于非小数点后的部分，去掉多余的前导0
只有对于小数点后面的部分才需要特判
所以可以先写好反转整数的函数，*/
/*12345678 长度为8，最适合的截止条件是i<4*/
/*123456789 长度为9，最合适的截止条件是i<4---9/2即可*/
string reverse(string &s){
    string temp;
    for(int i=s.length()-1;i>=0;i--){
        temp.push_back(s[i]);
    }
    return temp;
}
void removefrontzero(string &s){
    int pos=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!='0'){
            pos=i;
            break;
        }
    }
    s.erase(0,pos);
}
/*然后对于整数、分数、百分数直接套用就可以了*/
int isfraction(string &s){
    for(int i=0;i<s.length();i++){
        if(s[i]=='/') return i;
    }
    return false;
}
int isdecimal(string &s){
    for(int i=0;i<s.length();i++){
        if(s[i]=='.') return i;
    }
    return false;
}
bool ispercentage(string &s){
    if(s[s.length()-1]=='%') return true;
    else return false;
}
/*对于小数呢，整数部分直接套用，小数部分需要特判*/
//有没有可能原本的小数部分是.025452000的形式，然后反转之后000254520，
//那么还差一个多去掉后导0的函数,这个其实对于反转后的小数点后的子字符串是一定要操作的
void removebackzero(string &s){
    while(s[s.length()-1]=='0'&&s.length()>1){//保证如果全是0也可以剩下一个0
        s.erase(s.length()-1,1);
    }
}
//如果小数部分反转之后只有0
/*如果这个子字符串中只有0，那么直接打一个0就好了
如果这个子字符串中不全是0，那直接套用上去就好了*/

int main(){
    string s;
    cin>>s;
    getchar();
    if(isfraction(s)){
        // 1234/45678
        int pos=isfraction(s);
        string s1=s.substr(0,pos);
        string s2=s.substr(pos+1,s.length()-pos);
        s1=reverse(s1);
        s2=reverse(s2);
        removefrontzero(s1);
        removefrontzero(s2);  
        cout<<s1<<'/'<<s2;  
    }
    else if(ispercentage(s)){
        string s1=s.substr(0,s.length()-1);
        s1=reverse(s1);
        removefrontzero(s1);
        cout<<s1<<'%';
    }
    else if(isdecimal(s)){
        int pos=isdecimal(s);
        string s1=s.substr(0,pos);
        string s2=s.substr(pos+1,s.length()-pos);
        s1=reverse(s1);
        s2=reverse(s2);
        removefrontzero(s1);
        removebackzero(s2);
        cout<<
        s1<<'.'<<s2;
    }
    else{
        s=reverse(s);
        removefrontzero(s);
        cout<<s;
    }
    return 0;
}

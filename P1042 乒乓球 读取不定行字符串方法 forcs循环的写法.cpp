#include<bits/stdc++.h>
using namespace std;
//输出乒乓球11分制和21分制下不同的结果

// void for11(string &s){//统计11分制下的情况
//     string s1=s;
//     int w=0,l=0;
//     while(s1.length()>=11){
//         while(!(w+l>=11&&abs(w-l)>=2)){
//             if(s1[w+l]=='W') w++;
//             if(s1[w+l]=='W') w++;
//         }
//         cout<<w<<':'<<l<<endl;
//         s1.erase(0,w+l);
//         w=0,l=0;
//     }
//     if(s1.length()==0)return;
//     for(int i=0;i<s1.length();i++){
//         if(s1[i]=='W') w++;
//         else l++;
//     }
//     cout<<w<<':'<<l<<endl;
//     return;
// }

void for11(string &s){//统计11分制下的情况
    int w=0,l=0;
    for(char c:s){
        if(c=='W') w++;
        else if(c=='L') l++;
        if((w>=11||l>=11)&&abs(w-l)>=2){
            cout<<w<<':'<<l<<endl;
            w=0,l=0;
        }
    }
    cout<<w<<':'<<l;
}

void for21(string &s){//统计21分制下的情况
    int w=0,l=0;
    for(char c:s){
        if(c=='W') w++;
        else if(c=='L') l++;
        if((w>=21||l>=21)&&abs(w-l)>=2){
            cout<<w<<':'<<l<<endl;
            w=0,l=0;
        }
    }
    cout<<w<<':'<<l;
}
int main(){
    string s;
    string temp;
    while(getline(cin,temp)){//不停读取每一行的字符串
        s+=temp;
        if(s.find("E")!=string::npos) break;
    }
    s=s.substr(0,s.find("E"));
    for11(s);
    cout<<endl;
    cout<<endl;
    for21(s);
    return 0;
}
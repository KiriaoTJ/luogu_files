#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    cin>>a;
    for(int i=0;i<a.length();i++){
        if(islower(a[i])) a[i]-=32;
    }
    cout<<a;
}
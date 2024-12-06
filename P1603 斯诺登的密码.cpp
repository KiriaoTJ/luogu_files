#include <bits/stdc++.h>
using namespace std;
/*在全局作用域中直接对 map 进行操作是不允许的。
全局作用域中的代码在编译时会立即执行，而 map 的操作需要在运行时进行*/
int main(){
    map<string,int> q;
    q["one"]=1;q["two"]=2;q["three"]=3;q["four"]=4;q["five"]=5;q["six"]=6;q["seven"]=7;q["eight"]=8;q["nine"]=9;q["ten"]=10;q["eleven"]=11;q["twelve"]=12;q["thirteen"]=13;q["fourteen"]=14;q["fifteen"]=15;q["sixteen"]=16;q["seventeen"]=17;q["eighteen"]=18;q["nineteen"]=19;q["twenty"]=20;q["a"]=1;q["both"]=2;q["another"]=1;q["first"]=1;q["second"]=2;q["third"]=3;
    string s;
    int a[10];
    memset(a,0,sizeof(a));
    int j=0;
    for(int i=0;i<6;i++){
        cin>>s;
        if(q[s]){
            int k=(q[s]*q[s])%100;
            if(k==0) continue;
            else a[j++]=k;
        }
    }
    if(j==0){
        cout<<0;
        return 0;
    }
    sort(a,a+j-1);
    cout<<a[0];
    for(int i=1;i<j;i++){
        if(a[i]<10){
            cout<<0<<a[i];
        }
        else{
            cout<<a[i];
        }
    }
    return 0;
}

//01 04 01 01 04 09-10101040409
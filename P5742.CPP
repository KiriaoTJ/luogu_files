#include<bits/stdc++.h>
using namespace std;

int main(){
    //每个数被选中两次
    int a,n=0;
    long long s=0;
    while(scanf("%d",&a)!=EOF){
        s+=a;
        n++;
    }
    for(int i=1;i<=n-1;i++){
        s*=2;
    }
    printf("%lld",s);
}
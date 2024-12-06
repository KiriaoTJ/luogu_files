#include<bits/stdc++.h>
using namespace std;
int n,a,b,x=0,y=0;
void work1(){
    cin>>n>>a>>b;
    int c[a],d[b];
    for(int i=0;i<a;i++){
        cin>>c[i];
    }
    for(int i=0;i<b;i++){
        cin>>d[i];
    }
    for(int i=0;i<n;i++){
        switch(c[i%a]){
            case 0:switch(d[i%b]){
                case 1:
                case 4:{
                    y++;
                    break;
                }
                case 2:
                case 3:{
                    x++;
                    break;
                }
            };break; //注意这也是个switch的case
            case 1:switch(d[i%b]){
                case 2:
                case 4:{
                    y++;
                    break;
                }
                case 0:
                case 3:{
                    x++;
                    break;
                }
            };break;
            case 2:switch(d[i%b]){
                case 0:
                case 3:{
                    y++;
                    break;
                }
                case 1:
                case 4:{
                    x++;
                    break;
                }
            };break;
            case 3:switch(d[i%b]){
                case 1:
                case 0:{
                    y++;
                    break;
                }
                case 2:
                case 4:{
                    x++;
                    break;
                }
            };break;
            case 4:switch(d[i%b]){
                case 2:
                case 3:{
                    y++;
                    break;
                }
                case 0:
                case 1:{
                    x++;
                    break;
                }
            };break;
        }
    }
    cout<<x<<' '<<y;
    return;
}

void work2(){
    int g[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}}; //描述规则
    cin>>n>>a>>b;
    int c[a],d[b];
    for(int i=0;i<a;i++){
        cin>>c[i];
    }   
    for(int i=0;i<b;i++){
        cin>>d[i];
    }
    for(int i=0;i<n;i++){
        x+=g[c[i%a]][d[i%b]];
        y+=g[d[i%b]][c[i%a]];
    }
    cout<<x<<' '<<y;
    return;
}
int main(){
    work2();
}
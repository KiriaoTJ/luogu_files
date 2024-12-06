// 写废了

// #include<bits/stdc++.h>
// using namespace std;

// int x=1,y=1; //分别表示牛和John的朝向 1234上下左右
// int cx=0,cy=0,fx=0,fy=0; //记录牛和John的坐标
// char a[15][15],b[15][15]; //b是临时数组
// void moveC(char a[15][15],int&cx, int&cy, int&x){//牛的行动
//     if(x==1){
//         char temp=a[cx][cy-1];
//         if(temp=='.'){ //可以行动
//             a[cx][cy-1]='C';
//             a[cx][cy]='.';
//             cy--;
//         }
//         else if(temp=='F'){//可以行动
//         }
//         else if(temp=='*'){//转向
//             x=4;
//         }
//     }
//     else if(x==2){
//         char temp=a[cx][cy+1];
//         if(temp=='.'){ //可以行动
//             a[cx][cy+1]='C';
//             a[cx][cy]='.';
//             cy++;
//         }
//         else if(temp=='*'){//转向
//             x=3;
//         }
//     }
//     else if(x==3){
//         char temp=a[cx-1][cy];
//         if(temp=='.'){ //可以行动
//             a[cx-1][cy]='C';
//             a[cx][cy]='.';
//             cx--;
//         }
//         else if(temp=='*'){//转向
//             x=1;
//         }
//     }
//     else{
//         char temp=a[cx+1][cy];
//         if(temp=='.'){ //可以行动
//             a[cx+1][cy]='C';
//             a[cx][cy]='.';
//             cx++;
//         }
//         else if(temp=='*'){//转向
//             x=2;
//         }
//     }
// }

// void moveF(char a[15][15],int&fx, int&fy, int&y){//John的行动
//     if(y==1){
//         char temp=a[fx][fy-1];
//         if(temp=='.'){ //可以行动
//             a[fx][fy-1]='F';
//             a[fx][fy]='.';
//             fy--;
//         }
//         else if(temp=='*'){//转向
//             y=4;
//         }
//     }
//     else if(y==2){
//         char temp=a[fx][fy+1];
//         if(temp=='.'){ //可以行动
//             a[fx][fy+1]='F';
//             a[fx][fy]='.';
//             fy++;
//         }
//         else if(temp=='*'){//转向
//             y=3;
//         }
//     }
//     else if(y==3){
//         char temp=a[fx-1][fy];
//         if(temp=='.'){ //可以行动
//             a[fx-1][fy]='F';
//             a[fx][fy]='.';
//             fx--;
//         }
//         else if(temp=='*'){//转向
//             y=1;
//         }
//     }
//     else if(y==4){
//         char temp=a[fx+1][fy];
//         if(temp=='.'){ //可以行动
//             a[fx+1][fy]='F';
//             a[fx][fy]='.';
//             fx++;
//         }
//         else if(temp=='*'){//转向
//             y=2;
//         }
//     }
// }
// int main(){

//     for(int i=0;i<15;i++){//初始化网格
//         for(int j=0;j<15;j++){
//             a[i][j]='*'; //设置全为障碍物
//         }
//     }
//     for(int i=1;i<=10;i++){ //读取地图
//         for(int j=1;j<=10;j++){
//             cin>>a[i][j];
//             //读取C和F的坐标
//             if(a[i][j]=='C') cx=i,cy=j;
//             if(a[i][j]=='F') fx=i,fy=j;
//         }
//     }
//     int count=0; //记录分钟
//     while(!(cx==fx&&cy==fy)){
//         moveC(a,cx,cy,x);
//         moveF(a,fx,fy,y);
//         count++;
//     }
//     cout<<count;
// }

// 题解
// #include <bits/stdc++.h>
// using namespace std;
// char m[12][12];           // 地图
// int f[3], c[3], ans, tdz; // 农夫，奶牛，秒数，专属值
// bool zt[160005];          // 记录专属值是否出现
// void move(int x, int y, int mi, int h)
// //全程不需要改变原来的地图
// { // 移动函数 x,y为x,y坐标，mi为方向，h为类型：农夫为0，奶牛为1,引入参数h可以节省一个函数
//     if (mi == 0) //向北
//     { // 而且这样引入x，y，mi，避免了以数组为形参
//         if (m[x - 1][y] == '*') //如果此路不通
//             if (h == 0) //如果这里是农夫
//                 f[0] = 1;//换向
//             else //如果这里是奶牛
//                 c[0] = 1;
//         else if (h == 0) //如果这里是农夫，而且此路可通行
//             f[1]--;
//         else //如果这里是奶牛，而且此路可通行
//             c[1]--;
//     }
//     else if (mi == 1)
//     {
//         if (m[x][y + 1] == '*')
//             if (h == 0)
//                 f[0] = 2;
//             else
//                 c[0] = 2;
//         else if (h == 0)
//             f[2]++;
//         else
//             c[2]++;
//     }
//     else if (mi == 2)
//     {
//         if (m[x + 1][y] == '*')
//             if (h == 0)
//                 f[0] = 3;
//             else
//                 c[0] = 3;
//         else if (h == 0)
//             f[1]++;
//         else
//             c[1]++;
//     }
//     else
//     {
//         if (m[x][y - 1] == '*')
//             if (h == 0)
//                 f[0] = 0;
//             else
//                 c[0] = 0;
//         else if (h == 0)
//             f[2]--;
//         else
//             c[2]--;
//     }
// }
// bool pd()
// { // 判断循环终止条件：如果奶牛坐标与农夫坐标相等，则他们重叠，返回0，退出循环
//     if (f[1] == c[1] && f[2] == c[2])
//         return 0;
//     else
//         return 1;
// }
// int main()
// {
//     for (int i = 0; i <= 11; i++)
//         m[i][0] = '*', m[i][11] = '*';
//     for (int i = 1; i <= 11; i++)
//         m[0][i] = '*', m[11][i] = '*';
//     for (int i = 1; i <= 10; i++)
//     {
//         for (int j = 1; j <= 10; j++)
//         {
//             cin >> m[i][j];
//             if (m[i][j] == 'F')
//                 f[1] = i, f[2] = j; // 用这种方式去记录坐标！
//             if (m[i][j] == 'C')
//                 c[1] = i, c[2] = j;
//         }
//     }
//     while (pd())
//     { // 模拟每秒
//         tdz = f[1] + f[2] * 10 + c[1] * 100 + c[2] * 1000 + f[0] * 10000 + c[0] * 40000;
//         if (zt[tdz])
//         { // 死循环了就输出0并结束程序
//             cout << 0 << endl;
//             return 0;
//         }
//         zt[tdz] = 1; // 标记
//         move(f[1], f[2], f[0], 0);
//         move(c[1], c[2], c[0], 1); // 依次移动农夫和奶牛
//         ans++;                     // 记录秒数
//     }
//     cout << ans << endl; // 输出
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
char m[12][12];  
int c[3],f[3];

// 1 2 3 4 上下左右
void move(int x,int y,int h,int status){ //status=0: C status=1: F
    if(h==1){
        if(m[x-1][y]=='*'){//此路不通
            if(status==0) c[0]=4;
            else f[0]=4;
        }
        else{
            if(status==0) c[1]--;
            else f[1]--;
        }
    }
    else if(h==2){
        if(m[x+1][y]=='*'){//此路不通
            if(status==0) c[0]=3;
            else f[0]=3;
        }
        else{
            if(status==0) c[1]++;
            else f[1]++;
        }
    }
    else if(h==3){
        if(m[x][y-1]=='*'){//此路不通
            if(status==0) c[0]=1;
            else f[0]=1;
        }
        else{
            if(status==0) c[2]--;
            else f[2]--;
        }
    }
    else if(h==4){
        if(m[x][y+1]=='*'){//此路不通
            if(status==0) c[0]=2;
            else f[0]=2;
        }
        else{
            if(status==0) c[2]++;
            else f[2]++;
        }
    }
}
int main(){
    c[0]=1,f[0]=1;
    for(int i=0;i<12;i++){
        m[i][0]='*';
        m[i][11]='*';
        m[0][i]='*';
        m[11][i]='*';
    }
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            cin>>m[i][j];
            if(m[i][j]=='C') c[1]=i,c[2]=j;
            if(m[i][j]=='F') f[1]=i,f[2]=j;
        }
    }
    int count=0;
    while(!(f[1]==c[1]&&f[2]==c[2])){
        move(c[1],c[2],c[0],0);
        move(f[1],f[2],f[0],1);
        count++;
        if(count>=1000){
            cout<<0;
            return 0;
        }
    }
    cout<<count;
    return 0;   
}
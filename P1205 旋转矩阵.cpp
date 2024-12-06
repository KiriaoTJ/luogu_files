#include <bits/stdc++.h>
using namespace std;
bool isequal(char (*a)[15],char (*b)[15],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=b[i][j]) return 0;
        }
    }
    return 1;
}
void work1(char (*a)[15],char (*c)[15],int n){ //让一个矩阵=另一个矩阵转90度
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[j][n-1-i]=a[i][j];
        }
    }
}
void work4(char (*a)[15],char (*c)[15],int n){//让一个矩阵=另一个矩阵镜像
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            c[i][j]=a[i][n-1-j];
        }
    }
}
int main(){
    int n;
    cin>>n;
    char a[15][15],b[15][15],c[15][15],temp[15][15];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }
    memset(c, 0, sizeof(c)); // 每次使用前初始化
    work1(a,c,n); //赋值c为a旋转90度
    if(isequal(b,c,n)){
        cout<<1<<endl;
        return 0;
    }
    memset(temp, 0, sizeof(temp)); // 每次使用前初始化temp
    work1(c,temp,n); //把c再转90度也就是180度，赋值给temp
    if(isequal(b,temp,n)){
        cout<<2<<endl;
        return 0;
    }
    memset(c, 0, sizeof(c)); // 每次使用前初始化
    work1(temp,c,n); //把temp再转90度也就是270度，赋值给c
    if(isequal(b,c,n)){
        cout<<3<<endl;
        return 0;
    }
    memset(c, 0, sizeof(c)); // 每次使用前初始化
    memset(temp, 0, sizeof(temp)); // 每次使用前初始化temp
    work4(a,c,n); //再次赋值c为a镜像了一次
    if(isequal(b,c,n)){
        cout<<4<<endl;
        return 0;
    }
    work1(c,temp,n); //c为a的镜像，这个矩阵再转90度
    if(isequal(b,temp,n)){
        cout<<5<<endl;
        return 0;
    }
    memset(c, 0, sizeof(c)); // 每次使用前初始化
    work1(temp,c,n); //转180度
    if(isequal(b,c,n)){
        cout<<5<<endl;
        return 0;
    }
    memset(temp, 0, sizeof(temp)); // 每次使用前初始化temp
    work1(c,temp,n); //转270度
    if(isequal(b,temp,n)){
        cout<<5<<endl;
        return 0;
    }
    if(isequal(a,b,n)){ //如果什么操作都不需要的话就是6
        cout<<6<<endl;
        return 0;
    }
    cout<<7<<endl; //上面所有情况都没有return 0那么就是7
    return 0;
}

/*改之前的代码
洛谷 / 评测记录 / 评测详情 
R189754018 记录详情
编程语言
C++14 (GCC 9) O2
代码长度
1.73KB
用时
21ms
内存
688.00KB
 wendaining

所属题目
P1205 [USACO1.2] 方块转换 Transformations
评测状态
Unaccepted
评测分数
28
提交时间
2024-11-19 13:48:13
测试点信息源代码
源代码 复制
#include <bits/stdc++.h>
using namespace std;

// 判断两个矩阵是否相等
bool isequal(char (*a)[15], char (*b)[15], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != b[i][j]) 
                return false;
        }
    }
    return true;
}

// 旋转90度
void rotate90(char (*a)[15], char (*c)[15], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[j][n - 1 - i] = a[i][j];
        }
    }
}

// 镜像
void work4(char (*a)[15],char (*c)[15],int n){//让一个矩阵=另一个矩阵镜像
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            c[i][j]=a[i][n-1-j];
        }
    }
}

int main() {
    int n;
    cin >> n;
    char a[15][15], b[15][15], c[15][15];
    memset(a, 0, sizeof(a)); // 每次使用前初始化
    memset(b, 0, sizeof(b)); // 每次使用前初始化
    memset(c, 0, sizeof(c)); // 每次使用前初始化
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    // 旋转90度
    rotate90(a, c, n);
    if (isequal(b, c, n)) {
        cout << 1;
        return 0;
    }

    // 旋转180度
    rotate90(c, c, n);
    if (isequal(b, c, n)) {
        cout << 2;
        return 0;
    }

    // 旋转270度
    rotate90(c, c, n);
    if (isequal(b, c, n)) {
        cout << 3;
        return 0;
    }
    memset(c, 0, sizeof(c));
    // 镜像
    mirror(a, c, n);
    if (isequal(b, c, n)) {
        cout << 4;
        return 0;
    }

    // 镜像+旋转90度
    rotate90(c, c, n);
    if (isequal(b, c, n)) {
        cout << 5;
        return 0;
    }

    // 镜像+旋转180度
    rotate90(c, c, n);
    if (isequal(b, c, n)) {
        cout << 5;
        return 0;
    }

    // 镜像+旋转270度
    rotate90(c, c, n);
    if (isequal(b, c, n)) {
        cout << 5;
        return 0;
    }

    // 无需操作
    if (isequal(a, b, n)) {
        cout << 6;
        return 0;
    }

    // 无法匹配
    cout << 7;
    return 0;
}


在洛谷，
享受 Coding 的欢乐

关于洛谷 | 帮助中心 | 用户协议 | 联系我们
小黑屋 | 陶片放逐 | 社区规则 | 招贤纳才
Developed by the Luogu Dev Team
2013-2024 , © 洛谷
增值电信业务经营许可证 沪B2-20200477
沪ICP备18008322号 All rights reserved.*/
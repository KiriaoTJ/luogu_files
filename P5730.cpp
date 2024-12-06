#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c[10][5][4]= //数组打表
    {
        "XXX",//0
        "X.X",
        "X.X",
        "X.X",
        "XXX",
        "..X",//1,右对齐，坑2
        "..X",
        "..X",
        "..X",
        "..X",
        "XXX",//2
        "..X",
        "XXX",
        "X..",
        "XXX",
        "XXX",//3
        "..X",
        "XXX",
        "..X",
        "XXX",
        "X.X",//4
        "X.X",
        "XXX",
        "..X",
        "..X",
        "XXX",//5
        "X..",
        "XXX",
        "..X",
        "XXX",
        "XXX",//6
        "X..",
        "XXX",
        "X.X",
        "XXX",
        "XXX",//7
        "..X",
        "..X",
        "..X",
        "..X",
        "XXX",//8
        "X.X",
        "XXX",
        "X.X",
        "XXX",
        "XXX",//9
        "X.X",
        "XXX",
        "..X",
        "XXX"
    };
    int n,s=0,a;
    scanf("%d",&n);
    char arr[10][1000]; //数组开大一点
    for(int i=1;i<=n;i++){
        scanf("%1d",&a); //1d可以保证只要一个数
        for(int j=0;j<5;j++){
            for(int k=0;k<3;k++){
                arr[i][s+k]=c[a][i][j];
            }
        }
        for(int j=0;j<5;j++){//必须要另起一个循环，因为得上面那个双循环结束之后，才能再一整列地赋值，而一整列的赋值就是遍历一整行
            arr[j][s+4]='.'; //在j的循环里面，意思是对一整列进行操作，给这个数字的后面一列全部赋值为'.'
            s+=4;
        }
    }
    //打印结果
    for(int i=0;i<5;i++){//一行一行打印
        for(int j=0;j<s-1;j++){//最后那个数字不会跟着一列的'0'
            printf("%c",arr[i][j]);
        }
        printf("\n"); //记得打印完一行之后需要换行
    }
    return 0;
}
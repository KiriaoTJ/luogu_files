#include<bits/stdc++.h>
using namespace std;
/*
首先第一行的运算方式相当于给定了一个初值条件，
如果第n行没有给定运算方式，那么第n行的运算方式就取决于第n-1行的运算方式
如何判断有没有给定运算方式？
因为每一行的数据类型是string，那么只需要判断a[0][0]是不是'a'或者'b'或者'c'
然后这里就需要一个函数了，专门用来判断并且指定运算形式
再然后，下一行运算确定上一种运算的方式，定义一个int flag=1,2,3对应加、减、乘，
再搞一个对字符的映射
输入每一行新的运算，都需要这样判断一遍。

怎么写一个找到字符串中所有数字的方法呢？
首先使用find函数，当返回值不为string::npos时，
给一个数组b[2]记录这个位置，b[i]就是第i个空格的位置（要先让b全为-1）
然后再erase这个空格
这个循环结束之后，分别substr出来（最后一个地方用a.end()就好了）
理论上也就一个或者是两个空格，这里又需要特判了
如果只有一个空格，也就是b[1]=-1那么就从0到这个空格，再从空格到a.end()
如果有两个空格，那就先从b[0]+1到b[1]，再从b[1]+1到a.end()
定义一个函数，最后用这几个数组逐个取出来元素搞成数字(循环一下然后*10的方式)
最后按照格式输出
*/

int trans(const string& s) {
    int res = 0;
    int length = s.length();

    for (int i = 0; i < length; ++i) {
        res = res * 10 + (s[i] - '0');
    }

    return res;
}
int digitLength(int num) {
    // 将数字转换为字符串
    std::string str = std::to_string(num);
    // 返回字符串的长度
    return str.length();
}
int main(){
    int n,num1,num2;
    cin>>n;
    int flag[n];
    memset(flag,0,sizeof(flag));
    string a[n];
    getchar();
    for(int i=0;i<n;i++){
      getline(cin,a[i]);
        if(a[i][0]=='a'){
            flag[i]=1;
        }
        else if(a[i][0]=='b'){
            flag[i]=2;
        }
        else if(a[i][0]=='c'){
            flag[i]=3;
        }
        else{
            flag[i]=flag[i-1];
        }
    }
    map<int,char> mp;
    mp[1]='+';
    mp[2]='-';
    mp[3]='*';
    int b[2];
    for(int i=0;i<n;i++){
        b[0]=a[i].find(" ");
        a[i].erase(b[0],1);
        b[1]=a[i].find(" ");
        if(b[1]==string::npos){
            int num1=trans(a[i].substr(0,b[0]));
            int num2=trans(a[i].substr(b[0],a[i].size()-(b[0])));
            int result;
            if (flag[i] == 1) result = num1 + num2;
            else if (flag[i] == 2) result = num1 - num2;
            else if (flag[i] == 3) result = num1 * num2;
            string s1=to_string(num1);
            string s2=to_string(num2);
            string s3=to_string(result);
            printf("%d%c%d=%d\n%d\n",num1,mp[flag[i]],num2,result,
                                        s1.length()+s2.length()+s3.length()+2);
        }
        else{
            int num1=trans(a[i].substr(b[0],b[1]-(b[0])));
            int num2=trans(a[i].substr(b[1]+1,a[i].size()-(b[1]+1)));
            int result;
            if (flag[i] == 1) result = num1 + num2;
            else if (flag[i] == 2) result = num1 - num2;
            else if (flag[i] == 3) result = num1 * num2;
            string s1=to_string(num1);
            string s2=to_string(num2);
            string s3=to_string(result);
            printf("%d%c%d=%d\n%d\n",num1,mp[flag[i]],num2,result,
                                        s1.length()+s2.length()+s3.length()+2);
        }
    }
    return 0;
}



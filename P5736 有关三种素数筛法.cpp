#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){
    if(n==1) return false;
    if(n==2) return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    int len=0;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(isprime(temp)) arr[len++]=temp;
    }
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


//埃氏筛法：从2开始，将每个质数的倍数都标记成合数，以达到筛选素数的目的
int visit[maxn];  //maxn是需要打的素数表（布尔数组）
void Prime(){
    memset(visit,0,sizeof(visit)); //初始化都是素数，如果是素数的话就是0，不是素数才是1
    visit[0] = visit[1] = 1;  //0 和 1不是素数
    for (int i = 2; i <= maxn; i++) {
        if (!visit[i]) {         //如果i是素数，让i的所有倍数都不是素数
            for (int j = i*i; j <= maxn; j += i) { 
                visit[j] = 1;
            }
        }
    }
}

//欧拉筛法：在埃氏筛法的基础上，让每个合数只被它的最小质因子筛选一次，以达到不重复的目的。
vector<int> pri;
bool not_prime[N];

void pre(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!not_prime[i]) {
      pri.push_back(i);
    }
    for (int j = 0; j < pri.size(); ++j) {
      int pri_j = pri[j];
      if (i * pri_j > n) break;
      not_prime[i * pri_j] = true;
      if (i % pri_j == 0) {
        break;
      }
    }
  }
}
/*内层循环遍历 pri 向量中的每一个素数 pri_j。

如果 i * pri_j 大于 n，则跳出内层循环。因为我们需要标记的合数不能超过 n。

标记 i * pri_j 为合数，即 not_prime[i * pri_j] = true。

如果 i % pri_j == 0，说明 i 是 pri_j 的倍数，此时 i 可以表示为 pri_j * k，
其中 k 是某个整数。由于 pri 中的素数是从小到大排列的，
i 乘上更大的素数的结果一定会被 pri_j 的倍数筛掉，所以不需要继续标记，直接跳出内层循环。*/



//默写欧拉筛法
vector<int> pri;
bool not_prime[N];

void(int n){
    for(int i=2;i<=n;i++){
        if(not_prime[i]=false) pri.pushback(i);
        for(int j=0;j<pri.length();++j){
            int pri_j=pri[j];
            if(i*pri_j>n) break;
            not_prime[i*pri_j]=true;
            if(i%pri_j==0) break; 
        }
    }
}







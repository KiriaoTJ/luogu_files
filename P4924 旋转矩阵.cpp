//没写出来

// #include<bits/stdc++.h>
// using namespace std;
// int n,m,x,y,r,z;
// void rotate90(vector<vector<int>> &a,int x,int y,int r){
//     int n=2*r+1;
//     vector<vector<int>> temp(n, vector<int>(n));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             temp[i][j]=a[i+x-r][j+y-r];
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             a[x - r + i][y - r + j] = temp[n - 1 - j][i]; 
//         }
//     }
// }
// int main(){
//     cin>>n>>m;
//     vector<vector<int>> a(n+1, vector<int>(n+1));
//     int value=1;
//     for(int i=1;i<=n*n;i++){
//         for(int j=1;j<=n*n;j++){
//             a[i][j]=value++;
//         }
//     }
//     for(int i=0;i<m;i++){
//         cin>>x>>y>>r>>z;
//         if(z==0){ //顺时针旋转
//             rotate90(a,x,y,r);
//         }
//         else{ //逆时针旋转
//             rotate90(a,x,y,r);
//             rotate90(a,x,y,r);
//             rotate90(a,x,y,r);
//         }
//     }
//     for(int i=1;i<=n*n;i++){
//         for(int j=1;j<=n*n;j++){
//             cout<<a[i][j]<<' ';
//         }
//         cout<<endl;
//     }
// }

//题解


#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,r,z,a[505][505],b[505][505]; //b是临时数组
int main(){
	cin>>n>>m;
	int v=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=v++;
		}
	}
	for(int k=0;k<m;k++){
		cin>>x>>y>>r>>z;
		if(z==0){
			for(int i=x-r;i<=x+r;i++){
				for(int j=y-r;j<=y+r;j++){
					b[x-y+j][x+y-i]=a[i][j];
				}
			}
			for(int i=x-r;i<=x+r;i++){
				for(int j=y-r;j<=y+r;j++){
					a[i][j]=b[i][j];
				}
			}
		}
		else if(z==1){
			for(int i=x-r;i<=x+r;i++){
				for(int j=y-r;j<=y+r;j++){
					b[x+y-j][i+y-x]=a[i][j];
				}
			}
			for(int i=x-r;i<=x+r;i++){
				for(int j=y-r;j<=y+r;j++){
					a[i][j]=b[i][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
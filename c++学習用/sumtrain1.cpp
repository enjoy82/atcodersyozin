#include<iostream>
#include <algorithm>
using namespace std;

int a;
int DP[100][100];
int node[100][100];
int anslist[100];

int maxa(){
    int ma = 0;
    for(int i =0; i < a; i++){
        ma = max(ma, anslist[i]);
    }
    return ma;
}

int path(int count,int ans,int pos){
  ans = ans + node[count][pos];
  if(ans >= DP[count][pos]){
    DP[count][pos] = ans;
    if(count < a -1){
      path(count+1, ans, pos);
      path(count+1, ans, pos+1);
    }else{
      anslist[pos] = ans;
    }
  }
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i<n; i++){
    cin >> a;
    for(int l = 0; l < a; l++){
      for(int m =0; m <= l; m++){
        int mid;cin >> mid;
        node[l][m] = mid;DP[l][m] = mid;
      }
    }
    path(0, 0, 0);
    cout << maxa() << endl;
  }
  return 0;
}
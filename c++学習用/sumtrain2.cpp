#include<iostream>
#include <algorithm>
using namespace std;


int main(){
  int n,a;
  int DP[100][100];
  int node[100][100];
  cin >> n;
  for(int i = 0; i<n; i++){
    cin >> a;
    for(int l = 0; l < a; l++){
      for(int m =0; m <= l; m++){
        int mid;cin >> mid;
        node[l][m] = mid;DP[l][m] = mid;
      }
    }
    for(int n = a-2; n>=0; n--){
      for(int m = 0; m <= n; m++){
        node[n][m] = node[n][m] + max(node[n+1][m], node[n+1][m+1]);
      }
    }
    cout << node[0][0] << endl;
  }
  return 0;
}
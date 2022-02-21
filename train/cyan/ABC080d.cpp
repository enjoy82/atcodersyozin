#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, c; cin >> n >> c;
    vector<vector<int> > lis(c, vector<int>(200002, 0));
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        for(int i = a*2-1; i <= b*2; i++){
            lis[c-1][i] = 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < 200002; i++){
        int k = 0;
        for(int l = 0; l < c ;l++){
            k += lis[l][i];
       }
       ans = max(ans, k);
   }
   cout << ans << endl;
}
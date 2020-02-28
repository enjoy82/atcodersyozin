#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int h, w; cin >> h >> w;
    vector<vector<int> > change(10, vector<int>(10, 0));
    vector<vector<int> > lis(h, vector<int>(w, 0));
    for(int i = 0; i <= 9; i++){
        for(int l = 0; l <= 9; l++){
            cin >> change[i][l];
        }
    }
    for (int k = 0; k < 10; k++){
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                change[i][j] = min(change[i][j], change[i][k] + change[k][j]);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < h; i++){
        for(int l = 0; l < w; l++){
            int a; cin >> a;
            if(a == 1 || a == -1){
                continue;
            }else{
                ans += change[a][1];
            }
        }
    }
    cout << ans << endl;
}
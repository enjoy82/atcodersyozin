#include<bits/stdc++.h>
using namespace std;
#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)

int main(){
    int n; cin >> n;
    vector<string> lis(n);
    int ans = 0;
    REP(i, 0, n){cin >> lis[i];}
    REP(b, 0, n){
        vector<vector<char>> afterlis(n, vector<char>(n));
        REP(i, 0, n){
            REP(l, 0, n){
                afterlis[i][l] = lis[i][(l + b) % n];
            }
        }
        int f = 1;
        REP(i, 0, n){
            REP(l, 0, n){
                if(afterlis[i][l] != afterlis[l][i]){
                    f = 0;
                    i = n;
                    break;
                }
            }
        }
        ans +=
    }
    cout << ans * n << endl;
}
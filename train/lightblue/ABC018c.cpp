#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}


int main(){
    int h, w, k; cin >> h >> w >> k;
    vector<string> lis(h);
    vector<vector<int>> lis1(h, vector<int>(w));
    REP(i, 0, h){
        cin >> lis[i];
    }
    REP(i, 0, h){
        REP(l, 0, w){
            int up = 0, down = 0;
            int uy = i, dy = i;
            while(uy >= 0){
                if(lis[uy][l] == 'x'){
                    break;
                }else{
                    up++;
                }
                uy--;
            }
            while(dy < h){
                if(lis[dy][l] == 'x'){
                    break;
                }else{
                    down++;
                }
                dy++;
            }
            lis1[i][l] = min(up, down);
        }
    }
    int ans = 0;
    REP(i, k-1, h-k+1){
        REP(l, k-1, w-k+1){
            int f = 1;
            int c = 1;
            REP(j, l-(k-1), l+1){
                if(lis1[i][j] >= c){
                    c++;
                }else{
                    f = -1;
                    break;
                }
            }
            c -= 2;
            REP(j, l+1, l+(k-1)+1){
                if(lis1[i][j] >= c){
                    c--;
                }else{
                    f = -1;
                    break;
                }
            }
            if(f == 1){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
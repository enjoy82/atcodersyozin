#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int h, w, k; cin >> h >> w >> k;
    vector<string> lis(h);
    vector<vector<int> > llis(h, vector<int>(w, 0));
    int ans = 0;
    REP(i, 0, h){cin >> lis[i];}
    REP(i, 0, h){
        REP(l, 0, w){
            if(lis[i][l] == '#'){
                llis[i][l] = 1;
            }else{
                llis[i][l] = 2;
            }
        }
    }
    REP(i, 0, (1 << h)){
        REP(l, 0, (1 << w)){
            vector<vector<int> > cllis = llis;
            int ci = i;
            REP(j, 0, h){
                if(ci % 2 == 1){
                   // cout << "OK" << endl;
                    REP(a, 0, w){
                        cllis[j][a] = 3;
                    }
                }
                ci /= 2;
            }
            int cl = l;
            REP(j, 0, w){
                if(cl % 2 == 1){
                    REP(a, 0, h){
                        cllis[a][j] = 3;
                    }
                }
                cl /= 2;
            }
            int mid = 0;
            REP(a, 0, h){
                REP(b, 0, w){
                    if(cllis[a][b] == 1){
                        mid++;
                    }
                }
            }
            if(mid == k){ans++;}
        }
    }
    cout << ans << endl;
}
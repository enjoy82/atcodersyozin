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
    int c; cin >> c;
    vector<vector<int> > lis(c, vector<int>(3));
    REP(i, 0, c){
        cin >> lis[i][0] >> lis[i][1] >> lis[i][2];
        sort(ALL(lis[i]), greater<>());
    }
    int ans = 1e9;
    REP(i, 1, 101){
        REP(l, 1, 101){
            REP(k, 1, 101){
                vector<int> size(3);
                size[0] = i;
                size[1] = l;
                size[2] = k;
                sort(ALL(size), greater<>());
                int f = 1;
                REP(a, 0, c){
                    REP(b, 0, 3){
                        if(size[b] < lis[a][b]){
                            a = c;
                            f = 0;
                            break;
                        }
                    }
                }
                if(f == 1){
                    ans = min(ans, i*l*k);
                }
                size.clear();
            }
        }
    }
    cout << ans << endl;
}
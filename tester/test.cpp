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
    int d; cin >> d;
    vector<int> clis(26);
    vector<vector<int>> slis(d, vector<int>(26));
    vector<int> anslis(d);
    vector<int> prelas(26, 0);
    REP(i, 0, 26){cin >> clis[i];}
    REP(i, 0, d){
        int idx = 0, max = -1;
        REP(l, 0, 26){
            cin >> slis[i][l];
        }
        int key = -1 * 1e9;
        REP(j, 0, 26){
            int minus = 0;
            vector<int> las = prelas;
            las[j] = i+1;
            REP(k, 0, 26){
                minus += clis[k] * ((i+1) - las[k]);
            }
            if(slis[i][j] - minus > key){
                key = slis[i][j] - minus;
                anslis[i] = j;
            }
        }
    }
    vector<int> last(26, 0);
    int anspre = 0;
    REP(i, 0, d){
        last[anslis[i]] = i+1;
        anspre += slis[i][anslis[i]];
        int minus = 0;
        REP(l, 0, 26){
            minus += clis[l] * ((i+1) - last[l]);
        }
        anspre -= minus;
        //cout << anspre << endl;
    }
    REP(i, 0, 1e4){
        int from = rand() % 26;
        int to = rand() % 26;
        if(anslis[from] == to){continue;}
        int old = anslis[from];
        anslis[from] = to;
        int anspre1 = 0;
        //スコア計算
        REP(l, 0, d){
            last[anslis[l]] = l+1;
            anspre1 += slis[l][anslis[l]];
            int minus = 0;
            REP(j, 0, 26){
                minus += clis[j] * ((l+1) - last[j]);
            }
            anspre1 -= minus;
        }
        //cout << anspre1 << endl;
        if(anspre > anspre1){
            anslis[from] = old;
        }else{
            anspre = anspre1;
        }
    }
    REP(i, 0, d){
        cout << (anslis[i] + 1) % d << endl;
    }
    //cout << anspre << endl;
    return 0;
}
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

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, 1, -1, -1, 1, -1, 1, 0};

int main(){
    int h, w; cin >> h >> w;
    vector<string> lis(h);
    vector<vector<char> > anslis(h, vector<char>(w, '.'));
    REP(i, 0, h){cin >> lis[i];}
    REP(i, 0, h){
        REP(l, 0, w){
            int f = 1;
            REP(j, 0, 9){
                int nx = i + dx[j], ny = l + dy[j];
                if(nx >= 0 && ny >= 0 && nx < h && ny < w){
                    if(lis[nx][ny] == '#'){
                        continue;
                    }else{
                        f = 0;
                    }
                }else{
                    continue;
                }
            }
            if(f == 1){
                anslis[i][l] = '#';
            }
        }
    }
    vector<vector<char>> checklis(h, vector<char>(w, '.'));
    REP(i, 0, h){
        REP(l, 0, w){
            if(anslis[i][l] == '#'){
                REP(j, 0, 9){
                    int nx = i + dx[j], ny = l + dy[j];
                    if(nx >= 0 && ny >= 0 && nx < h && ny < w){
                        checklis[nx][ny] = '#';
                    }else{
                        continue;
                    }
                }
            }
        }
    }
    int f = 1;
    REP(i, 0, h){
        REP(l, 0, w){
            if(checklis[i][l] != lis[i][l]){
                f = 0;
                i = h;
                break;
            }
        }
    }
    if(f){
        cout << "possible" << endl;
        REP(i, 0, h){
            REP(l, 0, w){
                cout << anslis[i][l];
            }
            cout << endl;
        }
    }else{
        cout << "impossible" << endl;
    }
}
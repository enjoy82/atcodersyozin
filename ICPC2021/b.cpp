// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

//ordered_set 重複不可
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use set_function + find_by_order(select itr-num)

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}

template <class T>
inline vector<T> make_vec(size_t a, T val) {
    return vector<T>(a, val);
}
template <class... Ts>
inline auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec(ts...))>(a, make_vec(ts...));
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示
struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;

const long long LINF = 1LL << 60;
const int MINF = -1e9;

bool check(vector<int> &lis){
    REP(i,0,lis.size()){
        if(lis[i] == MINF){
            return false;
        }
    }
    return true;
}

int main(){
    int w, h;
    while(cin >> w){
        cin >> h;
        if(w == 0 && h == 0)
            break;
        vector<int> wlis(w, MINF), hlis(h, MINF);
        wlis[0] = 0;
        vector<vector<int> > grid(w, vector<int>(h, MINF));
        REP(i,0,w+h-1){
            int a, b, n; cin >> a >> b >> n;
            a--; b--;
            grid[a][b] = n;
        }
        int f = 1;
        REP(i,0,400){
            if(f == 1){
                REP(l,0,wlis.size()){
                    if(wlis[l] != MINF){
                        REP(k,0,h){
                            if(grid[l][k] != MINF){
                                hlis[k] = grid[l][k] - wlis[l];
                                REP(m, 0, wlis.size()){
                                    if(wlis[m] != MINF)
                                        grid[m][k] = wlis[m] + hlis[k];
                                }
                            }
                        }
                    }
                }
            }else if(f == -1){
                REP(l,0,hlis.size()){
                    if(hlis[l] != MINF){
                        REP(k,0,w){
                            if(grid[k][l] != MINF){
                                wlis[k] = grid[k][l] - hlis[l];
                                REP(m, 0, hlis.size()){
                                    if(hlis[m] != MINF)
                                        grid[k][m] = wlis[k] + hlis[m];
                                }
                            }
                        }
                    }
                }
            }
            /*
            REP(a,0,wlis.size()){
                REP(b,0,hlis.size()){
                    cout << grid[a][b] << " ";
                }
                cout << endl;
            }
            cout << "hlis ";
            REP(l,0,hlis.size()){
                cout << hlis[l] << " ";
            }
            cout << endl;
            cout << "wlis ";
            REP(l,0,wlis.size()){
                cout << wlis[l] << " ";
            }
            cout << endl;
            */
            f *= -1;
        }
        if(check(wlis) && check(hlis)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
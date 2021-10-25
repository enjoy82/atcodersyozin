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

int main(){
    int h;
    while(cin >> h){
        int w; cin >> w;
        if(h == 0 && w == 0){
            break;
        }
        vector<string> grid(h);
        REP(i,0,h){
            cin >> grid[i];
        }
        int dp[2][1<<(w+1)];
        int *crt = dp[0], *next = dp[1];
        crt[0] = 1;
        for(int i = h-1; i>=0; i--){
            for(int j = w-1; j >= 0; j--){
                for(int used = 0; used < (1<<(w+1)); used++){
                    cout <<  i << " " << j << " " << crt[0] << endl;
                    if( (used & 1) || grid[i][j] == '#'){
                        next[used] = crt[used & ~(1<<j)]; //おかなくていい
                    }else{
                        int res = 0;
                        if(j+1 < w && i+1 < h && !((used >> 1) & 1) && !((used >> w) & 1) && grid[i+1][j] == '.' && grid[i][j+1] == '.'){ //状態1
                            res += crt[used & ~(1<<(j+1)) & ~(1<<(w))];
                        }
                        if(j+1 < w && i+1 < h && !((used >> 1) & 1) && grid[i][j+1] == '.' && grid[i+1][j+1] == '.'){ //状態2
                            res += crt[used & ~(1<<(j+1))];
                        }
                        if(j+1 < w && i+1 < h && !((used >> w) & 1) && grid[i+1][j] == '.' && grid[i+1][j+1] == '.'){ //状態3
                            res += crt[used & ~(1<<(w))];
                        }
                        if(j < w && i+1 < h && !((used >> w) & 1)&& !((used >> (w-1)) & 1)  && grid[i+1][j-1] == '.' && grid[i+1][j] == '.'){ //状態4
                            res += crt[used & ~(1<<(w-1)) & ~(1<<(w))];
                        }
                        next[used] = res;
                    }
                }
                swap(crt, next);
            }
        }
        cout << crt[0] << endl;
    }
}
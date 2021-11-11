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

struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;

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

vector<int> arg_sort(vector<int> &lis){
    vector<int> idx(lis.size());
    iota(ALL(idx), 0);
    sort(ALL(idx), [&](auto &l, auto &r){
        return lis[l] < lis[r];
    });
    return idx;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const long long LINF = 1LL << 62;
const int INF = 1LL << 30;


vector<vector<int> > rotate(vector<vector<int> > &grids){
    int n = grids.size();
    vector<vector<int> > rotated(n, vector<int>(n));
    REP(i,0,n){
        REP(l,0,n){
            rotated[i][l] = grids[n-1-l][i];
        }
    }
    return rotated;
}

vector<vector<int> > shift(vector<vector<int> > &grids){
    int n = grids.size();
    int sx = 1e5, sy = 1e5;
    vector<vector<int> > shifted(n, vector<int>(n, 0));
    REP(i,0,n){
        REP(l,0,n){
            if(grids[i][l]){
                chmin(sx, i);
                chmin(sy, l);
            }
        }
    }
    
    REP(i,0,n){
        REP(l,0,n){
            if(grids[i][l])
                shifted[i-sx][l-sy] = grids[i][l];
        }
    }
    return shifted;
}

int check(vector<vector<int> > &grids, vector<vector<int> > &gridt){
    int n = grids.size();
    int f = 1;
    REP(i,0,n){
        REP(l,0,n){
            if(grids[i][l] != gridt[i][l])
                f = 0;
        }
    }
    return f;
}

int main(){
    int n; cin >> n;
    vector<vector<int> > grids(n, vector<int>(n, 0)), gridt(n, vector<int>(n, 0));
    REP(i,0,n){
        string s; cin >> s;
        REP(l,0,n){
            if(s[l] == '#')
                grids[i][l] = 1;
        }
    }
    REP(i,0,n){
        string s; cin >> s;
        REP(l,0,n){
            if(s[l] == '#'){
                gridt[i][l] = 1;
            }
        }
    }
    vector<vector<int> > shiftedt = shift(gridt);
    vector<vector<int> > rotated;
    int f = 0;
    REP(i,0,4){
        if(i == 0)
            rotated = rotate(grids);
        else
            rotated = rotate(rotated);
        vector<vector<int> > shifteds = shift(rotated);
        chmax(f, check(shifteds, shiftedt));
    }
    if(f)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
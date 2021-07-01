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


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

int h, w;

int solve(vector<string> &lis, vector<vector<int> > &check, int x, int y, int count){
    int mid = -1;
    REP(i,0,4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < h && ny < w && lis[nx][ny] == '.'){
            if(count >= 3 && check[nx][ny] == 0){
                chmax(mid, count + 1);
            }
            if(check[nx][ny] == 1000000){
                check[nx][ny] = count+1;
                chmax(mid, solve(lis, check, nx, ny, count+1));
                check[nx][ny] = 1000000;
            }
        }
    }
    return mid;
}

int main(){
    cin >> h >> w;
    int ans = -1;
    vector<string> lis(h);
    REP(i,0,h) cin >> lis[i];
    vector<vector<int> > check(h, vector<int>(w, 1000000));
    REP(i,0,h){
        REP(l,0,w){
            if(lis[i][l] != '#'){
                check[i][l] = 0;
                chmax(ans, solve(lis, check, i, l, 0));
                check[i][l] = 1000000;
            }
        }
    }
    cout << ans << endl;
}
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

void solve(){
    ll x, y, p, q; cin >> x >> y >> p >> q;
    ll train = 2*(x+y);
    ll taka = p + q;
    if(train >= taka){
        int f = 0;
        if((2 * x + 2 * y) % (p + q) == 0){
            f = 1;
        }
        ll now = x;
        ll n1 = (x - p) / (p + q);
        ll pp = (p + q) * n1 + p;
        ll pq = (p + q) * (n1+1);
        if(x <= pp && pp < x+y){
            cout << pp << endl;
            return;
        }else if(x <= pq && pq < x+y){
            cout << x << endl;
            return;
        }else if(f == 1){
            cout << "infinity" << endl;
            return;
        }
        ll n2 = 2*(x + y) / (p + q);
        ll dif = 2*(x + y) - (n2 * (p+q));
        ll ppdif = (p + q) * (n1+1) + p - x;
        ll pqdif = (p + q) * (n1+2) - x;
        ll k = (ppdif+dif-1) / dif;
        //ll kk = (pqdif+dif-1) / dif;
        ll kc = k * n2;
        ll pn = (p+q)*kc+p;
        ll pqn = (p+q)*(kc+1);
        if(2*(x+y)*k + x <= pn && pn < 2*(x+y)*k +x+y){
            cout << pn << endl;
            return;
        }else if(2*(x+y)*k + x  <= pqn && pqn < 2*(x+y)*k +x+y){
            cout << 2*(x+y)*k + x << endl;
            return;
        }else if(f == 1){
            cout << "infinity" << endl;
            return;
        }
    }else{
        int f = 0;
        if((p + q) % (2 * x + 2 * y) == 0){
            f = 1;
        }
        ll now = p;
        ll n1 = (p-x) / (2*(x + y));
        ll xx = 2*(x+y)+x;
        ll xy = 2*(x+y)+x+y;
        if(xx <= now && now < xy){
            cout << now << endl;
            return;
        }else if(xx <= p+q && p+q < xy){
            cout << xx << endl;
            return;
        }else if(f == 1){
            cout << "infinity" << endl;
            return;
        }
        ll n2 =  (p + q) / (2*(x + y));
        ll dif = (p+q) - (2*(x + y)*n2);
        ll xxdif = (2*(x+y)*(n2+1)) + x - p;
        ll xydif = (p + q) * (n1+2) - x;
        ll k = (xxdif+dif-1) / dif;
        ll kc = k + n2;
        ll xn = 2*(x+y)+x;
        ll xyn = 2*(x+y)+x+y;
        if(xn <= (p+q)*kc + p && (p+q)*(kc+1) < xyn){
            cout << (p+q)*kc + p << endl;
            return;
        }else if(xyn <= (p+q)*kc + p && (p+q)*(kc+1) < xyn){
            cout << xyn << endl;
            return;
        }else if(f == 1){
            cout << "infinity" << endl;
            return;
        }
    }
    
}

int main(){
    int t; cin >> t;
    REP(i,0 , t){
        solve();
    }
}
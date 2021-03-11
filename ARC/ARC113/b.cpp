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


ll Pow(ll  x, ll n, ll loop){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(x * x % loop, n / 2, loop);
  else
    return x * Pow(x, n - 1, loop) % loop;
}


int main(){
    int a, b, c; cin >> a >> b >> c;
    int aa = a % 10;
    int loop;
    if(aa == 0){
        cout << 0 << endl;
        return 0;
    }else if(aa == 1){
        cout << 1 << endl;
        return 0;
    }else if(aa == 2){
        loop = 4;
    }else if(aa == 3){
        loop = 4;
    }else if(aa == 4){
        loop = 2;
    }else if(aa == 5){
        cout << 5 << endl;
        return 0;
    }else if(aa == 6){
        cout << 6 << endl;
        return 0;
    }else if(aa == 7){
        loop = 4;        
    }else if(aa == 8){
        loop = 4;
    }else if(aa == 9){
        loop = 2;
    }
    int cc = Pow(b, c, loop);
    cc = (cc - 1 + loop) % loop;
    //cout << cc << endl;
    int now = aa;
    REP(i ,0 ,cc){
        now = (now * aa) % 10;
    }
    cout << now << endl;
}
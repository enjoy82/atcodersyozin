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

void ruiseki(vector<ll> &ru){
    REP(i,0,ru.size()-1){
        ru[i+1] = ru[i] + ru[i+1];
    }
}

int main(){
    ll n, k; cin >> n >> k;
    vector<vector<ll> > ru(3, vector<ll>(3*n+100, 0));
    ru[0][1]++;
    ru[0][n+1]--;
    ruiseki(ru[0]);
    REP(i,1,3){
        REP(l,1,3*n){
            ru[i][l+1] += ru[i-1][l];
            ru[i][l+n+1] -= ru[i-1][l];
        }
        ruiseki(ru[i]);
    }
    
    REP(i,0,11){
        cout << ru[2][i] << " ";
    }
    cout << endl;
    
   ruiseki(ru[2]);
   vector<ll> mid = ru[2];
   auto it = lower_bound(ALL(mid), k);
   int ind = it - mid.begin();
   int cc = k - mid[ind-1]; //mezasu
   int count = 0;
   REP(i,1,n+1){
       int low = i + 2;
       int high = i + 2 * n;
       if(low <= ind && high >= ind){
           count += min(abs(ind - i - low), abs((ind - i) - high)) + 1;
           if(count <= cc){
               oki = i;
               break;
           }
       }
   }
}
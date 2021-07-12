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

int main(){
    int n; cin >> n;
    vector<vector<int> > lis(n, vector<int>(2));
    REP(i,0,n){
        cin >> lis[i][0] >> lis[i][1];
    }
    vector<double> dp(n, 0);
    REP(i,1,n){
        dp[i] = dp[i-1];
        REP(l,0,i){
            double sump = 0.0;
            REP(k,lis[i][0], lis[i][1]+1){
                double lower = (double)max(min(k - lis[l][0] + 1, lis[l][1] - lis[l][0] + 1), 0);
                double upper = (double)max(min(lis[l][1] - k, lis[l][1] - lis[l][0] + 1) , 0);
                double p = upper / (lower + upper);
                sump += p / (double)(lis[i][1] - lis[i][0] + 1);
            }
            dp[i] += sump;
            //cout << sump << endl;
        }
    }
    cout << std::fixed << std::setprecision(15) << dp[n-1] << endl;
}

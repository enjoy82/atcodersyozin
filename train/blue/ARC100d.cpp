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
    vector<ll> ruiseki(n+1, 0), lis(n);
    REP(i, 0, n){
        cin >> ruiseki[i+1];
        lis[i] = ruiseki[i+1]; 
    }
    REP(i, 0 , n){
        ruiseki[i+1] = ruiseki[i] + ruiseki[i+1];
    }
    ll sum = ruiseki[n];
    int left = 0, right = 2;
    ll ans = 1e9;
    REP(i, 1, n-2){
        ll midsum = ruiseki[i+1];
        while(1){ //left
            ll midleftsum = ruiseki[left+1];
            if(left+2 == i+1){
                break;
            }
            ll midleftsum_next = ruiseki[left+2];
            if(abs(midsum - 2*midleftsum) > abs(midsum - midleftsum_next*2)){
                left++;
            }else{
                break;
            }
        }        
        chmax(right, i+1);
        ll midsum2 = sum - ruiseki[i+1];
        while(1){ //right
            ll midleftsum = ruiseki[right+1] - ruiseki[i+1];
            if(right+2 >= n){
                break;
            }
            ll midleftsum_next = ruiseki[right+2] - ruiseki[i+1];
            if(abs(midsum2 - 2*midleftsum) > abs(midsum2 - midleftsum_next*2)){
                right++;
            }else{
                break;
            }
        }
        ll ma = max({ruiseki[left+1], midsum - ruiseki[left+1], ruiseki[right+1] - ruiseki[i+1], sum - ruiseki[right+1]});
        ll mi = min({ruiseki[left+1], midsum - ruiseki[left+1], ruiseki[right+1] - ruiseki[i+1], sum - ruiseki[right+1]});
        //cout << ruiseki[right+1] - ruiseki[i+1] << sum - ruiseki[right+1] << endl;
        //cout << ma  <<  " " << mi << endl;
        chmin(ans, abs(mi-ma));
    }
    cout << ans << endl;
}
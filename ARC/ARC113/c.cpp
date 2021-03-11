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
    string s; cin >> s;
    ll ans = 0;
    int pre = 40;
    vector<int> count(26, 0);
    count[s[s.size()-1] - 'a']++;
    count[s[s.size()-2] - 'a']++;
    for(int i = s.size() -3; i >= 0; i--){
        if(s[i] == s[i+1] && s[i+1] != s[i+2]){
            //cout << i << endl;
            if(pre != (s[i] - 'a')){
                ans += s.size() - 2 - i - max(count[s[i] - 'a'] -  1, 0);
            }else{ //一致
                int mid = 0;
                REP(l, 0, 26){
                    if(l == (s[i] - 'a')){
                        continue;
                    }else{
                        mid += count[l];
                    }
                }
                ans += mid;
            }
            REP(i, 0, 26){
                count[i] = 0;
            }
            pre = s[i] - 'a';
            //cout << ans << endl;
        }else{
            count[s[i] - 'a']++;
        }
    }
    cout << ans << endl;
}
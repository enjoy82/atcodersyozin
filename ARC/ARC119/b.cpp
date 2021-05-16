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
string s, t; 

int solve(string ss, string tt){
    queue<int> stock, tar;
    int mid = 0;
    REP(i,0,ss.size()){
        if(ss[i] == '1' && tt[i] == '0'){
            stock.push(i);
        }else if(ss[i] == '0' && tt[i] == '1'){
            stock.pop();
            mid++;
        }else if(ss[i] == '0' && tt[i] == '0'){
            stock.pop();
            stock.push(i);
            mid++;
        }
    }
    return mid;
}

int main(){
    int n; cin >> n;
    cin >> s >> t;
    int count1 = 0, count2 = 0;
    REP(i,0,n){
        if(s[i] == '1') count1++;
        if(t[i] == '1') count2++;
    }
    if(count1 != count2){
        cout << -1 << endl;
        return 0;
    }
    queue<int> stock, tar, q0, cp;
    int ans = 0;
    int st = 0;
    REP(i,0,n){
        if(s[i] == '1' && t[i] == '0'){
            stock.push(i);
        }else if(s[i] == '0' && t[i] == '1'){
            tar.push(i);
        }
        if(stock.empty() && tar.empty()){
            st++;
        }
        if(!stock.empty() && !tar.empty() && stock.size() == tar.size()){
            string scp = s.substr(st, i-st+1);
            string tcp = t.substr(st, i-st+1);
            if(stock.front() < tar.front()){
                ans += solve(scp, tcp);
            }else{
                reverse(ALL(scp));
                reverse(ALL(tcp));
                ans += solve(scp, tcp);
            }
            stock = cp;
            tar = cp;
            q0 = cp;
            st = i+1;
        }
    }
    cout << ans << endl;
}
// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

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

int main(){
    string s; cin >> s;
    vector<ll> lis(s.size() + 10, 0), comlis(s.size() + 10, 0);
    int have = 5;
    ll ans = 0;
    ll combo = 0;
    int ch = 0;
    REP(i, 0, s.size()){
        have += lis[i];
        ch = max(ch-1, 0);
        if(i-1 >= 0){
            combo += comlis[i-1];
        }
        if(s[i] == 'N'){
            if(have < 1 || ch != 0){
                continue;
            }
            ch += 1;
            ans += 10 + (combo / 10) * 1;
            comlis[i + 1] += 1; 
            lis[i+7] += 1;
            have--;
        }else if(s[i] == 'C'){
            if(have < 3 || ch != 0){
                continue;
            }
            ch += 3;
            ans += 50 + (combo / 10) * 5;
            lis[i+9] += 3;
            comlis[i + 3] += 1; 
            have -= 3;
        }else{
            continue;
        }
    }
    cout << ans << endl;
}
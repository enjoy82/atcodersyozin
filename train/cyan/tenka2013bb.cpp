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
    ll q, l; cin >> q >> l;
    stack<Pll> st;
    ll have = 0;
    REP(i, 0, q){
        string s; cin >> s;
        if(s == "Push"){
            ll n, m; cin >> n >> m;
            have += n;
            if(have > l){
                cout << "FULL" << endl;
                return 0;
            }
            st.push(Pll(m, n));
        }else if(s == "Top"){
            if(have <= 0){
                cout << "EMPTY" << endl;
                return 0;
            }
            Pii k = st.top();
            cout << k.first << endl;
        }else if(s == "Pop"){
            ll n; cin >> n;
            if(have - n < 0){
                cout << "EMPTY" << endl;
                return 0;
            }
            have -= n;
            while(n != 0){
                Pll k = st.top();
                st.pop();
                ll num = k.second, val = k.first;
                if(num > n){
                    num -= n;
                    n = 0;
                    st.push(Pll(val, num));
                }else{
                    n -= num;
                }
            }
        }else if(s == "Size"){
            cout << have << endl;
        }
    }
    cout << "SAFE" << endl;
}
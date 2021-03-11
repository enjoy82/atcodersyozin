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
    ll n; cin >> n;
    string t; cin >> t;
    string aaa = "110";
    int f1 = 0;
    int k = 0;
    REP(i, 0, 3){
        int f2 = 1;
        REP(l, 0, n){
            if(t[l] != aaa[(l+i)%3]){
                f2 = 0;
            }
        }
        if(f2){
            f1 = 1;
            k = i;
        }
    }
    if(n == 1){
        if(t == "1"){
            cout << 20000000000 << endl;
        }else{
            cout << 10000000000 << endl;
        }
        return 0;
    }else if(n == 2){
        if(t == "00"){
            cout << 0 << endl;
            return 0;
        }
        cout << 10000000000 - (t == "01") << endl;
        return 0;
    }
    if(f1){
        ll a = 10000000000;
        if(n % 3 == 0){
            cout << a - n/3 + (k == 0) << endl;
        }else if(n % 3 == 1){
            cout << a - n/3 << endl;    
        }else{
            cout << a - n/3 - (k == 2) << endl;
        }
    }else{
        cout << 0 << endl;
        return 0;
    }
}
#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    string s; cin >> s;
    string a = "RUD", b = "LUD";
    for(int i = 0; i < s.size(); i+=2){
        int f = 1;
        REP(l, 0, 3){
            if(s[i] == a[l]){
                f = 0;
            }
        }
        if(f){
            cout << "No" << endl;
            return 0;
        }
    }

    for(int i = 1; i < s.size(); i+=2){
        int f = 1;
        REP(l, 0, 3){
            if(s[i] == b[l]){
                f = 0;
            }
        }
        if(f){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
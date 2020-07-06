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
    string s, t; cin >> s >> t;
    string at = "atcoder";
    if(s.size() != t.size()){
        cout << "You will lose" << endl;
        return 0;
    }else{
        REP(i, 0, s.size()){
            if(s[i] == t[i] && s[i] == '@'){
                continue;
            }
            if(s[i] == '@'){
                int f = 0;
                REP(l, 0, 7){
                    if(at[l] == t[i]){
                        f = 1;
                        break;
                    }
                }
                if(f == 0){
                    cout << "You will lose" << endl;
                    return 0;
                }
            }else if(t[i] == '@'){
                int f = 0;
                REP(l, 0, 7){
                    if(at[l] == s[i]){
                        f = 1;
                        break;
                    }
                }
                if(f == 0){
                    cout << "You will lose" << endl;
                    return 0;
                }
            }else if(s[i] != t[i]){
                cout << "You will lose" << endl;
                return 0;
            }
        }
    }
    cout << "You can win" << endl;
    return 0;
}
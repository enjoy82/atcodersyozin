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

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string abc = "abacaba";
    int count = 0;
    REP(i, 0, n-6){
        int f = 1;
        REP(l, 0, 7){
           if(s[i+l] == abc[l]){
                continue;
            }else{
                f = 0;
                break;
            } 
        }
        if(f == 1){
            count++;
        }
    }
    //cout << count << endl << s << endl;
    if(count == 1){
        cout << "Yes" << endl;
        REP(i, 0, n){
            if(s[i] == '?'){
                s[i] = 'z';
            }
        }
        cout << s << endl;
        return;
    }else if(count > 1){
        cout << "No" << endl;
        return;
    }
    //cout << "OK" << endl;
    //front
    string sc1 = s, sc2 = s;
    count = 0;
    REP(i, 0, n-6){
        int f = 1;
        REP(l, 0, 7){
            if(sc1[i+l] == abc[l] || sc1[i+l] == '?'){
                continue;
            }else{
                f = 0;
                break;
            }
        }
        if(f == 1){
            REP(l, 0, 7){
               sc1[i+l] = abc[l];
            }
            break;
        }
    }
    int cc = 0;
    REP(i, 0, n-6){
        int f = 1;
        REP(l, 0, 7){
           if(sc1[i+l] == abc[l]){
                continue;
            }else{
                f = 0;
                break;
            } 
        }
        if(f == 1){
            cc++;
        }
    }
    if(cc == 1){
        cout << "Yes" << endl;
        REP(i, 0, n){
            if(sc1[i] == '?'){
                sc1[i] = 'z';
            }
        }
        cout << sc1 << endl;
        return;
    }
    //cout << cc << endl << sc1 << endl;
    //back
    REP(i, 0, n-6){
        if(count == 1){
            break;
        }
        int f = 1;
        REP(l, 0, 7){
            //cout << sc2[n-1-i-l] << abc[6-l] << endl;
            if(sc2[n-1-i-l] == abc[6-l] || sc2[n-1-i-l] == '?'){
                continue;
            }else{
                f = 0;
                break;
            }
        }
        if(f == 1){
            REP(l, 0, 7){
               sc2[n-1-i-l] = abc[6-l];
            }
            break;
        }
    }
    //cout << sc2 << endl;
    cc = 0;
    REP(i, 0, n-6){
        int f = 1;
        REP(l, 0, 7){
           if(sc2[i+l] == abc[l]){
                continue;
            }else{
                f = 0;
                break;
            } 
        }
        if(f == 1){
            cc++;
        }
    }
    if(cc == 1){
        cout << "Yes" << endl;
        REP(i, 0, n){
            if(sc2[i] == '?'){
                sc2[i] = 'z';
            }
        }
        cout << sc2 << endl;
        return;
    }
    //cout << cc << endl << sc2 << endl;
    cout << "No" << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
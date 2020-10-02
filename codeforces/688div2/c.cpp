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
    int n, k; cin >> n >> k;
    string cs; cin >> cs;
    vector<string> s(n);
    REP(i, 0, n){
        s[i] = cs[i];
    }
    vector<int> lis;
    int f = 1;
    REP(i, 0, n){
        if(s[i] == "?"){
            lis.pb(i);
        }
    }
    int c1 = 0, c0 = 0;
    REP(i, 0, k){
        if(s[i] == "1"){
            c1++;
        }else if(s[i] == "0"){
            c0++;
        }
    }
    int ind = 0;
    if(c1 != c0){
        int c = abs(c1 - c0);
        string key;
        if(c1 > c0){
            key = "0";
        }else{
            key = "1";
        }
        REP(i, 0, c){
            if(ind >= lis.size() || lis[ind] + 1 > k){
                //cout << "OK" << endl;
                f = 0;
                break;
            }
            s[lis[ind]] = key; 
            ind++;
        }
        c1 = max(c1, c0);
        c0 = max(c1, c0);
    }
    REP(i, k, n){
        if(s[i-k] == "1"){
            c1--;
        }else if(s[i-k] == "0"){
            c0--;
        }
        if(s[i] == "1"){
            c1++;
        }else if(s[i] == "0"){
            c0++;
        }
        //cout << c1 << " " << c0 << endl;
        while(!(ind >= lis.size()) && lis[ind] <= i-k){
            ind++;
        }
        while(c1 > c0){
            if(ind >= lis.size() || lis[ind] > i){
                //cout << "OK1" << endl;
                //cout << lis[ind] << i << endl;
                f = 0;
                break;
            }
            s[lis[ind]] = "0";
            c0++;
            ind++;
        }
        while(c0 > c1){
            if(ind >= lis.size() || lis[ind]  > i){
                //cout << "OK2" << endl;
                f = 0;
                break;
            }
            s[lis[ind]] = "1";
            c1++;
            ind++;
        }
    }
    if(f){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
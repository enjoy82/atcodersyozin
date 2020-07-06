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
    vector<int> left(n), right(n);
    int blue = 0, straw = 0;
    map<int, int> difl;
    difl[0] = 0;
    REP(i, 0, n){
        cin >> left[n-i-1];
    }
    REP(i, 0, n){
        if(left[i] == 1){
            straw++;
        }else{
            blue++;
        }
        if(!difl.count(straw - blue)){
            //cout << i+1 << endl;
            //cout << straw << blue << endl;
            difl[straw-blue] = i + 1;
        }
    }
    REP(i, 0, n){
        cin >> right[i];
        if(right[i] == 1){
            straw++;
        }else{
            blue++;
        }
    }
    int dif = straw - blue;
    //cout << dif << endl;
    int mi = 1e9;
    if(difl.count(dif))
        mi = difl[dif];
    //cout << mi << endl;
    straw = 0, blue = 0;
    REP(i, 0, n){
        if(right[i] == 1){
            straw++;
        }else{
            blue++;
        }
        if(difl.count(dif - (straw - blue))){
            int mid =  difl[dif - (straw - blue)];
            mi = min(mid + i+1, mi);
        }
    }
    cout << mi << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
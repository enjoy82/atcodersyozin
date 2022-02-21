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
    int X, Y, Z, k; cin >> X >> Y >> Z >> k;
    vector<ll> alis(X), blis(Y), clis(Z);
    REP(i, 0, X){cin >> alis[i];}
    REP(i, 0, Y){cin >> blis[i];}
    REP(i, 0, Z){cin >> clis[i];}
    sort(ALL(alis), greater<>());
    sort(ALL(blis), greater<>());
    sort(ALL(clis), greater<>());
    map<ll, ll> mp;
    mp[0] = 1;
    priority_queue<Pll> pq;
    int count = 0;
    pq.push(Pll(alis[0]+blis[0]+clis[0], 0));
    while(count != k){
        count++;
        Pll k = pq.top();
        //cout << k.second << endl;
        pq.pop();
        cout << k.first << endl;
        ll z = k.second;
        ll a = z / 1e10;
        z -= a * 1e10;
        ll b = z / 1e5;
        z -= b * 1e5;
        ll c = z;
        ll aa = (a + 1) * 1e10 + b * 1e5 + c;
        if(a+1 < Z && mp[aa] == 0){
            //cout << aa << endl;
            ll aasum = alis[a+1] + blis[b] + clis[c];
            mp[aa]++;
            pq.push(Pll(aasum, aa));
        }
        ll bb = a * 1e10 + (b+1) * 1e5 + c;
        if(b+1 < Y && mp[bb] == 0){
            //cout << bb << endl;
            ll bbsum = alis[a] + blis[b+1] + clis[c];
            mp[bb]++;
            pq.push(Pll(bbsum, bb));
        }
        ll cc = a * 1e10 + b * 1e5 + (c+1);
        if(c+1 < Z && mp[cc] == 0){
            //cout << cc << endl;
            ll ccsum = alis[a] + blis[b] + clis[c+1];
            mp[cc]++;
            pq.push(Pll(ccsum, cc));
        }
    }
}
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

map<Pii, int> mp;
vector<vector<int> > imos;

porse(string s, int len, int left, int right, int count){
    if(mp.count(Pii(left, right))){
        return mp[Pii(right, left)];
    }
    if(len == 1){
        if(s[left] != alpha[count]){
            return 1;
        }else{
            return 0;
        }
    }
    int mid = (left + right) / 2;
    int front = porse(s, len/2, left, mid, count+1);
    int back = porse(s, len/2, mid, right, count+1);
    back += len/2  - (imos[mid][count] - imos[left][count]);
    front += len/2 - (imos[right][count] - imos[mid][count]);
    int res = min(back, front);
    mp[Pii(right, left)] = res;
    return res;
}

void solve(){
    mp.clear();
    int n; cin >> n;
    string s1; cin >> s1;
    imos = vector<vector<int> > (n+1, vector<int>(26, 0));
    REP(i, 0, n){
        imos[i+1] = imos[i];
        imos[i+1][s1[i] - 'a']++;
    }
    cout << porse(s1, n, 0, n, 0) << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
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
    int n; cin >> n;
    int ans = 0;
    vector<pair<string, int> > lis(n);
    map<string, int> mp;
    REP(i, 0, n){
        string s; cin >> s;
        int cc = s.size();
        lis[i] = {s, cc};
    }
    vector<int> flag(1e7, 0);
    vector<ll> H(1e7, 0);
    sort(ALL(lis), [](auto &x, auto &y){return x.second < y.second;});
    REP(i, 0, n){
        string key = lis[i].first;
        vector<vector<int> > imos(key.size()+1, vector<int>(26, 0));
        REP(l, 0, key.size()){
            imos[l+1] = imos[l];
            imos[l+1][key[l] - 'a']++;
        }
        string mid = "";
        ll hash = 0;
        for(int l = key.size(); l >= 0; l--){
            //string mid = key.substr(l, key.size() - l);
            if(flag[mid.size()+1] == 0){
                mid = key[l-1] + mid;
                hash = (hash * 100 + (key[l-1] - 'a')) % 200003;
                continue;
            }
            REP(k, 0, 26){
                ll hashi = (hash * 100 + (alpha[k] - 'a')) % 200003;
                if(H[hashi] == 0){
                    continue;
                }
                if(imos[l][k] > 0){
                    string t = alpha[k] + mid;
                    if(mp.count(t)){
                        ans += mp[t];
                    }else{
                        continue;
                    }
                }
            }
            mid = key[l-1] + mid;
            hash = (hash * 100 + (key[l-1] - 'a')) % 200003;
        }
        imos.clear();
        mp[key]++;
        flag[key.size()]++;
        H[hash]++;
    }
    cout << ans << endl;
}
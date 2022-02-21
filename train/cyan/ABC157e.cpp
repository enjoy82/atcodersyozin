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
    string s; cin >> s;
    vector<set<ll> > alset(26);
    REP(i, 0, n){
        int key = s[i] - 'a';
        alset[key].insert(i+1);
    }
    int q; cin >> q;
    REP(i, 0, q){
        int a; cin >> a;
        if(a == 1){
            int k; cin >> k;
            int key = s[k-1] - 'a';
            alset[key].erase(k);
            char x; cin >> x;
            alset[x-'a'].insert(k);
            s[k-1] = x;
            //cout << s << endl;
        }else{
            int s, e; cin >> s >> e;
            int count = 0;
            REP(l, 0, 26){
                if(alset[l].size() == 0)
                    continue;
                auto kk = alset[l].rbegin();
                if(*kk < s)
                    continue;
                auto it = alset[l].lower_bound(s);
                /*if( it - alset[l].begin() >= alset[l].size()){
                    continue;
                }*/
                if(*it <= e && *it >= s){
                    count++;
                }
            }
            cout << count << endl;
        }
    }
}
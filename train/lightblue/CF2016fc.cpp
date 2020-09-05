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
    int n, m; cin >> n >> m;
    vector<vector<int> > lang(m), people(n);
    vector<int> flag(n, 0), flag2(m, 0);
    flag[0] = 1;
    REP(i, 0, n){
        int k; cin >> k;
        REP(l, 0, k){
            int a; cin >> a;
            a--;
            lang[a].pb(i);
            people[i].pb(a);
        }
    }
    queue<Pii> q;
    q.push(Pii(0, 0));
    while(!q.empty()){
        Pii a = q.front();
        q.pop();
        int num = a.first;
        if(a.second == 0){
            REP(i, 0, people[num].size()){
                int next = people[num][i];
                if(flag2[next] == 0){
                    flag2[next] = 1;
                    q.push(Pii(next, 1));
                }
            }
        }else{
            REP(i, 0, lang[num].size()){
                int next = lang[num][i];
                if(flag[next] == 0){
                    flag[next] = 1;
                    q.push(Pii(next, 0));
                }
            }
        }
    }
    REP(i, 0, n){
        if(flag[i] == 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
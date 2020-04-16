#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int check(ll a){
    vector<int> flag(3, 0);
    string s = to_string(a);
    REP(i, 0, s.size()){
        if(s[i] == '3'){
            flag[0]++;
        }else if(s[i] == '5'){
            flag[1]++;
        }else if(s[i] == '7'){
            flag[2]++;
        }
    }
    REP(i, 0, 3){
        if(flag[i] == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    ll x; cin >> x;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    ll h[3] = {3, 5, 7};
    REP(i, 0, 3){
        pq.push(h[i]);
    }
    int ans = 0;
    while(1){
        ll mid = pq.top();
        if(mid > x){break;}
        pq.pop();
        REP(i, 0, 3){
            pq.push(mid*10 + h[i]);
        }
        if(x >= mid && check(mid) == 1){
            ans++;  
        }
    }
    cout << ans << endl;
}
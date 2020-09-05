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


ll Pow(ll  x, ll n, ll MOD){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(x * x % MOD, n / 2, MOD);
  else
    return x * Pow(x, n - 1, MOD) % MOD;
}


int main(){
    ll n, a;string k; cin >> n >> a >> k;
    vector<int> blis(n), flag(n, 0);
    a--;
    REP(i, 0, n){cin >> blis[i]; blis[i]--;}
    int key = a;
    if(k.size() <= 8){
        vector<ll> slis(10, 0);
        REP(i, 0, k.size()){
            slis[i] = k[i] - '0';
        }
        ll sum = 0;
        REP(i, 0, k.size()){
            sum += slis[k.size() - 1 - i] * Pow(10, i, 1e15);
        }
        for(int i = sum; i > 0; i--){
            key = blis[key];
        }
        cout << key+1 << endl;
        return 0;
    }
    flag[key] = 1;
    int count = 1;
    int step, first, start;
    while(1){
        int next = blis[key];
        if(flag[next] > 0){
            start = next;
            step = count - flag[next] + 1;
            first = flag[next] - 1;
            break;
        }else{
            key = next;
            count++;
            flag[next] = count;
        }
    }
    //cout << first << step << endl;
    vector<ll> slis(2e7, 0);
    REP(i, 0, k.size()){
        slis[i] = k[i] - '0';
    }
    ll sum = 0;
    int f = 1;
    REP(i, 0, k.size()){
        sum += slis[k.size() - 1 - i] * Pow(10, i, step);
        if(sum > first &&f == 1){
            f = 0;
            sum -= first;
        }
        sum %= step;
    }
    key = start;
    for(int i = sum; i > 0; i--){
        key = blis[key];
    }
    //cout << sum << endl;
    cout << key+1 << endl;
}
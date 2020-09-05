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

template<typename T>
vector<T> smallest_prime_factors(T n) {

    vector<T> spf(n + 1);
    for (int i = 0; i <= n; i++) spf[i] = i;


    for (T i = 2; i * i <= n; i++) {

        // 素数だったら
        if (spf[i] == i) {

            for (T j = i * i; j <= n; j += i) {

                // iを持つ整数かつまだ素数が決まっていないなら
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    return spf;
}

int main(){
    int n; cin >> n;
    vector<ll> lis(n);
    REP(i, 0, n){scanf("%lld", &lis[i]);}
    ll setwise = lis[0];
    REP(i, 1, n){
        setwise = gcd(setwise, lis[i]);
    }
    int f = 1;
    auto spf  = smallest_prime_factors(2 * 1e6);
    map<ll, int>mp;
    vector<int> flag(2 * 1e6, 0);
    REP(i, 0, n){
        ll cp = lis[i];
        while(cp != 1){
            int k = spf[cp];
            while(cp % k == 0){
                cp /= k;
            }
            flag[k]++;
            if(flag[k] != 1){
                f = 0;
            }
        }
    }
    if(f == 1){
        cout << "pairwise coprime" << endl;
    }else if(setwise == 1){
        cout << "setwise coprime" << endl;
    }else{
        cout << "not coprime" << endl;
    }
}
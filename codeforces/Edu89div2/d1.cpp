#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

int gcd(int a,int b){return b ? gcd(b,a%b) : a;}
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

vector<int> divisor(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}


int main(){
    int n; cin >> n;
    vector<int>ans1(n), ans2(n);
    REP(i, 0, n){
        int a;
        scanf("%d", &a);
        vector<int> r = divisor(a);
        if(r.size() <= 2){
            ans1[i] = -1;
            ans2[i] = -1;
            continue;
        }
        int d1 = r[1], d2 = r[2];
        if(gcd(d1+d2, a) == 1){
            ans1[i] = d1;
            ans2[i] = d2;
        }else{
            ans1[i] = -1;
            ans2[i] = -1;
        }
    }
    REP(i, 0, n){
        printf("%d ", ans1[i]);
    }
    printf("\n");
    REP(i, 0, n){
        printf("%d ", ans2[i]);
    }
    printf("\n");
}
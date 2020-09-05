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
    stack<Pll> st;
    REP(i, 0, n){
        ll a, num = 1;
        scanf("%lld", &a);
        while(!st.empty() && (st.top().first + a) * st.top().second < st.top().first * (st.top().second + num)){
            num += st.top().second;
            a += st.top().first;
            st.pop();
        }
        st.push(Pll(a, num));
    }
    vector<double> anslis;
    while(!st.empty()){
        double ans = (double)st.top().first / st.top().second;
        REP(i, 0, st.top().second){
            anslis.pb(ans);
        }
        st.pop();
    }
    REP(i, 0, n){
        printf("%.10f\n", anslis[n-1-i]);
    }
}
#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ll q, l; cin >> q >> l;
    ll Size = 0;
    int f = 0;
    stack<ll> st, ssize;
    REP(i, 0, q){
        string s; cin >> s;
        if(s == "Push"){
            ll n, m; cin >> n >> m;
            if(f == 1){continue;}
            st.push(m);
            ssize.push(n);
            Size += n;
            if(Size > l){
                cout << "FULL" << endl;
                f = 1;
            }
        }else if(s == "Top"){
            if(f == 1){continue;}
            if(st.empty()){
                cout << "EMPTY" << endl;
                f = 1;
            }else{
                cout << st.top() << endl;
            }
        }else if(s == "Size"){
            if(f == 1){continue;}
            cout << Size << endl;
        }else if(s == "Pop"){
            ll n; cin >> n;
            if(f == 1){continue;}
            while(n > 0 && Size > 0){
                if(ssize.empty()){
                    cout << "EMPTY" << endl;
                    f = 1;
                    break;
                }
                ll c = ssize.top();
                ll cp = c;
                c = max(0LL, c - n);
                if(c == 0){
                    Size -= cp;
                    st.pop();
                    n -= cp;
                }else{
                    Size -= n;
                    n = 0;
                    ssize.push(c);
                    break;
                }
            }
            if(n > 0 && Size <= 0 && f == 0){
                cout << "EMPTY" << endl;
                f = 1;
            }
        } 
    }
    if(f == 0)
        cout << "SAFE" << endl;
}
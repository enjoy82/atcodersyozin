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
    int a, b; cin >> a >> b;
    vector<vector<char> > anslis(100, vector<char>(100, '1'));
    int i = 0, l = 0;
    while(a > 1){
        a--;
        anslis[i][l] = '.';
        i+=2;
        if(i >= 100){
            i = 0;
            l+=2;
        }
    }
    i = 0, l = 99;
    while(b > 1){
        b--;
        anslis[i][l] = '#';
        i+=2;
        if(i >= 100){
            i = 0;
            l -=2;
        }
    }
    cout << 100 << " " << 100 << endl;
    REP(i, 0, 100){
        REP(l, 0, 50){
            if(anslis[i][l] == '1'){
                anslis[i][l] = '#';
            }
        }
        REP(l, 50, 100){
            if(anslis[i][l] == '1'){
                anslis[i][l] = '.';
            }
        }
    }
    REP(i, 0, 100){
        REP(l, 0, 100){
            cout << anslis[i][l];
        }
        cout << endl;
    }
}
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
    map<int, int> mp;
    int c4 = 0, c2 = 0;
    REP(i, 0, n){
        int a; cin >> a;
        mp[a]++;
        if(mp[a] % 4 ==  0){
            c2--;
            c4++;
        }else if(mp[a] % 2 == 0){
            c2++;
        }
    }
    int q; cin >> q;
    REP(i, 0, q){
        string s; cin >> s;
        if(s == "+"){
            int a; cin >> a;
            mp[a]++;
            if(mp[a] % 4 == 0){
                c2--;
                c4++;
            }else if(mp[a] % 2 == 0){
                c2++;
            }
            if(c4 >= 2 || (c4 == 1 && c2 >= 2)){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            int a; cin >> a;
            if(mp[a] % 4 == 0){
                c4--;
                c2++;
            }else if(mp[a] % 2 == 0){
                c2--;
            }
            mp[a]--;
            if(c4 >= 2 || (c4 == 1 && c2 >= 2)){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
}
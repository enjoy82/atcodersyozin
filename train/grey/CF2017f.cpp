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
    string s; cin >> s;
    int ll[6] = {1, 0, 0, 1, 1, 1};
    vector<int> lis;
    int ch = 0;
    string ss = "KIHBR";
    int count = 0;
    if(s.size() > 9){
        cout << "NO" << endl;
        return 0;
    }
    REP(i, 0, s.size()){
        if(ch >= 5 && s[i] != 'A'){
            cout << "NO" << endl;
            return 0;
        }
        if(ch < 5 && s[i] == ss[ch]){
            lis.pb(count);
            ch++;
            count = 0;
        }else if(s[i] == 'A'){
            count++;
        }else if(s[i] != ss[ch]){
            cout << "NO" << endl;
            return 0;
        }
    }
    lis.pb(count);
    if(lis.size() != 6){
        cout << "NO" << endl;
        return 0;
    }
    REP(i, 0, lis.size()){
        if(ll[i] < lis[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
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
    int x, y; cin >> x >> y;
    vector<int> lis;
    int count = 0;
    REP(i, 0, s.size()){
        if(s[i] == 'T'){
            lis.pb(count);
            count = 0;
            lis.pb(-1);
        }else{
            count++;
        }
    }
    if(count > 0){
        lis.pb(count);
    }
    /*REP(i, 0, lis.size()){
        cout << lis[i];
    }
    cout << endl;*/
    vector<set<int>> xdp(lis.size()+1, set<int>()), ydp(lis.size() + 1, set<int>());
    xdp[0].insert(lis[0]);
    if(lis.size() < 3){
        if(y == 0 && x == lis[0]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        return 0;
    }
    ydp[2].insert(lis[2]);
    ydp[2].insert(-1 * lis[2]);
    int xkey = 0, ykey= 2;
    REP(i, 4, lis.size()){
        if(i % 4 == 0){
            //cout << lis[i] << endl;
            for(auto x:xdp[i-4]){
                xdp[i].insert(x + lis[i]);
                xdp[i].insert(x - lis[i]);
            }
            xdp[i-4].clear();
           xkey = i;    
        }else if(i % 2 == 0){
            //cout << lis[i] << endl;
            for(auto x:ydp[i-4]){
                ydp[i].insert(x + lis[i]);
                ydp[i].insert(x - lis[i]);
            }
            ydp[i-4].clear();
            ykey = i;
        }
    }
    //cout << xkey << ykey << endl;
    if(xdp[xkey].find(x) != xdp[xkey].end() && ydp[ykey].find(y) != ydp[ykey].end()){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}

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


void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int x = 0, y = 0;
    map<tuple<int, int>, int> mp;
    mp[make_tuple(x, y)] = 1;
    int ansx = 0, ansy = 0, sum = 1e9;
    REP(i, 1, n+1){
        if(s[i-1] == 'L'){
            x++;
        }else if(s[i-1] == 'R'){
            x--;
        }else if(s[i-1] == 'U'){
            y++;
        }else{
            y--;
        }
        //cout << x << " " << y << endl;
        if(mp[make_tuple(x, y)] != 0){
            //cout << 100 << endl;
            if(sum > i+1 - mp[make_tuple(x, y)]){
                sum = i+1 - mp[make_tuple(x, y)];
                ansx = mp[make_tuple(x, y)];
                ansy = i;
            }
        }
        mp[make_tuple(x, y)] = i+1;
        //cout << mp[make_tuple(x, y)] << endl;
    }
    if(ansx == 0 && ansy == 0){
        cout << -1 << endl;
        return;
    }
    cout << ansx << " " << ansy << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
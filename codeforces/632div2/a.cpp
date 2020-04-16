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
    int h, w; cin >> h >> w;
    int f = 1;
    int count = 0;
    string s = "";
    if((h * w) % 2 == 1){
        while(1){
            if(f == 1){
                s = s + "B";
                f *= -1;
            }else{
                s = s + "W";
                f *= -1;
            }
            if(s.size() == w){
                cout << s << endl;
                count++;
                s = "";
            }
            if(count == h){break;}
        }
    }else{
        while(1){
            if(f == 1){
                s = s + "B";
                f *= -1;
            }else{
                s = s + "W";
                f *= -1;
            }
            if(s.size() == w){
                cout << s << endl;
                count++;
                s = "";
            }
            if(count == h-1){break;}
        }
        REP(i, 0, w){
            if(f == 1){
                s = s + "B";
                f *= -1;
            }else{
                s = s + "W";
                f *= -1;
            }
        }
        int f = 0;
        REP(i, 0, s.size()){
            if(s[i] == 'W' && f == 0){
                cout << "B";
                f = 1;
                continue;
            }
            cout << s[i];
        }
        cout << endl;
    }
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int main(){
    string s; cin >> s;
    vector<string> have;
    string mark[4] = {"S", "H", "D", "C"};
    string num[5] = {"10", "J", "Q", "K", "A"};
    int f = -1;
    while(1){
        string ss = "";
        if(s[1] == '1'){
            REP(i, 0, 3){ss = ss + s[i];}
            have.pb(ss);
            s.erase(0, 3);
        }else{
            REP(i, 0, 2){ss = ss + s[i];}
            have.pb(ss);
            s.erase(0, 2);
        }
        REP(i, 0, 4){
            REP(l, 0, 5){
                string key = mark[i] + num[l];
                int f1 = 0;
                REP(k, 0, have.size()){
                    if(key == have[k]){
                        f1 = 1;
                    }
                }
                if(f1 == 0){
                    break;
                }else{
                    if(l == 4){
                        f = i;
                    }
                }
            }
        }
        if(f != -1){
            break;
        }
    }
    int ansf = 1;
    REP(i, 0, have.size()){
        int ff = 1;
        REP(l, 0, 5){
            string key = mark[f] + num[l];
            if(have[i] == key){
                ff = 0;
            }
        }
        if(ff){
            cout << have[i];
            ansf = 0;
        }
    }
    if(ansf){
        cout << 0;
    }
    cout << endl;
}
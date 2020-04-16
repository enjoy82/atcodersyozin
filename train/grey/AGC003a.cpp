#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    string s; cin >> s;
    int n = s.size();
    int nc = 0, wc = 0, sc = 0, ec = 0;
    REP(i, 0, n){
        if(s[i] == 'N'){
            nc++;
        }else if(s[i] == 'W'){
            wc++;
        }else if(s[i] == 'S'){
            sc++;
        }else{
            ec++;
        }
    }
    if((min(wc, ec) == 0 && max(wc, ec) != 0) || (min(nc, sc) == 0 && max(nc, sc) != 0)){
        cout << "No" << endl;
        return 0;
    }/*else if(wc == 0 && wc == 0){
        if(nc % sc == 0 || sc % nc == 0){
            cout << "Yes" << endl;
            return 0;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }else if(nc == 0 && sc == 0){
        if(wc % ec == 0 || ec % wc == 0){
            cout << "Yes" << endl;
            return 0;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }
    if((wc % ec == 0 || ec % wc == 0) && (nc % sc == 0 || sc % nc == 0)){
        cout << "Yes" << endl;
        return 0;
    }*/
    cout << "Yes" << endl;
}
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
    vector<ll> alis(n), blis(n);
    REP(i, 0, n){cin >> alis[i];}
    REP(i, 0, n){cin >> blis[i];}
    int f1 = 0, f2 = 0;
    if(alis[0] != blis[0]){
        cout << "NO" << endl;
        return;
    }
    REP(i, 0, n-1){
        if(alis[i] == 1){
            f1++;
        }else if(alis[i] == -1){
            f2++;
        }
    }
    //cout << f1 << f2 << endl;
    int flag = 1;
    for(int i = n-1; i >= 0; i--){
        if(i != n-1){
            if(alis[i] == 1){
                f1--;
            }else if(alis[i] == -1){
                f2--;
            }
        }
        if(f1 > 0 && f2 > 0){

        }else if(f1 > 0 && f2 == 0){
            if(blis[i] < alis[i]){
                flag = -1;
            }
        }else if(f2 > 0 && f1 == 0){
            if(blis[i] > alis[i]){
                flag = -1;
            }
        }else{
            if(blis[i] != alis[i]){
                flag = -1;
            }
        }
        //cout << f1 << f2 << endl;
    }
    if(flag == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
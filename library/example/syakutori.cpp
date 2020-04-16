#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ll n, k; cin >> n >> k;
    ll ans = 0, sum = 0;
    vector<ll> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    int  r = 0; //rを滑らすので計算量落ちる
    REP(l, 0, n){//lを固定
        while(sum < k){
            if(r == n){
                break;
            }else{
                sum += lis[r];
                r++;
            }
        }
        if(sum < k){
            break;
        }
        ans += n-r+1;
        sum -= lis[l];
    }
    cout << ans << endl;
}
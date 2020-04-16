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

int main(){
    int k; cin >> k;
    priority_queue<ll, vector<ll>,  greater<ll>> q;
    REP(i, 1, 10){
        q.push(i);
    }
    int count = 0;
    while(1){
        ll c = q.top();
        //cout << c << endl;
        q.pop();
        count++;
        if(count == k){
            cout << c << endl;
            return 0;
        }
        ll k = c % 10;
        if(k-1 >= 0){
            q.push(c * 10 + (k-1));
        }
        q.push(c*10 + k);
        if(k+1 <= 9){
            q.push(c * 10 + (k+1));
        }
    }
}
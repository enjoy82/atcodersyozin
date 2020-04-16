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
    int n, m; cin >> n>> m;
    vector<int> lis(n);
    double sum = 0;
    REP(i, 0, n){cin >> lis[i]; sum += lis[i];}
    double k = (sum*1.0) / (4.0*m);
    int count = 0;
    REP(i, 0, n){
        if(lis[i] >= k){
            count++;
        }
    }
    if(count >= m){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
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

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

ld p;

ld func(ld x){
    return x + p*pow(2, -x/1.5);
}

int main(){
    cin >> p;
    ld left = 0.0;
    ld right = 1e15;
    while(right - left > 0.0000000001){
        ld mid_left = left*2.0/3.0 + right/3.0;
        ld mid_right = left/3.0 + right*2.0/3.0;
        if(func(mid_left) >= func(mid_right)){
            left = mid_left;
        }else{
            right = mid_right; 
        }
    }
    cout << std::fixed << std::setprecision(15) << func(right) << endl;
}
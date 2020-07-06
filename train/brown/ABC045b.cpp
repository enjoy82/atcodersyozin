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

int main(){
    string a, b, c; cin >> a >> b >> c;
    int ai = 0, bi = 0, ci = 0, f = 0;
    while(1){
        if(f == 0){
            if(ai == a.size()){
                cout << "A" << endl;
                return 0;
            }
            f = a[ai] - 'a';
            ai++;
        }else if(f == 1){
            if(bi == b.size()){
                cout << "B" << endl;
                return 0;
            }
            f = b[bi] - 'a';
            bi++;
        }else{
            if(ci == c.size()){
                cout << "C" << endl;
                return 0;
            }
            f = c[ci] - 'a';
            ci++;
        }
    }
}
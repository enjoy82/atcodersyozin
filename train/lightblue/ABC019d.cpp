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
    int mi = 1, ma = 100;
    vector<vector<int> > lis(101, vector<int>(2, -1));
    int x = 0, y = 0;
    REP(i, 0, 50){
        if(1500 - x - 2 * ma < 0){
            x = 0;
            y += 210;
        }
        lis[ma][0] = x, lis[ma][1] = y;
        lis[mi][0] = x, lis[mi][1] = y + 2 * ma;
        x += 2 * ma;
        ma--;
        mi++;
    }
    REP(i, 1, 101){
        cout << lis[i][0] + i  << " " << lis[i][1] + i  << endl;
    }
}
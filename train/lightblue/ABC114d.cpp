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
    int n; cin >> n;
    vector<int> div(101, 0);
    REP(i, 2, n+1){
        int k = i, l = 2;
        while(l*l <= k){
            if(k % l == 0){
                k /= l;
                div[l]++;
            }else{
                l++;
            }
        }
        div[k]++;
    }
    int c1 = 0, c2 = 0, c4 = 0, c14 = 0, c24 = 0, c74 = 0;
    REP(i, 2, n+1){
        if(div[i] >= 2){c2++;}
        if(div[i] >= 4){c4++;}
        if(div[i] >= 14){c14++;}
        if(div[i] >= 24){c24++;}
        if(div[i] >= 74){c74++;}
    }
    cout << ((c4*(c4-1))/2) * (c2-2) + c14*(c4-1) + c24*(c2-1) + c74  << endl;
}
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
    string s; cin >> s;
    string aki = "KIHBR";
    vector<int> lis(5, 0);
    int start = 0, l = 0, f = 1;
    REP(i, 0, 5){
        while(l < s.size() && ski[i] != s[l]){
            l++;
        }
        lis[i] = l;
        l++;
    }
    if(lis[0] >= 2 || (s[0] != 'A' && s[0] != 'K'){
        f = 0;
    }
    if(f == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
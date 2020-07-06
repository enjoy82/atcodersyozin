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

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n, m; cin >> n >> m;
    vector<string> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    vector<int> al(26, 0);
    REP(i, 0, n){
        REP(l, 0, m){
            al[(lis[i][l] - 'a')]++;
        }
    }
    int c4 = 0, c2 = 0, c1 = 0;
    c4 = (n - (n % 2)) / 2 * (m-(m%2)) / 2;
    c2 = (n % 2) *  (m-(m%2)) / 2 + (m % 2) *  (n-(n%2)) / 2;
    c1 = (n%2) * (m%2);
    int count4 = 0, count2 = 0;
    REP(i, 0, 26){
        while(al[i] >=4 && c4 > count4){
            al[i] -= 4;
            count4++;
        }
    }
    REP(i, 0, 26){
        while(al[i] >=2 && c2 > count2){
            al[i] -= 2;
            count2++;
        }
    }
    if(c4 == count4 && c2 == count2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
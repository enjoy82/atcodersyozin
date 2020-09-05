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
    int n; cin >> n;
    vector<int> array(n);
    vector<int> bitlis(40, 0);
    REP(i, 0, n){
        int a; cin >> a;
        array[i] = a;
        REP(l, 0, 40){
            if((a & 1) == 1){
                bitlis[l]++;
            }
            a = a >> 1;
        }
    }
    int max = 0, idx = 0;
    REP(i, 0, n){
        int a = array[i];
        int mid = 0;
        REP(l, 0, 40){
            if((a & 1) == 1 && bitlis[l] == 1){
                mid += (1 << l); 
            }
            a = a >> 1;
        }
        //cout << mid << endl;
        if(chmax(max, mid)){
            idx = i;
        }
    }
    cout << array[idx] << " ";
    REP(i, 0, n){
        if(i == idx) continue;
        cout << array[i] << " ";
    }
}
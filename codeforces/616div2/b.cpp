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

void solve(){
    int n; cin >> n;
    vector<int> lis(n), clis(n), clis1(n);
    REP(i, 0, n){cin >> lis[i];}
    clis1 = lis;
    int f = 1;
    REP(i, 0, n-1){
        if(clis1[i+1] < clis1[i]){
            continue;
        }else{
            clis1[i+1] = clis1[i]-1;
            if(clis1[i+1] < 0 || clis1[i+1] > lis[i+1]){
                f = 0;
                break;
            }
        }
    }
    if(f == 1){
        cout << "Yes" << endl;
        return;
    }
    clis = lis;
    clis[0] = 0;
    int key = 1e9;
    REP(i, 0, n-1){
        if(clis[i] < clis[i+1]){
            clis[i+1] = clis[i] + 1;
        }else if(clis[i] == clis[i+1]){
            if(clis[i] < clis[i]){
                clis[i]++;
            }else{
                clis[i+1]--;
                if(clis[i+1] < 0){
                    cout << "No" << endl;
                    return;
                }
            }
            key = i;
            break;
        }else{
            key = i;
            break;
        }
    }
    REP(i, key, n-1){
        if(clis[i] > clis[i+1]){
            continue;
        }else{
            clis[i+1] = clis[i] - 1;
            if(clis[i+1] < 0 || clis[i+1] > lis[i+1]){
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
    return;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
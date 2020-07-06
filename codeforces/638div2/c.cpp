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

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> lis(26, 0);
    REP(i, 0, n){
        lis[s[i]-'a']++;
    }
    int c = k, count = 0;
    int i = 0;
    for(; i < 26; i++){
        if(lis[i] != 0){
            count++;
            c -= lis[i];
        }
        if(c <= 0){break;}
    }
    if(count >= 2){
        cout << alpha[i] << endl;
    }else if(k == 1){
        REP(i, 0, 26){
            REP(l, 0, lis[i]){
                cout << alpha[i];
            }
        }
        cout << endl;
    }else{
        string s;
        REP(i, 0, 26){
            if(lis[i] != 0){
                lis[i] -= k;
                s = alpha[i];
                break;
            }
        }
        int key;
        REP(i, 0, 26){
            if(lis[i] != 0){
                key = i;
                break;
            }
        }
        int f = 1;
        REP(i, 0, 26){
            if(lis[i] != 0 && i != key){
                f = 0;
                break;
            }
        }
        if(f == 1){
            cout << s;
            REP(i, 0, 26){
                if(lis[i] != 0){
                    if(lis[i] % k == 0){
                        REP(l, 0, lis[i]/k){
                            cout << alpha[i];
                        }
                    }else{
                        REP(l, 0, lis[i]/k+1){
                            cout << alpha[i];
                        }
                    }
                }
            }
            cout << endl;
        }else{
            cout << s;
            REP(i, 0, 26){
                REP(l, 0, lis[i]){
                    cout << alpha[i];
                }
            }
            cout << endl;
        }
    }
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}
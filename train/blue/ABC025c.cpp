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

vector<vector<int> > blis(2, vector<int>(3));
vector<vector<int> > clis(3, vector<int>(2));
vector<int> temp(9, -1);
int sum = 0, ans = 0;

int solve(int n, vector<int> a){
    if(n == 9){ //直大のポイント計算
        int res = 0;
        REP(i, 0, 2){
            REP(l, 0, 3){
                if(a[i*3+l] == a[(i+1)*3+l]){
                    res += blis[i][l];
                }
                if(a[l*3+i] == a[l*3+i+1]){
                    res += clis[l][i];
                }
            }
        }
        return res;
    }else{
        int res = 0;
        REP(i, 0, 9){
            if(a[i] == -1){
                a[i] = n % 2;
                int tmp = solve(n+1, a); //9番手までとりあえず打つ点数つける
                a[i] = -1; //戻す
                if(n % 2 == 1){
                    tmp = sum - tmp;
                }
                res = max(res, tmp);
            }
        }
        return (n%2 == 0? res : sum-res);
    }
}

int main(){
    REP(i, 0, 2){
        REP(l, 0, 3){
            cin >> blis[i][l];
        }
    }
    REP(i, 0, 3){
        REP(l, 0, 2){
            cin >> clis[i][l];
        }
    }

    REP(i, 0, 2){
        REP(l, 0, 3){
            sum += blis[i][l] + clis[l][i];
        }
    }
    ans = solve(0, temp);
    cout << ans << endl << sum-ans << endl;
}
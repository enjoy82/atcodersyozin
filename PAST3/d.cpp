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

int main(){
    int n; cin >> n;
    vector<vector<vector<int> > > lis(n, vector<vector<int>>(5, vector<int>(3, 0)));
    REP(i, 0, 5){
        string s; cin >> s;
        int number = 0;
        REP(l, 1, s.size()-1){
            if(l % 4 == 0){
                number++;
                continue;
            }
            if(s[l] == '#'){
                lis[number][i][(l-1)%4]++;
            }
        }
    }
    vector<vector<vector<int> > > numberlis(10, vector<vector<int>>(5, vector<int>(3, 0)));
    vector<vector<int> > lis0(5, vector<int>(3, 0));
    lis0[0][0]++;
    lis0[0][1]++;
    lis0[0][2]++;
    lis0[1][0]++;
    lis0[1][2]++;
    lis0[2][0]++;
    lis0[2][2]++;
    lis0[3][0]++;
    lis0[3][2]++;
    lis0[4][0]++;
    lis0[4][1]++;
    lis0[4][2]++;
    numberlis[0] = lis0;

    vector<vector<int> > lis1(5, vector<int>(3, 0));
    lis1[0][1]++;
    lis1[1][0]++;
    lis1[1][1]++;
    lis1[2][1]++;
    lis1[3][1]++;
    lis1[4][0]++;
    lis1[4][1]++;
    lis1[4][2]++;
    numberlis[1] = lis1;

    vector<vector<int> > lis2(5, vector<int>(3, 0));
    lis2[0][0]++;
    lis2[0][1]++;
    lis2[0][2]++;
    lis2[1][2]++;
    lis2[2][0]++;
    lis2[2][1]++;
    lis2[2][2]++;
    lis2[3][0]++;
    lis2[4][0]++;
    lis2[4][1]++;
    lis2[4][2]++;
    numberlis[2] = lis2;

    vector<vector<int> > lis3(5, vector<int>(3, 0));
    lis3[0][0]++;
    lis3[0][1]++;
    lis3[0][2]++;
    lis3[1][2]++;
    lis3[2][0]++;
    lis3[2][1]++;
    lis3[2][2]++;
    lis3[3][2]++;
    lis3[4][0]++;
    lis3[4][1]++;
    lis3[4][2]++;
    numberlis[3] = lis3;

    vector<vector<int> > lis4(5, vector<int>(3, 0));
    lis4[0][0]++;
    lis4[0][2]++;
    lis4[1][0]++;
    lis4[1][2]++;
    lis4[2][0]++;
    lis4[2][1]++;
    lis4[2][2]++;
    lis4[3][2]++;
    lis4[4][2]++;
    numberlis[4] = lis4;

    vector<vector<int> > lis5(5, vector<int>(3, 0));
    lis5[0][0]++;
    lis5[0][1]++;
    lis5[0][2]++;
    lis5[1][0]++;
    lis5[2][0]++;
    lis5[2][1]++;
    lis5[2][2]++;
    lis5[3][2]++;
    lis5[4][0]++;
    lis5[4][1]++;
    lis5[4][2]++;
    numberlis[5] = lis5;

    vector<vector<int> > lis6(5, vector<int>(3, 0));
    lis6[0][0]++;
    lis6[0][1]++;
    lis6[0][2]++;
    lis6[1][0]++;
    lis6[2][0]++;
    lis6[2][1]++;
    lis6[2][2]++;
    lis6[3][0]++;
    lis6[3][2]++;
    lis6[4][0]++;
    lis6[4][1]++;
    lis6[4][2]++;
    numberlis[6] = lis6;

    vector<vector<int> > lis7(5, vector<int>(3, 0));
    lis7[0][0]++;
    lis7[0][1]++;
    lis7[0][2]++;
    lis7[1][2]++;
    lis7[2][2]++;
    lis7[3][2]++;
    lis7[4][2]++;
    numberlis[7] = lis7;

    vector<vector<int> > lis8(5, vector<int>(3, 0));
    lis8[0][0]++;
    lis8[0][1]++;
    lis8[0][2]++;
    lis8[1][0]++;
    lis8[1][2]++;
    lis8[2][0]++;
    lis8[2][1]++;
    lis8[2][2]++;
    lis8[3][0]++;
    lis8[3][2]++;
    lis8[4][0]++;
    lis8[4][1]++;
    lis8[4][2]++;
    numberlis[8] = lis8;

    vector<vector<int> > lis9(5, vector<int>(3, 0));
    lis9[0][0]++;
    lis9[0][1]++;
    lis9[0][2]++;
    lis9[1][0]++;
    lis9[1][2]++;
    lis9[2][0]++;
    lis9[2][1]++;
    lis9[2][2]++;
    lis9[3][2]++;
    lis9[4][0]++;
    lis9[4][1]++;
    lis9[4][2]++;
    numberlis[9] = lis9;

    /*REP(i, 0, 10){
        REP(j, 0, 5){
            REP(k, 0, 3){
                cout << lis[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }*/

    REP(i, 0, n){
        REP(l, 0, 10){
            int f = 1;
            REP(j, 0, 5){
                REP(k, 0, 3){
                    if(numberlis[l][j][k] != lis[i][j][k]){
                        f = 0;
                        j = 5;
                        break;
                    }
                }
            }
            if(f == 1){
                cout << l;
                break;
            }
        }
    }
    cout << endl;
    return 0;
}
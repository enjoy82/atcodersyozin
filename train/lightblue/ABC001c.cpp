#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int main(){
    vector<double> chs(15), che(15);
    string lis[15] = {"NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
    double lis1[12] = {0.0, 0.3, 1.6, 3.4, 5.5, 8.0, 10.8, 13.9, 17.2, 20.8, 24.5, 28.5};
    double lis2[12] = {0.2, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8, 17.1, 20.7, 24.4, 28.4, 32.6};
    double cc = 0.0;
    REP(i, 0, 15){
        cc += 22.50;
        chs[i] = cc - 11.25;
        che[i] = cc + 11.25;
    }
    double d, w; cin >> d >> w;
    d /= 10;
    w = round(w / 60 * 10) / 10;
    //cout << d << w << endl;
    if(lis1[0] <= w && lis2[0] >= w){
        cout << "C" << " " << 0 << endl;
        return 0;
    }
    int f = 0;
    REP(i, 0, 15){
        if(chs[i] <= d && che[i] >= d){
            cout << lis[i] << " ";
            f = 1;
            break;
        }
    }
    if(f == 0){
        cout << "N" << " ";
    }
    REP(i, 1, 12){
        if(lis1[i] <= w && lis2[i] >= w){
            cout << i << endl;
            return 0;
        }
    }
    cout << 12 << endl;
}
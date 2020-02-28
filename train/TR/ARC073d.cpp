#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> v0, v1, v2, v3;

int main(){
    ll n, W; cin >> n >> W;
    int e = 1, f = 0, g = 0, h = 0; 
    ll minw, midv;
    cin >> minw >> midv;
    v0.push_back(midv);
    for(int i = 1; i < n; i++){
        ll w, mid;
        cin >> w>> mid;
        if(w == minw){
            e++;
            v0.push_back(mid);
        }else if(w == minw+1){
            f++;
            v1.push_back(mid);
        }else if(w == minw+2){
            g++;
            v2.push_back(mid);
        }else if(w == minw+3){
            h++;
            v3.push_back(mid);
        }
    }
    sort(v0.begin(), v0.end(), greater<ll>());
    sort(v1.begin(), v1.end(), greater<ll>());
    sort(v2.begin(), v2.end(), greater<ll>());
    sort(v3.begin(), v3.end(), greater<ll>());
    //cout<< e << f << g << h << endl;
    ll ans = 0;
    for(int a = 0; a < e+1; a++){
        for(int b = 0; b < f+1; b++){
            for(int c = 0; c < g+1; c++){
                for(int d = 0; d < h+1; d++){
                    //cout << a << b << c << d<< endl;
                    if(a*minw +b*(minw+1) + c*(minw+2) + d*(minw+3) <= W){
                        ll dd = 0;
                        for(int aa = 0; aa < a; aa++){
                            dd += v0[aa];
                        }
                        for(int aa = 0; aa < b; aa++){
                            dd += v1[aa];
                        }
                        for(int aa = 0; aa < c; aa++){
                            dd += v2[aa];
                        }
                        for(int aa = 0; aa < d; aa++){
                            dd += v3[aa];
                        }
                        //cout << dd << endl;
                        ans = max(dd, ans);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
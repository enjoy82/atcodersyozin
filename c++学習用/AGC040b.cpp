#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<ll> L(n), R(n);
    vector<ll> dif(n);
    ll maxdif= 0, ind;
    for(int i = 0; i < n; i++){
        cin >> L[i] >> R[i];
        dif[i] = R[i] - L[i];
        if(dif[i] > maxdif){
            maxdif = dif[i];
            ind = i;
        }
    }
    ll l = L[ind], r = R[ind];
    maxdif = 0;
    ll ind2;
    vector<ll> kukan(n);
    for(int i = 0; i < n; i++){
        if(i == ind){continue;}
        ll LL = max(L[i], l);
        ll RR = min(R[i], r);
        kukan[i] = (r - l) - (RR - LL);
        if(maxdif < kukan[i]){
            maxdif = kukan[i];
            ind2 = i;
        }
    }
    ll l2 = L[ind2], r2 = R[ind2];
    //cout << l2 << r2 << endl;
    for(int i = 0; i < n; i++){
        if(i == ind || i == ind2){continue;}
        ll k1 = r-l - (min(r, R[i]) - max(l, L[i]));
        ll k2 = r-l -(min(r2, R[i]) - max(l2, L[i]));
        if(k1 > k2){
            r = min(r, R[i]);
            l = max(l, L[i]);
        }else{
            r2 = min(r2, R[i]);
            l2 = max(l2, L[i]);
        }
        //cout << r << l << endl << r2 << l2 << endl;
    }
    cout << r2- l2 + r - l + 2 << endl;
}
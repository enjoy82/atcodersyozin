#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> tlis(n), alis(n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> tlis[i] >> alis[i];
    }
    ll tpre = 1, apre = 1;
    for(int i = 0; i < n; i++){
        if(tpre <= tlis[i] && apre <= alis[i]){
            tpre = tlis[i];
            apre = alis[i];
        }else{
            ll k1 = apre / alis[i], k2 = tpre / tlis[i];
            if(apre % alis[i] != 0){
                k1++;
            }
            if(tpre % tlis[i] != 0){
                k2++;
            }
            ll k = max(k1, k2);
            apre = alis[i] * k;
            tpre = tlis[i] * k;
        }
    }
    cout << apre + tpre << endl;
}
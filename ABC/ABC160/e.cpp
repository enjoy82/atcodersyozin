#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll x, y, a, b, c; cin >> x >> y >> a >> b >> c;
    ll ans = 0;
    vector<ll> lisa(a+1, 0), lisb(b+1, 0), lisc(c+1, 0);
    for(int i = 0; i < a; i++){
        cin >> lisa[i];
    }
    for(int i = 0; i < b; i++){
        cin >> lisb[i];
    }
    for(int i = 0; i <c; i++){
        cin >> lisc[i];
    }
    sort(lisa.begin(), lisa.end(), greater<>());
    sort(lisb.begin(), lisb.end(), greater<>());
    sort(lisc.begin(), lisc.end(), greater<>());
    for(int i = 0; i < x; i++){
        ans += lisa[i];
    }
    for(int i = 0; i < y; i++){
        ans += lisb[i];
    }
    //cout << ans << endl << endl;
    int aidx = a, bidx = b, cidx = 0;
    while(1){
        //cout << lisa[aidx] << "@" << lisb[bidx] << endl;
        if((lisa[aidx-1] - lisc[cidx]) > 0 && (lisa[aidx-1] - lisc[cidx]) > 0 && abs(lisa[aidx-1] - lisc[cidx]) > abs(lisb[bidx-1] - lisc[cidx])){
            ans -= lisa[aidx-1];
            ans += lisc[cidx];
            aidx--;
            cidx++;
            //cout << ans << endl;
        }else if((lisa[aidx-1] - lisc[cidx]) > 0){
                ans -= lisb[bidx-1];
                ans += lisc[cidx];
                bidx--;
                cidx++;
                //cout << ans << endl;
            
        }
        //cout << lisa[aidx] << lisb[bidx] <<  lisc[cidx] << endl;
        int k = min({lisa[aidx], lisb[bidx], lisc[cidx]});
        if(k = lisc[cidx] || cidx >= c){
            break;
        }
    }
    cout << ans << endl;
}
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int h, w, d; cin >> h >> w >> d;
    vector<ll> lis(h*w+1);
    for(int i = 0; i < h; i++){
        for(int l = 0; l < w; l++){
            int mid;
            cin >> mid;
            lis[mid] = i * 1000 + l; //i is x, l is y
        }
    }
    int q; cin >> q;
    vector<ll> ruiseki(h*w+1);
    for(int i = 0; i <= d; i++){
        ruiseki[i] = 0;
    }
    for(int i = d+1; i <= h*w; i++){
        ruiseki[i] = ruiseki[i-d] + abs(lis[i]/1000-lis[i-d]/1000)+abs(lis[i]%1000-lis[i-d]%1000);
        //cout << i << " " << ruiseki[i] << endl;
    }
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        cout << ruiseki[r] - ruiseki[l] << endl;
    }
    return 0;
}
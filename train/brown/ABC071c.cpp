#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<ll> lis(n);
    for(int i = 0; i < n; i++){
        cin >> lis[i];
    }
    sort(lis.begin(), lis.end(), greater<>());
    ll max1 = 0, max2 = 0;
    for(int i = 0; i < n-1; i++){
        if(max1 == 0 && lis[i] == lis[i+1]){
            max1 = lis[i];
            i += 2;
        }
        if(i > n-1){break;}
        if(max2 == 0 && lis[i] == lis[i+1]){
            max2 = lis[i];
        }
    }
    cout << max1 * max2 << endl;
}
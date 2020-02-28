#include<bits/stdc++.h>
typedef long long ll;
using namespace std;



int main(){
    int mod = 1000000007;
    int n; cin >> n;
    ll ans = 1; 
    vector<int> flag(n+1, 0);
    for(int i = 2; i <= n; i++){
        int mid = i;
        int k = 2;
        while(1){
            if(mid % k == 0){
                flag[k]++;
                mid = mid / k;
                k = 2;
            }else{
                k++;
            }
            if(k > mid){
                break;
            }
        }
    }
    for(int l = 2; l <= n; l++){
        if(flag[l] != 0){
            ans =  (ans * (flag[l]+1)) % mod;                    
        }
    }
    cout << ans << endl;
}
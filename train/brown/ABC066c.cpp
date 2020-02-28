#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<ll> lis(n);
    for(int i = 0; i < n; i++){
        cin >> lis[i];
    }
    int count = 0;
    int k = n-1;
    while(1){
        cout << lis[k] << " ";
        count++;
        k -= 2;
        if(k < 0){
            if(n % 2 == 0) k = 0;
            else k = 1;
            break;
        }
    }
    while(count != n){
        cout << lis[k] << " ";
        count++;
        k += 2;
    }
    return 0;
}
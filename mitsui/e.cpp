#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    ll k = 1000000007;
    int n; cin >> n;
    vector<int> lis(n);
    for(int i = 0; i < n; i++){
        cin >> lis[i];
    }
    ll ans = 1;
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < n; i++){
        int f = 0;
        if(lis[i] == a){
            f++;
        }
        if(lis[i] == b){
            f++;
        }
        if(lis[i] == c){
            f++;
        }

        if(lis[i] == a){
            a++;
        }else if(lis[i] == b){
            b++;
        }else if(lis[i] == c){
            c++;
        }
        ans = (ans * f) % k;
    }
    cout << ans << endl;
}
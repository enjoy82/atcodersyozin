#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll h, a;  cin >> h >> a;
    ll sum = 0;
    for(int i = 0; i < a; i++){
        ll mid; cin >> mid;
        sum += mid;
    }
    if(h <= sum){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
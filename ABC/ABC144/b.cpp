#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    for(int i = 9; i > 1; i--){
        if(n % i == 0){
            n = n / i;
            break;
        }
    }
    if(n < 10){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
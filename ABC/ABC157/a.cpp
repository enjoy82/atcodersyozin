#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    if(n % 2 == 0){
        cout << n / 2;
    }else{
        cout << n / 2 + 1;
    }
}
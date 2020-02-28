#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int x; cin >> x;
    int y = (x % 100);
    if(y % 5 == 0){
        y = y/5;
    }else{
        y = y/5+1;
    }
    x = x / 100;
    if(x >= y){
        cout << 1 << endl;
        return 0;
    }else{
        cout << 0;
    }
}
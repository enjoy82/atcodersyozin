# include<iostream>
# include<vector>
#include<algorithm>
#include<cstdlib>
#include <math.h>
using namespace std;

int main(){
    int mod = 2019;
    int l, r;cin >> l >> r;
    if(r-l >= 2019){cout << 0 << endl;return 0;}
    l = l%mod;
    r = r%mod;
    if(l>=r){
        cout << 0 << endl;
        return 0;
    }
    int min = 3000;
    for(int i = l; i<r; i++){
        for(int k = i+1; k<=r; k++){
            int res = (i*k)% mod;
            if(res < min){min = res;}
        }
    }
    cout << min << endl;
}
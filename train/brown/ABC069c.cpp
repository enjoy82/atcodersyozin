#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    int count2 = 0, count4 = 0, count0 = 0;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        if(a % 4 == 0){
            count4++;
        }else if(a % 2 == 0){
            count2++;
        }else{
            count0++;
        }
    }
    if(n % 2 == 1 && (count4 == count0-1) && count2 == 0){
        cout << "Yes" << endl;
        return 0;
    }
    if(n % 2 == 1 && (count4 == count0-1) && count2 != 0){
        cout << "No" << endl;
        return 0;
    }
    if(count4 >= count0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
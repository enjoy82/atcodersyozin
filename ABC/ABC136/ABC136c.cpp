#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    if(n == 1){cout << "Yes" << endl;return 0;}
    vector<long long int > a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    a[0] -= 1;
    for(int i = 0 ; i < n-1; i++){
        long long int mid = a[i+1] - a[i];
        if(mid >= 1){
            a[i+1] -= 1;
        }else if(mid == 0){
        }else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int an = n/2;
    cout << a[an]-a[an-1] << endl;
}
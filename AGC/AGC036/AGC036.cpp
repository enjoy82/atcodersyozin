#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long int s; cin >> s;
    long long int x2, y2, x3;
    x3 = ceil(pow(s, 0.5));
    y2 = ceil(pow(s, 0.5));
    x2 = x3*y2 - s;
    cout << 0 <<" " <<  0 <<" "<< x2 << " " << y2 << " "<< x3 << " " << 1 << endl;
}
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    double a, b, x, ta; cin >> a >> b >> x;
    if(x <= a * a * b / 2){
        ta = a * b * b / (2 * x);
    }else{
        x = a * a * b - x;
        ta = 2 * x / (a * a * a);
    }
    double ans = atan(ta) * 180.00000000 / 3.141592;
    cout << setprecision(9)<< ans << endl;
}
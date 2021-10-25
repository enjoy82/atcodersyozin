#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}

ll extGcd(ll X, ll Y, ll &p, ll &q) {  
    if (Y == 0) { p = 1; q = 0; return X; }  
    ll d = extGcd(Y, X%Y, q, p);  
    q -= X/Y * p;  
    return d;  
}


int main() {
    ll X = 27182818, Y = 10000000, a, b;
    extGcd(X, Y, a, b);
    cout << a << "・" << X << " + " \
         << b << "・" << Y << " = " \
         << gcd(X, Y) << endl;
}
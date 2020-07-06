#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

int counter = 0;
int gcd(int a, int b) {
    if (b == 0) return a;
    counter++;
    return gcd(b, a%b);
}

int main(){
    int k; cin >> k;
    k--;
    int a = 2, b = 1;
    while(k != 0){
        int c = a + b;
        b = a; a = c;
        k--;
    }
    cout << a << " " << b << endl;
}
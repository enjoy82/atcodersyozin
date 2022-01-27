#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

vector<vector<ll>> det = {{1801, 840, 2889}, {465, 213, 741}, {225, 105, 361}};

ll get_det_by_mod(vector<vector<ll>> array, ll mod){
    return (((det[0][0] * det[1][1] * det[2][2]) % mod) + ((det[0][1] * det[1][2] * det[2][0]) % mod) + ((det[0][2] * det[1][0] * det[2][1]) % mod) \
     - ((det[0][2] * det[1][1] * det[2][0]) % mod) - ((det[0][1] * det[1][0] * det[2][2]) % mod) - ((det[0][0] * det[1][2] * det[2][1]) % mod
     ) + (3*mod)) % mod;
}

ll get_det(vector<vector<ll>> array){
    return (det[0][0] * det[1][1] * det[2][2]) + (det[0][1] * det[1][2] * det[2][0]) + (det[0][2] * det[1][0] * det[2][1]) \
     - (det[0][2] * det[1][1] * det[2][0]) - (det[0][1] * det[1][0] * det[2][2]) - (det[0][0] * det[1][2] * det[2][1]);
}

int main(){
    ll ans_by_mod15 = get_det_by_mod(det, 15) % 15;
    ll ans = get_det(det);
    cout << "currect det : " <<  ans  << endl << "det by mod15 : " << ans_by_mod15 << endl;
}
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

vector<vector<ll>> det = {{32, 49, 42}, {25, 31, 18}, {11, 19, 23}};
const ll mod19 = 19;
const ll mod23 = 23;
const ll mod31 = 31;

int main(){
    ll ans = (det[0][0] * det[1][1] * det[2][2]) + (det[0][1] * det[1][2] * det[2][0]) + (det[0][2] * det[1][0] * det[2][1]) \
     - (det[0][2] * det[1][1] * det[2][0]) - (det[0][1] * det[1][0] * det[2][2]) - (det[0][0] * det[1][2] * det[2][1]);
    ll ans_mod19 = (((det[0][0] * det[1][1] * det[2][2]) % mod19) + ((det[0][1] * det[1][2] * det[2][0]) % mod19) + ((det[0][2] * det[1][0] * det[2][1]) % mod19) \
     - ((det[0][2] * det[1][1] * det[2][0]) % mod19) - ((det[0][1] * det[1][0] * det[2][2]) % mod19) - ((det[0][0] * det[1][2] * det[2][1]) % mod19) + (3 * mod19)) % mod19;
    ll ans_mod23 = (((det[0][0] * det[1][1] * det[2][2]) % mod23) + ((det[0][1] * det[1][2] * det[2][0]) % mod23) + ((det[0][2] * det[1][0] * det[2][1]) % mod23) \
     - ((det[0][2] * det[1][1] * det[2][0]) % mod23) - ((det[0][1] * det[1][0] * det[2][2]) % mod23) - ((det[0][0] * det[1][2] * det[2][1]) % mod23) + (3 * mod23)) % mod23;
    ll ans_mod31 = (((det[0][0] * det[1][1] * det[2][2]) % mod31) + ((det[0][1] * det[1][2] * det[2][0]) % mod31) + ((det[0][2] * det[1][0] * det[2][1]) % mod31) \
     - ((det[0][2] * det[1][1] * det[2][0]) % mod31) - ((det[0][1] * det[1][0] * det[2][2]) % mod31) - ((det[0][0] * det[1][2] * det[2][1]) % mod31) + (3 * mod31)) % mod31;
    cout << "currect det : " << ans << endl << "det mod 19 : " << ans_mod19 << endl << "det mod 23 : " << ans_mod23 << endl << "det mod 31 : " << ans_mod31 << endl;;
}
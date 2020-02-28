#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int na, nb; cin >> na >> nb;
    vector<int> a(na), b(nb);
    double count = 0;
    for(int i = 0; i < na; i++){
        cin >> a[i];
    }
    for(int i = 0; i < nb; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < na; i++){
        if(binary_search(b.begin(), b.end(), a[i])){
            count++;
        }
    }
    cout << count / (na+nb-count) << endl;
}
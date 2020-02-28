#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


class UnionFind{
    public:
        vector<int> uni;
        UnionFind(int s) : uni(s, -1) { }
 
       //頂点aが所属するグループを調べる
        int root(int a)
        {
            if (uni[a] < 0) return a;
            return uni[a] = root(uni[a]);
        }
    
        //頂点aと頂点bを繋ぐ。もともと同じグループの時falseを返す
        bool connect(int a,int b)
        {
            a = root(a);
            b = root(b);
            if (a == b) return false;
    
            if (uni[a] > uni[b])
            {
                a ^= b;
                b ^= a;
                a ^= b;
            }
    
            uni[a] = uni[a] + uni[b];
            uni[b] = a;
            return true;
        }
    
        //頂点a,bが同じグループであるかを調べる
        bool isConnect(int a,int b)
        {
            return root(a) == root(b);
        }
    
        //頂点aを含むグループの頂点数を調べる
        int size(int a)
        {
            return -uni[root(a)];
        }
    
    };

int main(){
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int n; cin >> n;
        vector<int> a(n);
        UnionFind un(n+1); //宣言
        for(int l = 0; l < n; l++){
            cin >> a[l];
        }
        for(int l = 0; l < n; l++){
            un.connect(a[l], a[a[l] - 1]);
        }
        for(int l = 0; l < n; l++){
            cout << un.size(a[l]) << " ";
        }
        cout << endl;
    }
}

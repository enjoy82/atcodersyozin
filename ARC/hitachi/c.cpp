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


struct edge{
    int s, t;
};

int main(){
    int n; cin >> n;
    vector<vector<int> > tree(n+1);
    vector<vector<int> > tree2(n+1);
    vector<int> treelist(n+1, -1);
    vector<vector<int> > pairlis(n+1);
    vector<edge> lis;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        edge e = {a, b};
        lis.push_back(e);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> anslis(n+1, -1);
    for(int i = 1; i <= n; i++){
        anslis[i] = i % 3;
    }
    int num = 0;
    for(int i = 0; i < n-1; i++){
        int p1 = lis[i].s, p2 = lis[i].t;
        vector<int> midlis, midlis2;
        for(int l = 0; l < tree[p1].size(); l++){
            if(tree[p1][l] == p2){
                continue;
            }
            for(int k = 0; k < tree[p2].size(); k++){
                if(tree[p2][k] == p1){
                    continue;
                }
                int x = max(tree[p1][l], tree[p2][k]), y = min(tree[p1][l], tree[p2][k]);
                if(anslis[x] == anslis[y]){
                    int c = anslis[x]; anslis[x] = anslis[x-1]; anslis[x-1] = c;
                }
            }
        } 
    }
    int t0 = 0, t1 = 0, t2 = 0;
    for(int i = 1; i <= n; i++){
        if(anslis[i] == 1){
            anslis[i] = t1 * 3 + 1;
            t1++;
        }else if(anslis[i] == 2){
            anslis[i] = t2 * 3 + 2;
            t2++;
        }else if(anslis[i] == 0){
            anslis[i] = t0 * 3 + 3;
            t0++;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << anslis[i] << " ";
    }
}
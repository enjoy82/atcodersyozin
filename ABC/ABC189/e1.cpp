// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)

#define ZERO(a) memset(a,0,sizeof(a))

ll C[301010],D[301010];

const int MAT=3;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);v[0][0]=v[1][1]=v[2][2]=1;};}; //

Mat mulmat(Mat a,Mat b,int n=MAT) {
	int x,y,z; Mat r;
	REP(x,0,n) REP(y,0,n) r.v[x][y]=0;
	REP(x,0,n) REP(z,0,n) REP(y,0,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
	}
	return r;
}

Mat M[301010];


Mat hoge(int c,ll d) {
	Mat m;
	if(c==1) { //90
		m.v[0][0]=m.v[1][1]=0;
		m.v[0][1]=1;
		m.v[1][0]=-1;
	}
	if(c==2) { //-90
		m.v[0][0]=m.v[1][1]=0;
		m.v[0][1]=-1;
		m.v[1][0]=1;
	}
	if(c==3) { //x p
		m.v[0][0]=-1;
		m.v[0][2]=2*d;
	}
    if(c == 4){ // y p
        m.v[1][1]=-1;
        m.v[1][2]=2*d;
    }
	return m;
}


int main() {
    int N; cin >> N;
    vector<vector<ll> > lis(N, vector<ll>(2, 0));
    REP(i, 0, N){
        cin >> lis[i][0] >> lis[i][1];
    }
    int m; cin >> m;
	REP(i,0,m) {
		cin>>C[i];
		if(C[i]==3) {cin>>D[i];}
        if(C[i]==4) {cin>>D[i];}
	}
	
	REP(i, 0, m){
		M[i+1]=mulmat(hoge(C[i],D[i]), M[i]);
	}
    int q; cin >> q;
    REP(i, 0, q){
        int a, b; cin >> a >> b;
        ll PX = lis[b-1][0], PY = lis[b-1][1];
        cout<<(M[a].v[0][0]*PX+M[a].v[0][1]*PY+M[a].v[0][2])<<" "<<(M[a].v[1][0]*PX+M[a].v[1][1]*PY+M[a].v[1][2])<<endl;
    }
}
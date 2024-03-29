#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Real = double;
constexpr Real EPS = 1e-10;
constexpr Real INF = 1e18;
const Real PI = acos(-1);

using P = complex<Real>;
int sgn(const Real a) {
    return (a < -EPS ? -1 : (a > EPS ? +1 : 0));
}

inline bool EQ(Real a, Real b) {
    return (abs(a - b) < EPS);
}

inline Real Get_Value(Real a) {
    return (EQ(a, 0) ? 0 : a);
}

istream &operator>>(istream &is, P &p) {
    Real a, b;
    is >> a >> b;
    p = P(a, b);
    return is;
}
ostream &operator<<(ostream &os, P &p) {
    return os << fixed << setprecision(12) << Get_Value(p.real()) << " " << Get_Value(p.imag());
}

P operator*(const P &p, const Real &d) {
    return P(real(p) * d, imag(p) * d);
}

bool operator==(const P &p, const P &q) {
    return (EQ(p.real(), q.real()) && EQ(p.imag(), q.imag()));
}

Real dot(const P &a, const P &b) {
    // ベクトル a,b の内積
    return (a.real() * b.real() + a.imag() * b.imag());
}

Real cross(const P &a, const P &b) {
    // 外積
    return a.real() * b.imag() - a.imag() * b.real();
}

struct Line {
    // 直線
    P a, b;

    Line() = default;

    Line(P a, P b) : a(a), b(b) {}

    Line(Real A, Real B, Real C) // Ax + By = C
    {
        if(EQ(A, 0))
            a = P(0, C / B), b = P(1, C / B);
        else if(EQ(B, 0))
            b = P(C / A, 0), b = P(C / A, 1);
        else
            a = P(0, C / B), b = P(C / A, 0);
    }

    friend ostream &operator<<(ostream &os, Line &p) {
        return os << p.a << " to " << p.b;
    }

    friend istream &operator>>(istream &is, Line &a) {
        return is >> a.a >> a.b;
    }
};

struct Segment : Line {
    // 線分
    Segment() = default;
    Segment(P a, P b) : Line(a, b) {}
};

struct Circle {
    // 円 p が中心 r が半径
    P p;
    Real r;
    Circle() = default;
    Circle(P p, Real r) : p(p), r(r){};
};

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
// 点の回転方向
int ccw(const P &a, P b, P c) {
    b = b - a, c = c - a;
    if(cross(b, c) > EPS) return +1;  // "COUNTER_CLOCKWISE" CがベクトルABの半時計方向にある
    if(cross(b, c) < -EPS) return -1; // "CLOCKWISE" CがベクトルABの時計方向にある
    if(dot(b, c) < 0) return +2;      // "ONLINE_BACK" Cが直線AB上かつAの方向にある
    if(norm(b) < norm(c)) return -2;  // "ONLINE_FRONT" Cが直線AB上かつBの方向にある
    return 0;                         // "ON_SEGMENT" Cが線分AB上に乗っている
}

bool is_orthogonal(const Line &a, const Line &b) {
    // 2直線の直交判定
    // 2つのベクトルの内積が0なら直交
    return EQ(dot(a.a - a.b, b.a - b.b), 0.0);
}

bool is_parallel(const Line &a, const Line &b) {
    // 2直線の平行判定
    // 2つのベクトルの外積が0なら平行
    return EQ(cross(a.b - a.a, b.a - b.b), 0.0);
}

bool is_point_on_line(const P &a, const P &b, const P &c) {
    // 点cが直線a,b上にあるかどうか
    // ab ベクトルと ac ベクトルが平行なら点cは直線a,b上にある
    // 3点は同一直線状にあるともいえる
    return EQ(cross(b - a, c - a), 0.0);
}

bool intersect(const Segment &s, const Segment &t) {
    // 線分同士の交差判定
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

bool intersect(const Segment &s, const P &p) {
    return ccw(s.a, s.b, p) == 0;
}

P projection(const Line &s, const P &p) {
    Real t = dot(s.b - s.a, p - s.a) / norm(s.a - s.b);
    return s.a + (s.b - s.a) * t;
}

P projection(const Segment &s, const P &p) {
    return projection((Line)s, p);
}

P refrection(const Line &s, const P &p) {
    return (projection(s, p) - p) * 2.0 + p;
}

P refrection(const Segment &s, const P &p) {
    return refrection((Line)s, p);
}

Real distance(const P &p, const P &q) {
    return Get_Value(abs(p - q));
}

Real distance(const Segment &s, const P &p) {
    P r = projection(s, p);
    if(intersect(s, r)) {
        return distance(r, p);
    } else {
        return min(distance(s.a, p), distance(s.b, p));
    }
}

Real distance(const Segment &s, const Segment &t) {
    if(intersect(s, t)) {
        return 0.0;
    } else {
        return min({distance(s, t.a), distance(s, t.b), distance(t, s.a), distance(t, s.b)});
    }
}

P rotete(const P &p, const int &a) {
    return {p.real() * cos(a * PI / 180.0) - p.imag() * sin(a * PI / 180.0),
            p.real() * sin(a * PI / 180.0) + p.imag() * cos(a * PI / 180.0)};
}

int main() {
    ll N, M, L;
    while(cin >> N >> M >> L, N + M + L) {
        int x, y, a, r;
        P point;
        vector<Segment> star[N];
        for(ll i = 0; i < N; i++) {
            P O;
            cin >> O;
            cin >> a >> r;
            // cout << point << endl;
            P point = rotete({0.0, double(r)}, a);
            // cout << point + O << endl;
            for(int j = 0; j < 5; j++) {
                P nxt = rotete(point, 144);
                star[i].push_back({point + O, nxt + O});
                // cout << "(" << point + O << "," <<  nxt + O <<")" << endl;
                point = nxt;
            }
        }

        vector<vector<double>> G(N, vector<double>(N, INF));
        for(int i = 0; i < N; i++) {
            G[i][i] = 0.0;
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                double Mlen = INF;
                if(i == j) continue;
                for(int k = 0; k < 5; k++) {
                    for(int h = 0; h < 5; h++) {
                        Mlen = min(distance(star[i][k], star[j][h]), Mlen);
                    }
                }
                G[i][j] = Mlen;
            }
        }

        //printf("%.12f\n", G[2][1]);
        //printf("%.12f\n", G[1][2]);

        for(int k = 0; k < N; ++k) {
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j) {
                    if(G[i][k] != INF && G[k][j] != INF) {
                        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                    }
                }
            }
        }
        cout << G[M-1][L-1] << endl;
        // printf("%.12f\n",G[M-1][L-1]);
        /*printf("%.12f\n",G[0][1]);
        printf("%.12f\n",G[2][1]);
        printf("%.12f\n",G[1][2]);
        printf("%.12f\n", G[0][2]);*/
    }

    return 0;
}
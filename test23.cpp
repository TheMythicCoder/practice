#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point() : x(0), y(0) {}
    Point(double X, double Y) : x(X), y(Y) {}
    double dist(const Point& o) const {
        double dx = x - o.x, dy = y - o.y;
        return sqrt(dx*dx + dy*dy);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_real_distribution<double> U(-10.0, 10.0);

    int n = 8;
    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) pts[i] = Point(U(rng), U(rng));

    auto centroid = [&]() {
        double sx = 0, sy = 0;
        for (auto& p : pts) sx += p.x, sy += p.y;
        return Point(sx / n, sy / n);
    }();

    vector<vector<double>> d(n, vector<double>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            d[i][j] = d[j][i] = pts[i].dist(pts[j]);

    int a = 0, b = 0; double mx = -1;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (d[i][j] > mx) mx = d[i][j], a = i, b = j;

    cout << fixed << setprecision(3);
    cout << "Centroid: (" << centroid.x << ", " << centroid.y << ")\n";
    cout << "Farthest pair: " << a << "-" << b << " distance=" << mx << "\n";
    for (int i = 0; i < n; ++i)
        cout << "P" << i << ": (" << pts[i].x << ", " << pts[i].y << ")\n";
    return 0;
}

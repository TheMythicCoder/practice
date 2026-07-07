
#include <bits/stdc++.h>
using namespace std;

// Random C++ program ~100 lines demonstrating various features

struct Point {
	double x, y;
	Point(double a=0, double b=0): x(a), y(b) {}
	double dist() const { return sqrt(x*x + y*y); }
};

class PettyHasher {
public:
	size_t operator()(const string &s) const noexcept {
		// simple rolling hash
		uint64_t h = 1469598103934665603ULL;
		for (char c: s) h = (h ^ (unsigned char)c) * 1099511628211ULL;
		return (size_t)h;
	}
};

double random_double(double lo=0, double hi=1) {
	static random_device rd;
	static mt19937_64 rng(rd());
	uniform_real_distribution<double> dist(lo, hi);
	return dist(rng);
}

vector<Point> generate_random_points(int n, double r=100.0) {
	vector<Point> pts; pts.reserve(n);
	for (int i=0;i<n;++i) pts.emplace_back(random_double(-r,r), random_double(-r,r));
	return pts;
}

double average_distance(const vector<Point>& pts) {
	if (pts.empty()) return 0.0;
	double s=0; for (auto &p: pts) s += p.dist();
	return s/pts.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Create some random points and demonstrate containers
	int n = 20;
	auto pts = generate_random_points(n, 50.0);

	cout << "Generated " << n << " random points:\n";
	for (int i=0;i<n;i++) {
		cout << i << ": (" << fixed << setprecision(2) << pts[i].x << ", " << pts[i].y << ") dist=" << setprecision(3) << pts[i].dist() << '\n';
	}

	cout << "Average distance from origin: " << setprecision(4) << average_distance(pts) << '\n';

	// Use unordered_map with custom hasher
	unordered_map<string,int,PettyHasher> freq;
	vector<string> words = {"apple","banana","apple","cherry","banana","date","apple"};
	for (auto &w: words) freq[w]++;
	cout << "Word frequencies:\n";
	for (auto &p: freq) cout << "  " << p.first << " -> " << p.second << '\n';

	// A tiny simulation: pick nearest neighbor for a random point
	Point q(random_double(-50,50), random_double(-50,50));
	int best = -1; double bestd = 1e300;
	for (int i=0;i<n;i++) {
		double d = hypot(pts[i].x - q.x, pts[i].y - q.y);
		if (d < bestd) { bestd = d; best = i; }
	}
	cout << "Query point: (" << q.x << ", " << q.y << ")\n";
	if (best>=0) cout << "Nearest: index=" << best << " dist=" << bestd << '\n';

	// Demonstrate lambda + algorithm
	sort(pts.begin(), pts.end(), [](const Point &a, const Point &b){ return a.dist() < b.dist(); });
	cout << "Closest 3 points after sorting:\n";
	for (int i=0;i<min(3, (int)pts.size()); ++i)
		cout << "  (" << pts[i].x << ", " << pts[i].y << ") d=" << pts[i].dist() << '\n';

	// small deterministic pseudo-random sequence
	vector<int> seq(16); iota(seq.begin(), seq.end(), 1);
	shuffle(seq.begin(), seq.end(), mt19937(12345));
	cout << "Shuffled seq: "; for (int v: seq) cout << v << ' '; cout << '\n';

	return 0;
}

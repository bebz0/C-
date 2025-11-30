#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

struct Segment {
    Point p1, p2;
    double dist;
};

double get_len(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool compare(Segment a, Segment b) {
    return a.dist < b.dist;
}

int main() {
    ofstream tmp("input_points.txt");
    tmp << "(0, 4), (5, 4) (3, 3), (8, 10)";
    tmp.close();

    ifstream in("input_points.txt");
    if (!in.is_open()) {
        cout << "File not found" << endl;
        return 1;
    }

    vector<Point> pts;
    char c;
    int x, y;

    while (in >> c) {
        if (c == '(') {
            in >> x >> c >> y; 
            pts.push_back({x, y});
        }
    }
    in.close();

    vector<Segment> segs;
    int n = pts.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Segment s;
            s.p1 = pts[i];
            s.p2 = pts[j];
            s.dist = get_len(pts[i], pts[j]);
            segs.push_back(s);
        }
    }

    sort(segs.begin(), segs.end(), compare);

    ofstream out("result.txt");
    for (Segment s : segs) {
        out << "(" << s.p1.x << ", " << s.p1.y << ") - (" 
            << s.p2.x << ", " << s.p2.y << ") Length: " << s.dist << endl;
    }
    out.close();

    cout << "Done. Check result.txt" << endl;

    return 0;
}
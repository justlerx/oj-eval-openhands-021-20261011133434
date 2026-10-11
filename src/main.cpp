#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<Point> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(Point(x, y));
    }
    
    // Sort points by x-coordinate, then by y-coordinate
    sort(points.begin(), points.end());
    
    int count = 0;
    
    // For each point as potential bottom-left corner
    for (int i = 0; i < n; i++) {
        // Minimum y-coordinate of points seen so far that are above points[i]
        // Initialize to a value larger than any possible y-coordinate
        int min_y = 1000000001;
        
        // Process points to the right of points[i] in order of increasing x
        for (int j = i + 1; j < n; j++) {
            // If this point is above points[i] and below or equal to the current minimum y
            if (points[j].y > points[i].y && points[j].y <= min_y) {
                count++;
                // Update the minimum y-coordinate
                min_y = points[j].y;
            }
            // If this point is above points[i] but above the current minimum y,
            // it cannot be a top-right corner for an empty rectangle, but we still
            // need to update the minimum y if it's smaller
            else if (points[j].y > points[i].y) {
                min_y = min(min_y, points[j].y);
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}
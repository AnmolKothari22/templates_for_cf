
#include <bits/stdc++.h>
#define ll long long 
using namespace std;















struct Point {
    double x, y;
};

// Function to check if a point lies on a given line segment
bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x)
        && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}


// Function to find the orientation of the ordered triplet
// (p, q, r) 0 -> p, q and r are collinear 1 -> Clockwise 2
// -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    double val = (q.y - p.y) * (r.x - q.x)
                 - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
      
        // Collinear
        return 0;
  
    // Clock or counterclock wise
    return (val > 0) ? 1 : 2;
}


bool doIntersect(Point p1, Point q1, Point p2, Point q2,
                 Point& res) {
    //res is the point of intersection ...if it exist
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case: lines intersect if they have different
    // orientations
    if (o1 != o2 && o3 != o4) {
      
        // Compute intersection point
        double a1 = q1.y - p1.y;
        double b1 = p1.x - q1.x;
        double c1 = a1 * p1.x + b1 * p1.y;

        double a2 = q2.y - p2.y;
        double b2 = p2.x - q2.x;
        double c2 = a2 * p2.x + b2 * p2.y;

        double determinant = a1 * b2 - a2 * b1;

        if (determinant != 0) {
            res.x
                = (c1 * b2 - c2 * b1) / determinant;
            res.y
                = (a1 * c2 - a2 * c1) / determinant;
            return true;
        }
    }

    // Special Cases: check if the lines are collinear and
    // overlap
    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;
  	if (o3 == 0 && onSegment(p2, p1, q2)) 
        return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) 
        return true;
  
    // Lines do not intersect in any case
    return false;
}


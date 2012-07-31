#include "Bezier.h"

BezierCurve::BezierCurve() {
}

void BezierCurve::setBasePoints(vector<Point3d*> pointsList) {
	basePoints = pointsList;
}

vector<Point3d*> BezierCurve::getBasePoints() {
	return basePoints;
}

vector<Point3d*> BezierCurve::getBezierPoints() {
	return bezierPoints;
}

Point3d* BezierCurve::getBezierPoint(int pointNo) {
	if(bezierPoints.size() > pointNo && pointNo >= 0) {
		return bezierPoints[pointNo];
	}

	cerr << "Error retrieving point from list. Asked for index " << pointNo << ", size of array: " << bezierPoints.size() << ". Returned faux point." << endl;
	Point3d point;
	point.x = 0;
	point.y = 0;
	point.z = 0;

	return &point;
}

void BezierCurve::calculateBezier(int points) {
	for(int i = 0; i < points; ++i) {
		bezierPoints.push_back(recBezierHelper(basePoints, i/points)[0]);
	}
}

vector<Point3d*> BezierCurve::recBezierHelper(vector<Point3d*> points, float part) {
	vector<Point3d*> points2;															// sets up a return array
	if(points.size() == 2) {															// Checks if the size of the input array was 2, since two points are a single line
		points2.push_back(HelperMethods::findPoint(*points[0], *points[1], part));		//    uses the findpoint helper method to find the correct point on the line, and does a push_back into the output array
		return points2;																	//    returns the output array
	}

	for(int i = 0; i < (points.size() - 1); ++i) {										// for every point in the input array, except the last
		points2.push_back(HelperMethods::findPoint(*points[i], *points[i+1], part));    //    use the findpoint method to find a new point along the line between that point and the next, and push it back in the output array
	}																					
																						// the previous should give us an output array with one less point than the input array, with points along the lines between each point along the array
	return recBezierHelper(points2, part);												// recursively return using the output array as input
}

Point3d* HelperMethods::findPoint(const Point3d p1, const Point3d p2, float part) {
	Point3d point;
	point.x = p2.x - p1.x;   // This
	point.y = p2.y - p1.y;   // is
	point.z = p2.z - p1.z;   // all
	                         // basic
	point.x *= part;         // vector
	point.y *= part;         // maths
	point.z *= part;

	point.x += p1.x;
	point.y += p1.y;
	point.z += p1.z;

	return &point;
}
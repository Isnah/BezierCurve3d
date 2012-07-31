#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

struct Point3d {
	float x, y, z;
};

class HelperMethods {
public:
	static Point3d* findPoint(const Point3d p1, const Point3d p2, float part);
};

class BezierCurve {
private:
	vector<Point3d*> bezierPoints;
	vector<Point3d*> basePoints;

public:
	BezierCurve();
	BezierCurve(vector<Point3d*> pointsList);

	~BezierCurve();

	void setBasePoints(vector<Point3d*> pointsList);
	vector<Point3d*> getBasePoints();
	vector<Point3d*> getBezierPoints();
	Point3d* getBezierPoint(int pointNo);

	void calculateBezier(int points);
	vector<Point3d*> recBezierHelper(vector<Point3d*> points, float part);
};
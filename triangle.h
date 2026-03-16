#pragma once

struct Point {
  double x, y;
};

double distance(const Point &a, const Point &b);

struct Triangle {

  Point A, B, C;

  double area() const;

  bool isDegenerate() const;

  // 0 - всередині,
  // 1 - ззовні,
  // 2 - на межі трикутника

  int checkPointPosition(const Point &P) const;

  // 0 - всередині
  // 1 - ззовні
  // 2 - на межі трикутника

  int checkPointPosition1(const Point &P) const;
};

bool checkBorderDegenerate(const Point& p1, const Point& p2, const Point& p);
double cross(const Point &A, const Point &B, const Point &P);
double heronArea(const Triangle &t);

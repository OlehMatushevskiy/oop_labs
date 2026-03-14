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
};

double heronArea(const Triangle &t);

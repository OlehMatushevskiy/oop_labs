#include "triangle.h"
#include <cmath>

using namespace std;

double distance(const Point &p1, const Point &p2) {

  return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double heronArea(const Triangle &t) {

  double a = distance(t.A, t.B);
  double b = distance(t.B, t.C);
  double c = distance(t.C, t.A);
  double half_s = (a + b + c) / 2.0;

  double valueUnderSqrt = half_s * (half_s - a) * (half_s - b) * (half_s - c);

  if (valueUnderSqrt < 0) {
    valueUnderSqrt = 0;
  }

  return sqrt(valueUnderSqrt);
}

double Triangle::area() const { return heronArea(*this); }

bool Triangle::isDegenerate() const { return area() < 1e-9; }

bool checkBorderDegenerate(const Point &a, const Point &b, const Point &p) {

  const double EPSILON = 1e-9;

  return fabs(distance(a, p) + distance(p, b) - distance(a, b)) < EPSILON;
}

// 0 - всередині, 1 - десь ззовні, 2 - на межі трикутника
int Triangle::checkPointPosition(const Point &P) const {

  const double EPSILON = 1e-9;

  if (isDegenerate()) {

    if (checkBorderDegenerate(A, B, P) || checkBorderDegenerate(B, C, P) ||
        checkBorderDegenerate(C, A, P)) {
          
      return 2; // на межі
    }

    return 1; // ззовні
  }

  // метод площ

  Triangle t0 = {A, B, C};

  Triangle t1 = {P, A, B};
  Triangle t2 = {P, B, C};
  Triangle t3 = {P, C, A};

  double area0 = t0.area();

  double area1 = t1.area();
  double area2 = t2.area();
  double area3 = t3.area();

  double area_sum = area1 + area2 + area3;

  if (fabs(area0 - area_sum) < EPSILON) {

    if (area1 < EPSILON || area2 < EPSILON || area3 < EPSILON) {
      return 2; // На межі
    }

    return 0; // всередині
  }

  return 1; // ззовні
}

int Triangle::checkPointPosition1(const Point &P) const {

  const double EPSILON = 1e-9;

  if (isDegenerate()) {
    if (checkBorderDegenerate(A, B, P) || checkBorderDegenerate(B, C, P) ||
        checkBorderDegenerate(C, A, P)) {
      return 2; // на межі
    }
    return 1; // ззовні
  }

  double d1 = cross(A, B, P);
  double d2 = cross(B, C, P);
  double d3 = cross(C, A, P);

  if (fabs(d1) < 1e-9 || fabs(d2) < 1e-9 || fabs(d3) < 1e-9) {
    return 0;
  }

  if (d1 > 0 && d2 > 0 && d3 > 0) {
    return 2; // на межі
  }

  if (d1 < 0 && d2 < 0 && d3 < 0) {
    return 0; // всередині
  }

  // на межі
  return 1;
}

double cross(const Point &A, const Point &B, const Point &P) {
  return ((B.x - A.x) * (P.y - A.y)) - ((B.y - A.y) * (P.x - A.x));
}

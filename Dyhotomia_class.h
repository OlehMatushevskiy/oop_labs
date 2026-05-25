#pragma once

class Dyhotomia_class {
private:
  double a;
  double b;
  double eps;

public:
  Dyhotomia_class();
  ~Dyhotomia_class();

  void setVolumes(double vol_a, double vol_b);
  void setTolerance(double vol_eps);
  int countDyhotomia(double &x);
  int countNewton(double &x);
};

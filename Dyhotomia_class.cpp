#include "Dyhotomia_class.h"

#include <cmath>

Dyhotomia_class::Dyhotomia_class() {
  a = 0.0;
  b = 0.0;
  eps = 0.0001;
}

Dyhotomia_class::~Dyhotomia_class() {}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b) {
  a = vol_a;
  b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps) { eps = vol_eps; }

int Dyhotomia_class::countDyhotomia(double &x) {
  double left = a;
  double right = b;
  double c;

  auto f = [](double value) {
    return value + sqrt(value) + cbrt(value) - 2.5;
  };

  if (eps <= 0 || left >= right) {
    return -2;
  }

  if (f(left) * f(right) > 0) {
    return -1;
  }

  while (fabs(right - left) > eps) {
    c = (left + right) / 2.0;

    if (f(left) * f(c) < 0) {
      right = c;
    } else {
      left = c;
    }
  }

  x = (left + right) / 2.0;
  return 0;
}

int Dyhotomia_class::countNewton(double &x) {
  const double h = 0.00001;
  const double derivativeLimit = 0.0000000001;
  const int maxIterations = 1000;

  auto f = [](double value) {
    return value + sqrt(value) + cbrt(value) - 2.5;
  };

  auto derivative = [h, f](double value) {
    return (f(value + h) - f(value)) / h;
  };

  if (eps <= 0) {
    return -3;
  }

  x = 0.8;

  for (int i = 0; i < maxIterations; i++) {
    double currentDerivative = derivative(x);

    if (fabs(currentDerivative) < derivativeLimit) {
      return -1;
    }

    double x_next = x - f(x) / currentDerivative;

    if (std::isnan(x_next)) {
      return -2;
    }

    if (fabs(x_next - x) < eps) {
      x = x_next;
      return 0;
    }

    x = x_next;
  }

  return -2;
}

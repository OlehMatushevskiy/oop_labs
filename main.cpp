#include "triangle.h"
#include <iostream>

using namespace std;

int main() {

  Triangle t;

  cout << "Введіть координати вершини A (x y): ";
  if (!(cin >> t.A.x >> t.A.y)) {
    cout << "Некоректні координати" << endl;
    return 1;
  }
  cout << "Введіть координати вершини B (x y): ";
  if (!(cin >> t.B.x >> t.B.y)) {
    cout << "Некоректні координати" << endl;
    return 1;
  }
  cout << "Введіть координати вершини C (x y): ";
  if (!(cin >> t.C.x >> t.C.y)) {
    cout << "Некоректні координати" << endl;
    return 1;
  }

  if (t.isDegenerate()) {
    cout << "Трикутник вироджений , площа дорівнює 0" << endl;
  }

  cout << "\nВийшов трикутник з вершинами: { " << t.A.x << " , " << t.A.y
       << " },  { " << t.B.x << " , " << t.B.y << " },  { " << t.C.x << " , "
       << t.C.y << " }\n"
       << endl;

  while (true) {
    Point p;

    cout << "Введіть координати точки, яку хочете перевірити (x y) ( введіть "
            "щось інше для виходу): ";

    if (!(cin >> p.x >> p.y)) {
      cout << "Програму завершено" << endl;
      break;
    }


    int pos_s = t.checkPointPosition(p);
    int pos_v = t.checkPointPosition1(p);
    cout << "Точка { " << p.x << " , " << p.y << " } лежить ";

    switch (pos_s) {
      case 0:
        cout << "всередині трикутника ( площа )" << endl;
        break;
      case 1:
        cout << "десь ззовні трикутника ( площа )" << endl;
        break;
      case 2:
        cout << "на межі трикутника ( площа )" << endl;
        break;
    }

    switch (pos_v) {
      case 0:
        cout << "всередині трикутника ( вектор )" << endl;
        break;
      case 1:
        cout << "десь ззовні трикутника ( вектор )" << endl;
        break;
      case 2:
        cout << "на межі трикутника ( вектор )" << endl;
        break;
    }
  }

  return 0;
}
#include "TransportClasses.h"
#include <iostream>

using namespace std;

int main() {
  Car car("Toyota", 120);
  Bus bus("Bogdan", 70, 40);
  Truck truck("MAN", 80, 12);
  ElectricCar electricCar("Tesla", 85);

  electricCar.SetSpeed(90, 110);

  Transport *transport;

  cout << "Полiморфiзм у програмi:\n\n";

  transport = &car;
  transport->ShowInfo();
  transport->Move();
  cout << "\n";

  transport = &bus;
  transport->ShowInfo();
  transport->Move();
  cout << "\n";

  transport = &truck;
  transport->ShowInfo();
  transport->Move();
  cout << "\n";

  transport = &electricCar;
  transport->ShowInfo();
  transport->Move();
  cout << "\n";

  return 0;
}

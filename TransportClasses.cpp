#include "TransportClasses.h"
#include <iostream>

using namespace std;

Transport::Transport() {
  brand = "Невідома марка";
  speed = 0;
}

Transport::Transport(string b, int s) {
  brand = b;
  speed = s;
}

Transport::~Transport() {
}

int Transport::SetBrand(string b) {
  brand = b;
  return 1;
}

int Transport::SetSpeed(int s) {
  speed = s;
  return 1;
}

int Transport::SetSpeed(int minSpeed, int maxSpeed) {
  speed = (minSpeed + maxSpeed) / 2;
  return 1;
}

void Transport::ShowInfo() const {
  cout << "Транспорт марки " << brand << ", швидкість " << speed << " км/год.\n";
}

void Transport::Move() const {
  cout << "Транспорт рухається.\n";
}

Car::Car(string b, int s) : Transport(b, s) {
}

void Car::ShowInfo() const {
  cout << "Автомобіль марки " << brand << ", швидкість " << speed << " км/год.\n";
}

void Car::Move() const {
  cout << "Автомобіль їде по дорозі.\n";
}

Bus::Bus(string b, int s, int p) : Transport(b, s) {
  SetPassengers(p);
}

int Bus::SetPassengers(int p) {
  passengers = p;
  return 1;
}

void Bus::ShowInfo() const {
  cout << "Автобус марки " << brand << ", швидкість " << speed
       << " км/год, пасажирів " << passengers << ".\n";
}

void Bus::Move() const {
  cout << "Автобус зупиняється на зупинках.\n";
}

Truck::Truck(string b, int s, int load) : Transport(b, s) {
  SetLoadCapacity(load);
}

int Truck::SetLoadCapacity(int load) {
  loadCapacity = load;
  return 1;
}

void Truck::ShowInfo() const {
  cout << "Вантажівка марки " << brand << ", швидкість " << speed
       << " км/год, вантажність " << loadCapacity << " тонн.\n";
}

void Truck::Move() const {
  cout << "Вантажівка перевозить вантаж.\n";
}

ElectricCar::ElectricCar(string b, int batteryPower) : Transport(b, 0) {
  SetBattery(batteryPower);
}

int ElectricCar::SetBattery(int batteryPower) {
  battery = batteryPower;
  return 1;
}

void ElectricCar::ShowInfo() const {
  cout << "Електромобіль марки " << brand << ", батарея "
       << battery << " кВт*год, швидкість " << speed << " км/год.\n";
}

void ElectricCar::Move() const {
  cout << "Електромобіль їде майже безшумно.\n";
}

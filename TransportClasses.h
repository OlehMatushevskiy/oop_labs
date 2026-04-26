#pragma once

#include <string>

using namespace std;

class Transport {
protected:
  string brand;
  int speed;

public:
  Transport();
  Transport(string b, int s);
  virtual ~Transport();

  int SetBrand(string b);
  int SetSpeed(int s);
  int SetSpeed(int minSpeed, int maxSpeed);

  virtual void ShowInfo() const;
  virtual void Move() const;
};

class Car : public Transport {
public:
  Car(string b, int s);

  void ShowInfo() const;
  void Move() const;
};

class Bus : public Transport {
private:
  int passengers;

public:
  Bus(string b, int s, int p);

  int SetPassengers(int p);
  void ShowInfo() const;
  void Move() const;
};

class Truck : public Transport {
private:
  int loadCapacity;

public:
  Truck(string b, int s, int load);

  int SetLoadCapacity(int load);
  void ShowInfo() const;
  void Move() const;
};

class ElectricCar : public Transport {
private:
  int battery;

public:
  ElectricCar(string b, int batteryPower);

  int SetBattery(int batteryPower);
  void ShowInfo() const;
  void Move() const;
};

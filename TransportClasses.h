#pragma once

#include <string>

class Transport {
protected:
  std::string brand;
  int speed;

public:
  Transport();
  Transport(std::string b, int s);
  virtual ~Transport();

  int SetBrand(std::string b);
  int SetSpeed(int s);
  void ShowTransport() const;
};

class LandTransport : virtual public Transport {
protected:
  int wheels;

public:
  LandTransport();
  LandTransport(int w);
  ~LandTransport();

  int SetWheels(int w);
  void ShowLandTransport() const;
};

class PassengerTransport : virtual public Transport {
protected:
  int passengers;

public:
  PassengerTransport();
  PassengerTransport(int p);
  ~PassengerTransport();

  int SetPassengers(int p);
  void ShowPassengerTransport() const;
};

class CargoTransport : virtual public Transport {
protected:
  int loadCapacity;

public:
  CargoTransport();
  CargoTransport(int load);
  ~CargoTransport();

  int SetLoadCapacity(int load);
  void ShowCargoTransport() const;
};

class UniversalTransport : public LandTransport, public PassengerTransport, public CargoTransport {
private:
  std::string purpose;

public:
  UniversalTransport(std::string b, int s, int w, int p, int load, std::string purp);
  ~UniversalTransport();

  int SetPurpose(std::string purp);
  void ShowInfo() const;
};

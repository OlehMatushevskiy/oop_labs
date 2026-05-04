#include "TransportClasses.h"
#include <iostream>

using namespace std;

Transport::Transport() {
  brand = "Невідомо";
  speed = 0;
  cout << "Конструктор Transport" << "\n";
}

Transport::Transport(string b, int s) {
  brand = b;
  speed = s;
  cout << "Конструктор Transport" << "\n";
}

Transport::~Transport() {
  cout << "Деструктор Transport" << "\n";
}

int Transport::SetBrand(string b) {
  brand = b;
  return 1;
}

int Transport::SetSpeed(int s) {
  speed = s;
  return 1;
}

void Transport::ShowTransport() const {
  cout << "Марка: " << brand << ", швидкість: " << speed << " км/год." << "\n";
}

LandTransport::LandTransport() {
  wheels = 0;
  cout << "Конструктор LandTransport" << "\n";
}

LandTransport::LandTransport(int w) {
  wheels = w;
  cout << "Конструктор LandTransport" << "\n";
}

LandTransport::~LandTransport() {
  cout << "Деструктор LandTransport" << "\n";
}

int LandTransport::SetWheels(int w) {
  wheels = w;
  return 1;
}

void LandTransport::ShowLandTransport() const {
  cout << "Кількість коліс: " << wheels << "\n";
}

PassengerTransport::PassengerTransport() {
  passengers = 0;
  cout << "Конструктор PassengerTransport" << "\n";
}

PassengerTransport::PassengerTransport(int p) {
  passengers = p;
  cout << "Конструктор PassengerTransport" << "\n";
}

PassengerTransport::~PassengerTransport() {
  cout << "Деструктор PassengerTransport" << "\n";
}

int PassengerTransport::SetPassengers(int p) {
  passengers = p;
  return 1;
}

void PassengerTransport::ShowPassengerTransport() const {
  cout << "Кількість пасажирів: " << passengers << "\n";
}

CargoTransport::CargoTransport() {
  loadCapacity = 0;
  cout << "Конструктор CargoTransport" << "\n";
}

CargoTransport::CargoTransport(int load) {
  loadCapacity = load;
  cout << "Конструктор CargoTransport" << "\n";
}

CargoTransport::~CargoTransport() {
  cout << "Деструктор CargoTransport" << "\n";
}

int CargoTransport::SetLoadCapacity(int load) {
  loadCapacity = load;
  return 1;
}

void CargoTransport::ShowCargoTransport() const {
  cout << "Вантажність: " << loadCapacity << " тонн" << "\n";
}

UniversalTransport::UniversalTransport(string b, int s, int w, int p, int load, string purp)
    : Transport(b, s), LandTransport(w), PassengerTransport(p), CargoTransport(load) {
  purpose = purp;
  cout << "Конструктор UniversalTransport" << "\n";
}

UniversalTransport::~UniversalTransport() {
  cout << "Деструктор UniversalTransport" << "\n";
}

int UniversalTransport::SetPurpose(string purp) {
  purpose = purp;
  return 1;
}

void UniversalTransport::ShowInfo() const {
  cout << "Універсальний транспорт" << "\n";
  ShowTransport();
  ShowLandTransport();
  ShowPassengerTransport();
  ShowCargoTransport();
  cout << "Призначення: " << purpose << "\n";
}

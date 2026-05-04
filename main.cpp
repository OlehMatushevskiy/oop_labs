#include "TransportClasses.h"
#include <iostream>

using namespace std;

int main() {
  cout << "Лабораторна 5. Множинне успадкування"
       << "\n\n";
  cout << "Створення об'єкта:"
       << "\n";

  {
    UniversalTransport machine("Mercedes", 90, 6, 12, 8, "рятувальні роботи");
    LandTransport *landPart = &machine;
    PassengerTransport *passengerPart = &machine;
    CargoTransport *cargoPart = &machine;
    Transport *baseFromLand = landPart;
    Transport *baseFromPassenger = passengerPart;
    Transport *baseFromCargo = cargoPart;

    cout << "\nІнформація про об'єкт:"
         << "\n";
    machine.ShowInfo();

    cout << "\nПеревірка virtual успадкування:"
         << "\n";
    cout << "Адреса Transport через LandTransport: " << baseFromLand << "\n";
    cout << "Адреса Transport через PassengerTransport: " << baseFromPassenger
         << "\n";
    cout << "Адреса Transport через CargoTransport: " << baseFromCargo << "\n";
    cout << "Усі адреси однакові, бо базовий клас Transport створився один раз"
         << "\n";

    landPart->SetBrand("MAN");
    passengerPart->SetSpeed(75);

    cout << "\nПісля зміни через різні гілки успадкування:"
         << "\n";
    baseFromCargo->ShowTransport();

    cout << "\nПояснення:"
         << "\n";
    cout << "Клас UniversalTransport успадковується від трьох батьківських "
            "класів"
         << "\n";
    cout << "Усі вони мають спільний базовий клас Transport"
         << "\n";
    cout << "Завдяки virtual успадкуванню клас Transport створюється тільки "
            "один раз"
         << "\n";
    cout
        << "Якби virtual не було, виникло б дублювання базового класу Transport"
        << "\n";
  }

  cout << "\nОб'єкт знищено"
       << "\n";

  return 0;
}

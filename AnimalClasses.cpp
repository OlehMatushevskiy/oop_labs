#include "AnimalClasses.h"
#include <iostream>

using namespace std;

Animal::Animal() {
  int e = SetTail("без хвоста");
  e = SetPaws(0);
  e = SetVoice("звичайним");
}

int Animal::SetTail(string t) {
  tail = t;
  return 1;
}

int Animal::SetPaws(int p) {
  paws = p;
  return 1;
}

int Animal::SetVoice(string v) {
  voice = v;
  return 1;
}

int Animal::Say() {
  cout << "Звук: " << voice << " му-у\n";
  return 1;
}

int Animal::CreateAnimal() {
  cout << "Має " << paws << " лапи та " << tail << "\n";
  return 1;
}

Dog::Dog() {
  int e = SetPaws(4);
  e = SetTail("обкусаний хвіст");
  e = SetVoice("гучним");
  e = CreateAnimal();
  e = Say();
}

int Dog::Say() {
  cout << "Гав\n";
  return 1;
}

Cat::Cat() {
  int e = SetPaws(4);
  e = SetTail("хвіст");
  e = SetVoice("няшним");
  e = CreateAnimal();
  e = Say();
}

int Cat::Say() {
  cout << "Мяу\n";
  return 1;
}

HighbredCat::HighbredCat() {
  int e = SetBreed("без породи");
  cout << "Порода: " << breed << "\n";
}

HighbredCat::HighbredCat(string b) {
  int e = SetBreed(b);
  cout << "Порода: " << breed << "\n";
}

int HighbredCat::SetBreed(string b) {
  breed = b;
  return 1;
}

HomeCat::HomeCat(string b, string n, string c) : HighbredCat(b) {
  int e = SetBreed(b);
  e = SetName(n);
  e = SetColour(c);
  cout << "То " << colour << " кіт " << breed << ". Звати " << name << "\n";
}

int HomeCat::SetBreed(string b) {
  breed = b;
  return 1;
}

int HomeCat::SetName(string n) {
  name = n;
  return 1;
}

int HomeCat::SetColour(string c) {
  colour = c;
  return 1;
}

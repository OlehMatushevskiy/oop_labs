#pragma once

#include <string>

using namespace std;

class Animal {
protected:
  string tail;
  int paws;
  string voice;

public:
  Animal();
  int SetTail(string t);
  int SetPaws(int p);
  int SetVoice(string v);
  int Say();
  int CreateAnimal();
};

class Dog : public Animal {
public:
  Dog();
  int Say();
};

class Cat : public Animal {
public:
  Cat();
  int Say();
};

class HighbredCat : public Cat {
protected:
  string breed;

public:
  HighbredCat();
  HighbredCat(string b);
  int SetBreed(string b);
};

class HomeCat : public HighbredCat {
private:
  string name;
  string colour;

public:
  HomeCat(string b, string n, string c);
  int SetBreed(string b);
  int SetName(string n);
  int SetColour(string c);
};

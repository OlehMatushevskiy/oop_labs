#include "AnimalClasses.h"

int main() {

  HomeCat *my_pet = new HomeCat("Дворняжка", "Барсік", "Чорно-білий");
  my_pet->Say();
  delete my_pet;
  return 0;
}

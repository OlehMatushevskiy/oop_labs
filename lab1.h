#ifndef LAB1_H
#define LAB1_H

struct money {
  int grn;
  short int kop;
};

void sum(money *a, money b);
void multi(money *m, int n);

money round(const money &m);
void parseLines(const char *file_name);

#endif

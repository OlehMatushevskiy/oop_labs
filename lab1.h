#include <iostream> 
#include <vector>
#include <string>
#include <cctype>

using namespace std;

struct money {
    int grn;
    short int kop;
};

money sum(money a, money b);
money multi(money m, int n);

money round(const money& m);
vector<string> parseLines(const char*);
money parseLine(const string& line);

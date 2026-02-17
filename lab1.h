#include <iostream> 
#include <vector>
#include <string>
 #include <cctype>

using namespace std;

struct money {
    int grn;
    short int kop;

    money operator+(const money& other) const;
    money operator*(int n) const;
};

money round(const money& m);
vector<string> parseLines(const char*);
money parseLine(const string& line);





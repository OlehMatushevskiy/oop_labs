
 #include "lab1.h"
 #include <string> 
 #include <vector>
 #include <iostream>
 #include <cctype>

 using namespace std;

 money money::operator+(const money& other) const {

    money result;

    int total_grn = this->grn + other.grn;
    short int total_kop = this->kop + other.kop;

    int all_kop = total_grn * 100 + total_kop;

    int result_grn = all_kop / 100;

    int result_kop = all_kop - result_grn * 100;

    result.grn = result_grn;
    result.kop = result_kop;

    return result;
 }

 money money::operator*(int n) const {

    money result;
    int grn = this->grn * n;
    int kop = this->kop * n;
    int total_kop = grn * 100 + kop;
    
    int result_grn = total_kop / 100;
    int result_kop = total_kop - result_grn * 100;

    result.grn = result_grn;
    result.kop = result_kop;

    return result;
 }

 money round(const money& m) {

    money result;

    short int secondDigit = m.kop % 10;

    if (secondDigit == 0)
    { 
        result.grn = m.grn;
        result.kop = m.kop;

        return result; 
    }

    if(secondDigit % 10 >= 5) {
        
        if(m.kop > 94) {
            result.grn = m.grn + 1;
            result.kop = 0;
            return result;
        }
        else {

            result.grn = m.grn;
            result.kop = m.kop + ( 10 - secondDigit );
            return result;
        }
    } 
    else {

        result.grn = m.grn;
        result.kop = m.kop - secondDigit; 

        return result;
    }
 }

vector<string> parseLines(const char* file_name) {

    vector<string> all_lines;

    FILE *f = fopen(file_name,"r");
    
    if (f == NULL) { return all_lines; }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), f)) {
        all_lines.push_back(string(buffer));
    }

    fclose(f);

    return all_lines;
}

money parseLine(const string& line) {
    money m = { 0, 0 };
    int current_number = 0;
    int quantity = 1;

    for (size_t i = 0; i < line.length(); ++i) {

        if (isdigit(line[i])) {
            size_t start = i;
            while (i < line.length() && isdigit(line[i])) {
                i++;
            }

            current_number = std::stoi(line.substr(start, i - start));

            while (i < line.length() && isspace(line[i])) {
                i++;
            }

            string tail = line.substr(i, 10); 

            if (tail.find("грн") == 0 || tail.find("grn") == 0) {
                m.grn = current_number;
            } 
            else if (tail.find("коп") == 0 || tail.find("kop") == 0) {
                m.kop = (short)current_number;
            } 
            else if (tail.find("шт") == 0 || tail.find("x") == 0) {
                quantity = current_number;
            }
        }
    }

    if (quantity > 1) {
        return m * quantity;
    }
    return m;
}
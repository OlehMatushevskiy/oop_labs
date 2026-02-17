
#include <iostream> 
#include <stdio.h> 
#include <vector>
#include <string>
#include <cctype> 
#include "lab1.h"

using namespace std;

int main() {

    const char* receiptName = "receipt.txt";

    FILE *my_file;
    my_file = fopen(receiptName,"w+t");
    fprintf(my_file, "33\n");
    fprintf(my_file, "Apple, 5 шт 55 коп, 2 грн\n");
    fprintf(my_file, "Milk, 3.5 grn , 6 kop");
    fclose(my_file);
    
    vector<string> lines = parseLines(receiptName);

    cout << "\n-- Receipt got --\n" << endl;

    for (int i = 0; i < lines.size(); i++) {
        cout << lines[i];
    }
    cout << "\n\n-----------------\n" << endl;

    money totalMoney = { 0,0 };

    for (int i = 0; i < lines.size(); i++) {

        if (lines[i] == "\n" || lines[i].empty()) { continue; }

        money parseMoney = parseLine(lines[i]);

        cout << "parsed line: { grn: " << parseMoney.grn << ", kop: " << parseMoney.kop << " }" << endl;

        totalMoney = totalMoney + parseMoney;
    }

    money finalMoney = round(totalMoney);

    cout << "\nfull receipt amount: { grn: " << finalMoney.grn << ", kop: " << finalMoney.kop << " }" << endl;

    return 0;
}
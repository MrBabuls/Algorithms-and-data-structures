#include "HTMLChecker.h"
#include <iostream>
#include <fstream>

using namespace std;

bool HTMLChecker::checkFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open file: " << filename << endl;
        return false;
    }

    string line;
    int lineNumber = 0;
    while (getline(file, line)) {
        lineNumber++;
        size_t pos = 0;
        while ((pos = line.find('<', pos)) != string::npos) {
            size_t end = line.find('>', pos);
            if (end == string::npos) break;
            string tagContent = line.substr(pos + 1, end - pos - 1);
            cout << "Found tag: <" << tagContent << "> on line " << lineNumber << endl;
            pos = end + 1;
        }
    }
    return true;
}
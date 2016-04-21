#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "markov.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;

markov::markov(vector<string> src) {
    
}

string markov::gen_chain(int lim) {
    return "";
}

void markov::update_val(vector<string>, string val) {
}

void markov::contains_key(vector<string>) {
}

vector<string> &split(string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        cout << "Error: Wrong number of arguments" << endl << "Usage: ./main <filename> <length>" << endl;
        return 1;
    } else if(argc == 3) {
        string filename = string(argv[1]);
        string line;
        
        int max_len = std::stoi(argv[2]);
        ifstream infile(filename);
        vector<string> text;
        while (getline(infile, line)) {
            split(line, ' ', text);
        }
        for (int i = 0; i < text.size(); i++) {
            cout << text.at(i) << endl;
        }

    } else {
        
    }
    
    return 0;
}

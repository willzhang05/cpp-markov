#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "markov.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;

markov::markov() {}
markov::markov(vector<string> src) {
    for (int i = 0; i < (int)src.size() - 1; i++) {
        vector<string> key;
        key.push_back(src[i]);
        key.push_back(src[i + 1]);
        vector<string> values;
        values.push_back(src[i + 2]);
        if (map.find(key) == map.end())
            map[key] = values;
        else {
            map[key].push_back(src[i + 2]);
        }
        cout << ind_to_string(key, map[key]) << endl;
    }
}

string markov::gen_chain(int lim) {
    string buff;
    if (lim < 0) {
        string cur_val;
        while (cur_val != "") {
        }
    }

    return "";
}

string markov::ind_to_string(vector<string> key, vector<string> val) {
    string buff("[" + key[0] + ", " + key[1] + "] -> [");
    for (int i = 0; i < (int)val.size(); i++) {
        buff += val[i] + ", ";
    }
    return buff.substr(0, buff.size() - 2) + "]";
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Error: Wrong number of arguments" << endl
             << "Usage: ./main <filename> <length>" << endl;
        return 1;
    }
    int max_len = argc == 3 ? std::stoi(argv[2]) : -1;
    string filename = string(argv[1]);
    string line;
    ifstream infile(filename);
    vector<string> text;
    while (getline(infile, line, ' ')) {
        text.push_back(line);
        if (line.at(line.size() - 1) == '.') {
            text.push_back("");
            text.push_back("");
        }
    }
    for (int i = 0; i < (int)text.size(); i++) {
        cout << text.at(i) << endl;
    }
    markov::markov m(text);
    m.gen_chain(max_len);
    return 0;
}

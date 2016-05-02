#include <iostream>
#include <sstream>
#include <fstream>
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
    for (int i = 0; i < (int)src.size() - 2; i++) {
        vector<string> key;
        key.push_back(src[i]);
        key.push_back(src[i + 1]);
        vector<string> values;
        values.push_back(src[i + 2]);
        if (map.find(key) == map.end()) {
            map[key] = values;
        } else {
            map[key].push_back(src[i + 2]);
        }
    }
    print();
}

string markov::gen_chain(int lim) {
    string buff, cur_val = " ";
    vector<string> cur_key = {"", ""}, cur_vals = map[cur_key];
    int ind, sent = 0;
    if (lim < 0) {
        while (cur_val != "" && cur_vals.size() != 0) {
            ind = std::rand() % cur_vals.size();
            cur_val = cur_vals[ind];
            buff += cur_val + " ";
            cur_key[0] = cur_key[1];
            cur_key[1] = cur_val;
            cur_vals = map[cur_key];
        }
        return buff.substr(0, buff.size() - 1);
    }
    while (sent < lim && cur_vals.size() != 0) {
        ind = std::rand() % cur_vals.size();
        cur_val = cur_vals[ind];
        buff += cur_val + " ";
        if (cur_val.find(".") != string::npos) {
            buff = buff.substr(0, buff.size() - 1);
            sent++;
        }
        cur_key[0] = cur_key[1];
        cur_key[1] = cur_val;
        cur_vals = map[cur_key];
    }
    return buff;
}

string markov::ind_to_string(vector<string> key, vector<string> val) {
    string buff("[" + key[0] + ", " + key[1] + "] -> [");
    for (int i = 0; i < (int)val.size(); i++) {
        buff += val[i] + ", ";
    }
    return buff.substr(0, buff.size() - 2) + "]";
}

void markov::print() {
    for (auto const &e : map) {
        cout << ind_to_string(e.first, map[e.first]) << endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Error: Wrong number of arguments" << endl
             << "Usage: ./main <filename> <length>" << endl;
        return 1;
    }
    std::srand(time(0));
    int max_len = argc == 3 ? std::atoi(argv[2]) : -1;
    string filename = string(argv[1]);
    string line;
    ifstream infile(filename);
    vector<string> text;
    while (getline(infile, line)) {
        stringstream in(line);
        string token;
        while (getline(in, token, ' ')) {
            text.push_back(token);
            if (token[token.size() - 1] == '.') {
                text.push_back("");
                text.push_back("");
            }
        }
    }
    text.push_back("");
    /*for (int i = 0; i < (int)text.size(); i++) {
        cout << text.at(i) + " ";
    }*/
    markov::markov m(text);
    cout << m.gen_chain(max_len) << endl;
    return 0;
}

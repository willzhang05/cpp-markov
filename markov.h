#ifndef MARKOV_HEADER
#define MARKOV_HEADER

#include <string>
#include <vector>
#include <map>

using std::vector;
using std::string;
using std::map;

class markov {
   private:
    map<vector<string>, vector<string>> map;

   public:
    markov();
    markov(vector<string> src);

    string gen_chain(int lim);
    string ind_to_string(vector<string> key, vector<string> val);
    void print();
};

#endif

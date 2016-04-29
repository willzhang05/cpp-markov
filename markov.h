#ifndef MARKOV_HEADER
#define MARKOV_HEADER

#include <vector>
#include <string>
#include <map>

class markov {
   private:
    std::map<std::vector<std::string>, std::vector<std::string>> map;

   public:
    markov();
    markov(std::vector<std::string> src);

    std::string gen_chain(int lim);
    std::string ind_to_string(std::vector<std::string> key, std::vector<std::string> val);
};

#endif

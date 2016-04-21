class markov {
   private:
    std::map<std::vector<std::string>, std::vector<std::string>> map;

   public:
    markov(std::vector<std::string> src);

    std::string gen_chain(int lim);
    void update_val(std::vector<std::string>, std::string val);
    void contains_key(std::vector<std::string>);
};

#pragma once
#include"player.hpp"
#include <iostream>
#include <vector>

namespace ariel{
    class Card{
       public:

        Card();
        int get_card_value(string);
        map<std::string, int> card_deck;
        vector<string> cards;
        string get_card(unsigned int);
        void get_cards();
    };
}
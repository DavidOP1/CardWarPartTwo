#include <iostream>
using namespace std;
#include <string>
#include <map>
#include <vector>
#pragma once
namespace ariel{
    class Player{
        public:
            Player(string);
            int stacksize();
            int cardesTaken();
            double winRate();
            bool inGame();
            void set_cards(string);
            string get_card();
            void deck_values();
            string get_name();
            int rounds_won , rounds_played , stack_size,cards_taken;
            bool in_game;
            vector<string> cards ;
            string name;
            unsigned int  card_index;
            map<string, int> card_deck;
    };
}
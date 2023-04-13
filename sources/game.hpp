#pragma once
#include"player.hpp"
#include <iostream>
#include <vector>
namespace ariel{
    class Game{
       public:
        Game(Player&,Player&);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void add_turn_data(string);
      private:
        vector <string> turn_data;
        Player &p1,&p2;
        int draw=0;
        bool can_game;
    };
}
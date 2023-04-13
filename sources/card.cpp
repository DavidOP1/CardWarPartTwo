#include <iostream>
#include "card.hpp"
#include <map>
#include <algorithm>
#include <random>
const int NUM_SUITS = 4;
const int NUM_RANKS = 13;
string card_names[NUM_SUITS] = {"Spades", "Hearts", "Diamonds", "Clubs"};
string ranks[NUM_RANKS] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King","Ace"};
namespace ariel{
    Card::Card(){
        int index = 0 ;
        string name ="";
        // Generate all cards
        for (int suit = 0; suit < NUM_SUITS; suit++) {
        for (int rank = 0; rank < NUM_RANKS; rank++) {
            name = ranks[rank] + " of " + card_names[suit];
            cards.push_back(name);
            card_deck[name] = rank;
            index++;
        }
    }
        random_device rd;
        mt19937 gen(rd());
        shuffle(cards.begin(),cards.end(),gen);

    }

    void Card::get_cards(){
        for(string vec : cards){
            cout << vec << endl;
        }
    }

    string Card::get_card(unsigned int index){
        return this->cards.at(index);
    }

    int Card::get_card_value(string card){
        return this->card_deck[card];
    };
}
#include "player.hpp"
#include <iostream>
using namespace std;


namespace ariel{
        
        Player::Player(string player_name){this->name=player_name;
        this->stack_size = 0;
        this->cards_taken=0;
        this->card_index=0;
        this->rounds_won=0;
        this->rounds_played =0;
        this->in_game = false;
        };

        int Player::stacksize(){return this->stack_size;};
        int Player::cardesTaken(){return this->cards_taken;};
        double Player::winRate(){return (static_cast<double>(this->rounds_won)/this->rounds_played);};
        bool Player::inGame(){return in_game;};

        void Player::set_cards(string card){
                this->cards.push_back(card);
                };
                
        string  Player::get_card(){
                if(this->stack_size>0){
                this->stack_size -=1 ;
                this->card_index +=1;
                return this->cards.at(this->card_index-1);
                }
                return "";
        };

        string Player::get_name(){
                return this->name;
                };
        
}
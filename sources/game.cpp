#include <iostream>
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include <map>
#include <algorithm>
#include <random>
#include <vector>


namespace ariel{
        Card cards;
        Game::Game(Player & player1,Player & player2):p1(player1),p2(player2){ 
        const int num_cards =52;
        map<std::string, int> card_deck;
        if((player1.inGame() || player2.inGame()) || (&player1 == &player2)){
            this->can_game=false;
            }
        else{
        this->can_game=true;
        p1.in_game = true;
        p2.in_game = true;
        p1.stack_size =26;
        p2.stack_size =26;
        this->draw =0;
        // Shuffle the array 
        int p1_index =0 , p2_index =0 ;

        //Give cards to both players.
        for(int i=0;i<num_cards;i++){
            if(i%2==0) {
                p1.set_cards(cards.get_card(static_cast<unsigned int>(i))); 
                p1_index+=1;
                }
            else{ 
                p2.set_cards(cards.get_card(static_cast<unsigned int>(i)));
                p2_index+=1;
                };
    }

        }
    };


        void Game::playTurn(){
            try{
               if(!p1.stacksize() || !p2.stacksize() || !this->can_game){
                throw ("Game Ended");
               }else {
               string p1_card = p1.get_card() , p2_card = p2.get_card() , 
               round_data = p1.get_name() + " played " + p1_card +" "+ p2.get_name() + " played " +p2_card+". ";
               int pot =0;


                int p1_val = cards.get_card_value(p1_card);
                int p2_val = cards.get_card_value(p2_card);


               if(p1_val>p2_val || (p1_val==0 && p2_val==12)){
                    p1.rounds_won +=1;
                    p1.cards_taken +=2;
                    this->add_turn_data(round_data+p1.get_name() + " wins.");
               }else if(p1_val<p2_val || (p2_val==0 && p1_val==12)){
                    p2.cards_taken+=2;
                    p2.rounds_won +=1;
                    this->add_turn_data(round_data+p2.get_name() + " wins.");
                }else if(p1_val==p2_val){

                    //add condition where they are out of cards.
                    pot +=2;
                    while((p1_val==p2_val)&&(p1.stacksize() && p2.stacksize())){
                        this->draw +=1;
                        round_data += " Draw. ";
                        p1.get_card();
                        p2.get_card();
                        pot+=2;
                        if(p1.stacksize()&&p2.stacksize()){
                        p1_card = p1.get_card();
                        p2_card = p2.get_card();
                        p1_val = cards.get_card_value(p1_card);
                        p2_val = cards.get_card_value(p2_card);
                        round_data += p1.get_name() + " played " + p1_card +" "+ p2.get_name() + " played " +p2_card+". ";
                        pot+=2;
                        }
                    }
                    
                    if(p1_val>p2_val || (p1_val==0 && p2_val==12)){
                        p1.rounds_won +=1;
                        p1.cards_taken += pot;
                        this->add_turn_data(round_data+p1.get_name() + " wins.");
                    }else if(p1_val<p2_val || (p2_val==0 && p1_val==12)){
                        p2.rounds_won +=1;
                        p2.cards_taken += pot;
                        this->add_turn_data(round_data+p2.get_name() + " wins.");
                    }else if(!p1.stacksize()&&!p2.stacksize()){
                        p1.cards_taken += pot/2;
                        p2.cards_taken += pot/2;
                        this->add_turn_data(round_data);
                    }
               }
               p1.rounds_played +=1;
               p2.rounds_played +=1;
            }
            }catch(runtime_error& e){
                    cerr << "Exception caught: " << e.what() << endl;
            }

        };

        void Game::printLastTurn(){
                 cout <<  turn_data.front() << endl;
        };

        void Game::add_turn_data(string turn){
                turn_data.insert(turn_data.begin(), turn);
        };

        void Game::playAll(){
            try{
            if(p1.stacksize()&&p2.stacksize()&& this->can_game){
            while (p1.stacksize() && p2.stacksize())
            {
                this->playTurn();
            }
            }else{
                throw ("Game Ended");
            }
            }catch(runtime_error& e){
                    cerr << "Exception caught: " << e.what() << endl;
            }
            
        };

        void Game::printWiner(){
            if(p1.cardesTaken()==p2.cardesTaken()) {
                cout <<"TIE"<< endl;}
            else if(p1.cardesTaken() && p2.cardesTaken()){
                cout << "NO WINNER STILL" <<endl;
            }
                else{
            cout <<( (p1.cardesTaken() > p2.cardesTaken()) ? p1.get_name() : p2.get_name() )<< endl;
                }
            
        };

        void Game::printLog(){
            for(string data : turn_data){
                cout << data << endl;
            }
        };

        void Game::printStats(){
            Player p_arr[] = {p1,p2};
            for(Player player : p_arr){
                cout << player.get_name() << " stats: " << "Win rate: " << player.winRate() << " ,Rounds played: "<<player.rounds_played
                <<" ,Draw rate :" << (static_cast<double>(this->draw)/player.rounds_played) << " ,Draws occured: " << this->draw << "." << endl;
            }
        };
}
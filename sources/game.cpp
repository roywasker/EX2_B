#include "game.hpp"
using namespace ariel;

Game::Game() :player1_(*(new Player())), player2_(*(new Player())), cardlist(std::vector<card>()), turnPlayed(0), loglist(std::vector<std::string>()){
    createCardGame();
    for (auto i = cardlist.begin(); i != cardlist.end(); i = i+2) {     // how to work with vector https://www.geeksforgeeks.org/vector-in-cpp-stl/
        player1_.push(*i);
        player2_.push(*(i+1));
    }
}

Game::Game(Player &player1, Player &player2) :player1_(player1), player2_(player2), cardlist(std::vector<card>()), turnPlayed(0), loglist(std::vector<std::string>()){
    createCardGame();
    for (auto i = cardlist.begin(); i != cardlist.end(); i = i+2) {    // how to work with vector https://www.geeksforgeeks.org/vector-in-cpp-stl/
        player1_.push(*i);
        player2_.push(*(i+1));
    }
}

/**
 * play all remaining games
 */
void Game::playAll() {
    while (player1_.stacksize() != 0 && player2_.stacksize() != 0){
        playTurn();
    }
}

/**
 * play one turn of the game
 */
void Game::playTurn() {
    if(&player1_==&player2_){
        throw std::runtime_error("A player can not play against himself !");
    }
    if (player1_.stacksize() == 0 && player2_.stacksize() == 0 ){
        throw std::runtime_error("The game is over !");
    }
    card player1card = player1_.pop();
    card player2card = player2_.pop();
    int whowin = player1card.compare(player2card);
    if (whowin > 0){ // player 1 win
        player1_.addcardesTaken(2);
        std::string currentlog =""+player1_.getname()+" played "+player1card.getcardname()+" of "+player1card.getcardtype()
                                +" "+player2_.getname()+" played "+player2card.getcardname()+" of "+player2card.getcardtype()+". "+player1_.getname()+" wins.";
        loglist.push_back(currentlog);
        player1_.addtuenwin();
    } else if (whowin < 0){  // player 2 win
        player2_.addcardesTaken(2);
        std::string currentlog =""+player1_.getname()+" played "+player1card.getcardname()+" of "+player1card.getcardtype()
                                +" "+player2_.getname()+" played "+player2card.getcardname()+" of "+player2card.getcardtype()+". "+player2_.getname()+" wins.";
        loglist.push_back(currentlog);
        player2_.addtuenwin();
    }else{  // draw
        int countcard = 2;
        std::string currentlog = ""+player1_.getname()+" played "+player1card.getcardname()+" of "+player1card.getcardtype()
                                 +" "+player2_.getname()+" played "+player2card.getcardname()+" of "+player2card.getcardtype()+". draw.";
        while(player1_.stacksize() >= 0 && player2_.stacksize() >= 0){
            if (player1_.stacksize() == 1){
                player1_.pop();
                player2_.pop();
                countcard = countcard + 2;
                player1_.addcardesTaken(countcard/2);
                player2_.addcardesTaken(countcard/2);
                break;
            }
            if (player1_.stacksize() == 0 && player2_.stacksize() == 0){
                player1_.addcardesTaken(countcard/2);
                player2_.addcardesTaken(countcard/2);
                break;
            }
            player1_.pop();
            player2_.pop();
            player1card = player1_.pop();
            player2card = player2_.pop();
            countcard = countcard + 4;
            whowin = player1card.compare(player2card);
            if (whowin > 0){ // player 1 win
                player1_.addcardesTaken(countcard);
                currentlog.append(" "+player1_.getname()+" played "+player1card.getcardname()+" of "+player1card.getcardtype()
                                  +" "+player2_.getname()+" played "+player2card.getcardname()+" of "+player2card.getcardtype()+". "+player1_.getname()+" wins.");
                player1_.addtuenwin();
                break;
            } else if (whowin < 0){  // player 2 win
                player2_.addcardesTaken(countcard);
                currentlog.append(" "+player1_.getname()+" played "+player1card.getcardname()+" of "+player1card.getcardtype()
                                  +" "+player2_.getname()+" played "+player2card.getcardname()+" of "+player2card.getcardtype()+". "+player2_.getname()+" wins.");
                player2_.addtuenwin();
                break;
            }else if (whowin == 0 && player1_.stacksize() == 0 && player2_.stacksize() == 0 ){ // draw and the player dont have card
                player1_.addcardesTaken(countcard/2);
                player2_.addcardesTaken(countcard/2);
                currentlog.append(" "+player1_.getname()+" played "+player1card.getcardname()+" of "+player1card.getcardtype()
                                  +" "+player2_.getname()+" played "+player2card.getcardname()+" of "+player2card.getcardtype()+". draw.");
                break;
            }
        }
        loglist.push_back(currentlog);
    }
    turnPlayed++;
}

/**
 * print last turn log
 */
void Game::printLastTurn() {
    std::cout << loglist.back()<<std::endl;
}

/**
 * printing  all the log of the games played so far
 */
void Game::printLog() {
    int count = 1;
    for (auto i = loglist.begin(); i != loglist.end(); i++) {
        std::cout << count++ <<". "<< *i << std::endl;
    }
}

/**
 * printing of all the statistics of the 2 players in the games played so far
 */
void Game::printStats() {
    int winrate1 = ((player1_.gerturnwin()*1.) /turnPlayed)*100;
    int winrate2 = ((player2_.gerturnwin()*1.) /turnPlayed)*100;
    std::cout << "Stats for " << player1_.getname() << " win rate : " << winrate1 <<" % , take "<<player1_.cardesTaken()
              <<" cards , and he has  "<<player1_.stacksize() <<" cards left"<<std::endl;
    std::cout << "Stats for " << player2_.getname() << " win rate : " << winrate2 <<" % , take "<<player2_.cardesTaken()
              <<" cards , and he has  "<<player2_.stacksize() <<" cards left"<<std::endl;
}

/**
 * print the winner of the game after all the turn complete
 */
void Game::printWiner() {
    if(player1_.stacksize()>0&&player2_.stacksize()>0){
        std::cout <<"The game is not over yet !"<< std::endl;
        return;
    }
    if(player1_.cardesTaken() > player2_.cardesTaken()){
        std::cout <<"the winner is :"<< player1_.getname() << std::endl;
    } else if (player1_.cardesTaken() < player2_.cardesTaken()){
        std::cout <<"the winner is :"<< player2_.getname() << std::endl;
    } else if (player1_.cardesTaken()==player2_.cardesTaken()){
        std::cout <<"The game ended in a draw !"<< std::endl;
    }
}

/**
 * create vector of all the card in the game
 */
void Game::createCardGame() {
    std::string typeOfCard[] ={"Club","Diamond","Heart","Spade"};
    std::string nameOfCard[] ={"2","3","4","5","6","7","8","9","10","jack","queen","king","ace"};
    for (int i=0; i<4; i++){
        for (int j=0; j<13; j++){
            card c(nameOfCard[j],typeOfCard[i]);
            cardlist.push_back(c);
        }
    }
    shuffle();
}

/**
 *  shuffle the game card
 */
void Game::shuffle(){               // shuffle element in vector  https://en.cppreference.com/w/cpp/algorithm/random_shuffle
    std::random_device rd;
    std::mt19937 rand(rd());
    std::shuffle(cardlist.begin(), cardlist.end(), rand);
}
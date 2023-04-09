#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <stdexcept>
#include <vector>

namespace ariel{
    class Game {
    public:
        Game();
        Game(Player &player1, Player &player2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void createCardGame();
        void shuffle();
    private:
        Player &player1_;
        Player &player2_;
        std::vector<card> cardlist;
        int turnPlayed;
        std::vector<std::string> loglist;
    };
}
#endif //GAME_HPP
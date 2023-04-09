#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "card.hpp"
#include <stack>
#include <stdexcept>

namespace ariel {
    class Player {
    public:
        Player();
        Player(std::string name);
        std::string getname();
        int stacksize();
        int cardesTaken();
        void push(card card);
        card pop();
        card peek();
        void addcardesTaken(int numofcard);
        void addtuenwin();
        int gerturnwin();
    private:
        std::string name_;
        int cardesTaken_;
        std::stack<card> cardstack;
        int turnwin;
    };
}
#endif //PLAYER_HPP
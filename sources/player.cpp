#include "player.hpp"

using namespace ariel;

Player::Player(std::string name) : name_(name), cardesTaken_(0),turnwin(0) {}

Player::Player() : name_("guest"), cardesTaken_(0), turnwin(0) {}

/**
 * get player name
 * @return player name
 */
std::string Player::getname(){return name_;}

/**
 * get the size of card stack
 * @return size of stack
 */
int Player::stacksize(){return cardstack.size();}

/**
 * get the number of card player win
 * @return how much card player win
 */
int Player::cardesTaken(){return cardesTaken_;}

/**
 * push card to stack
 * @param card card to push
 */
void Player::push(card card) {
    cardstack.push(card);
}

/**
 * get the card on top of the stack
 * @return card on top
 */
card Player::peek() {
    if(cardstack.size()!=0) {
        card peekcard = cardstack.top();
        return peekcard;
    }
    throw std::runtime_error("The stack is empty!");
}

/**
 * pop card from stack
 * @return card that we pop
 */
card Player::pop(){
    if(cardstack.size()!=0) {
        card popcard = cardstack.top();
        cardstack.pop();
        return popcard;
    }
    throw std::runtime_error("The stack is empty!");
}

/**
 * add cards that player win
 * @param numofcard number of card that he win this turn
 */
void Player::addcardesTaken(int numofcard) {
    cardesTaken_=cardesTaken_+numofcard;
}

/**
 * add +1 to number of turn that player win
 */
void Player::addtuenwin() {
    turnwin++;
}

/**
 * get the number of turn the player win
 * @return number of turn the player win
 */
int Player::gerturnwin() {
    return turnwin;
}
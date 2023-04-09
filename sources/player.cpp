#include "player.hpp"

using namespace ariel;

Player::Player(std::string name) : name_(name), cardesTaken_(0),turnwin(0) {}

Player::Player() : name_("guest"), cardesTaken_(0), turnwin(0) {}

std::string Player::getname(){return name_;}

int Player::stacksize(){return cardstack.size();}

int Player::cardesTaken(){return cardesTaken_;}

void Player::push(card card) {
    cardstack.push(card);
}

card Player::peek() {
    if(cardstack.size()!=0) {
        card peekcard = cardstack.top();
        return peekcard;
    }
    throw std::runtime_error("The stack is empty!");
}

card Player::pop(){
    if(cardstack.size()!=0) {
        card popcard = cardstack.top();
        cardstack.pop();
        return popcard;
    }
    throw std::runtime_error("The stack is empty!");
}
void Player::addcardesTaken(int numofcard) {
    cardesTaken_=cardesTaken_+numofcard;
}
void Player::addtuenwin() {
    turnwin++;
}
int Player::gerturnwin() {
    return turnwin;
}
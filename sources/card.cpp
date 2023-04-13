#include "card.hpp"
#include <stdexcept>

using namespace ariel;

card::card(std::string name, std::string type) : name_(name) , type_(type){}

card::card() : name_("king") , type_("diamonds"){}

std::string card::getcardname(){return name_;}

std::string card::getcardtype(){ return type_;}

/**
 * Conversion of the card name to its int number
 * @param name name of the card
 * @return Card number by int
 */
int strToInt(std::string name) {
    int numOfCard = 0;
    try {                                   // Convert String to int  https://www.geeksforgeeks.org/stdstoi-function-in-cpp/
        numOfCard = std::stoi(name);
    } catch (const std::invalid_argument &e) {
        if (name == "jack") {
            numOfCard = 11;
        } else if (name == "queen") {
            numOfCard = 12;
        } else if (name == "king") {
            numOfCard = 13;
        } else if(name == "ace"){
            numOfCard = 14;
        } else{
            numOfCard = -1;
        }
    }
    return numOfCard;
}

/**
 * Comparison between 2 cards
 * @param card1 card to compare with
 * @return A positive number if a card is greater than card1 , 0 if they equal and negative number if a card is smaller than card1
 */
int card::compare(card card1) {
    int digOfCard1 = strToInt(name_);
    int digOfCard2 = strToInt(card1.getcardname());
    if(digOfCard1 == 14 || digOfCard2 == 14){
        if(digOfCard1==14 && digOfCard2 == 2){
            return -1;
        } else if (digOfCard2==14 && digOfCard1 == 2){
            return 1;
        }
    }
    if(digOfCard1 == -1 || digOfCard2== -1){
        return -100;
    }
    return digOfCard1-digOfCard2;
}
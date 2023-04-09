#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;


// clang++-14 -Wall sources/card.cpp sources/game.cpp sources/player.cpp Test.cpp -o test

int main() {
    for (int i = 0; i < 1000; ++i) {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        game.playAll();
        int sum = p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken();
        /*std::cout << p1.stacksize() << "," << p1.cardesTaken() << "," << p2.stacksize() << "," << p2.cardesTaken()
                  << ", sum " << sum << std::endl;*/
        if(sum!=52){
            std::cout <<"filed"<<std::endl;
            game.printLog();
            break;
        }
    }
    return 0;
}

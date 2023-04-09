#ifndef CARD_HPP
#define CARD_HPP

#include <string>

namespace ariel {
    class card {
    public:
        card();
        card(std::string name, std::string type);
        std::string getcardname();
        std::string getcardtype();
        int compare(card card1);
    private:
        std::string name_;
        std::string type_;
    };
}
#endif //CARD_HPP
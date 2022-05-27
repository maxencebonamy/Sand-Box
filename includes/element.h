#ifndef SANDBOX_ELEMENT_H
#define SANDBOX_ELEMENT_H

#include <SFML/Graphics.hpp>


enum State {SOLID, LIQUID, DUST, GAZ, PLASMA};


class Element {

public:
    Element(std::string name, sf::Keyboard::Key key, State state, std::vector<sf::Color> colors);
    std::string getName();
    sf::Color getColor() const;
    sf::Keyboard::Key getKey();
    State getState();

    bool operator==(Element other);
    bool operator!=(Element other);

private:
    std::string name;
    sf::Keyboard::Key key;
    std::vector<sf::Color> colors;
    State state;

};


const Element VOID = Element("Void", sf::Keyboard::N, SOLID, {
        {12, 15, 10}
});

const Element WATER = Element("Water", sf::Keyboard::W, LIQUID, {
//        {6,66,115},
        {10, 14, 41},
        {15, 19, 46},
//        {23, 27, 65},
//        {21, 33, 59},
//        {48, 75, 120},
//        {36, 148, 162}
});

const Element STEAM = Element("Steam", sf::Keyboard::V, GAZ, {
        {22, 25, 20}
});

const Element SAND = Element("Sand", sf::Keyboard::S, DUST, {
        {242,210,169},
        {236,204,162},
        {231,196,150},
        {225,191,146}
});

const Element WOOD = Element("Wood", sf::Keyboard::L, SOLID, {
        {49, 18, 4},
        {77, 60, 35}
});

const Element FIRE = Element("Fire", sf::Keyboard::F, PLASMA, {
        {255,0,0},
        {255,90,0},
        {255,154,0},
        {255,206,0},
        {255,232,8}
});

const Element ASH = Element("Ash", sf::Keyboard::A, DUST, {
        {208,198,198},
        {195,185,185},
        {180,168,168},
        {169,157,157},
        {159,147,147}
});

const Element STONE = Element("Stone", sf::Keyboard::R, SOLID, {
        {73,60,60},
        {92,73,73},
        {101,83,83}
});

const Element ACID = Element("Acid", sf::Keyboard::Z, LIQUID, {
        {137,255,0},
        {253,255,0}
});

const Element ICE = Element("Ice", sf::Keyboard::I, SOLID, {
        {192, 247, 255},
        {148, 247, 255}
});

const Element SNOW = Element("Snow", sf::Keyboard::J, DUST, {
        {255,255,255},
        {236,255,253},
        {208,236,235}
});


const std::vector<Element> ELEMENTS = {VOID, WATER, STEAM, SAND, WOOD, FIRE, ASH, STONE, ACID, ICE, SNOW};


#endif

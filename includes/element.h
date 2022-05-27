#ifndef SANDBOX_ELEMENT_H
#define SANDBOX_ELEMENT_H

#include <SFML/Graphics.hpp>


enum State {SOLID, LIQUID, DUST, GAZ, PLASMA};


class Element {

public:
    Element(std::string name, sf::Keyboard::Key key, std::vector<sf::Color> colors, State state);
    std::string getName();
    sf::Color getColor();
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


const std::vector<sf::Color> VOID_COLORS = {
        {12, 15, 10}
};
const Element VOID = Element("Void", sf::Keyboard::N, VOID_COLORS, SOLID);

const std::vector<sf::Color> WATER_COLORS = {
        {6,66,115}
};
const Element WATER = Element("Water", sf::Keyboard::W, WATER_COLORS, LIQUID);

const std::vector<sf::Color> STEAM_COLORS = {
        {22, 25, 20}
};
const Element STEAM = Element("Steam", sf::Keyboard::V, STEAM_COLORS, GAZ);

const std::vector<sf::Color> SAND_COLORS = {
//        {246,215,17},
        {242,210,169},
        {236,204,162},
        {231,196,150},
        {225,191,146}
};
const Element SAND = Element("Sand", sf::Keyboard::S, SAND_COLORS, DUST);

const std::vector<sf::Color> WOOD_COLORS = {
        {132,36,12},
//        {218,109,66}
};
const Element WOOD = Element("Wood", sf::Keyboard::L, WOOD_COLORS, SOLID);

const std::vector<sf::Color> FIRE_COLORS = {
        {255,0,0},
        {255,90,0},
        {255,154,0},
        {255,206,0},
        {255,232,8}
};
const Element FIRE = Element("Fire", sf::Keyboard::F, FIRE_COLORS, PLASMA);

const std::vector<sf::Color> ASH_COLORS = {
        {208,198,198},
        {195,185,185},
        {180,168,168},
        {169,157,157},
        {159,147,147}
};
const Element ASH = Element("Ash", sf::Keyboard::A, ASH_COLORS, DUST);

const std::vector<sf::Color> STONE_COLORS = {
        {73,60,60},
        {92,73,73},
        {101,83,83}

};
const Element STONE = Element("Stone", sf::Keyboard::R, STONE_COLORS, SOLID);

const std::vector<sf::Color> ACID_COLORS = {
        {137,255,0},
        {253,255,0}
};
const Element ACID = Element("Acid", sf::Keyboard::Z, ACID_COLORS, LIQUID);


const std::vector<Element> ELEMENTS = {VOID, WATER, STEAM, SAND, WOOD, FIRE, ASH, STONE, ACID};


#endif

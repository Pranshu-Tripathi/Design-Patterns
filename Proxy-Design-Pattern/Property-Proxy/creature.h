#pragma once

class Creature {
    public:
        Creature(int strenght, int health, int agility) : strenght(strenght), health(health), agility(agility) {}
        int strenght = 10;
        int health = 100;
        int agility = 60;
};
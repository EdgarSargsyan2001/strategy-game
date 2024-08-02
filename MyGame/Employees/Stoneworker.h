#ifndef STONEWORKER
#define STONEWORKER
#include <iostream>
#include "Employee.h"
#include "../Resources/Resources.h"

class Stoneworker : public Employee
{
public:
    static Resources cost()
    {
        Resources res;
        res.add_money((8 * count) + 8);
        res.add_wood((5 * count) + 2);
        return res;
    }
    static char count;

private:
    // to_work
    static const char amount_of_work = 3;
    static const char energy_spent = 15;

    // gather_energy
    static const char collected_energy = 15;
    static const char spent_food = 1;

public:
    Stoneworker() { count++; };

    void to_work(Resources &res) override
    {
        if (get_energy() != 0)
        {
            res.add_stone(amount_of_work);
            add_energy(-energy_spent);
        }
    }
    void gather_energy(Resources &res) override
    {
        if (res.get_food() >= spent_food)
        {
            add_energy(collected_energy);
            res.add_food(-spent_food);
        }
    }
};

#endif
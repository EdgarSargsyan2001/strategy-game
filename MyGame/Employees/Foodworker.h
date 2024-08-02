#ifndef FOODWORKER
#define FOODWORKER
#include <iostream>
#include "Employee.h"
#include "../Resources/Resources.h"

class Foodworker : public Employee
{
public:
    static Resources cost()
    {
        Resources res;
        res.add_money((3 * count) + 3);
        res.add_wood((2 * count) + 2);
        res.add_stone(2 + count);
        return res;
    }
    static char count;

private:
    // to_work
    static const char amount_of_work = 8 + 1;
    static const char energy_spent = 7;

    // gather_energy
    static const char collected_energy = 14;
    static const char spent_food = 1;

public:
    Foodworker() { count++; };
    void to_work(Resources &res) override
    {
        if (get_energy() != 0)
        {
            res.add_food(amount_of_work);
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
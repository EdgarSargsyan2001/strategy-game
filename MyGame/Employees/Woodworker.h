#ifndef WOODWORKER
#define WOODWORKER
#include <iostream>
#include "Employee.h"
#include "../Resources/Resources.h"

class Woodworker : public Employee
{
public:
    static Resources cost()
    {
        Resources res;
        res.add_money((5 * count) + 5);
        res.add_stone(2 * count);
        return res;
    }
    static char count;

private:
    // to_work
    static const char amount_of_work = 4;
    static const char energy_spent = 10;

    // gather_energy
    static const char collected_energy = 10;
    static const char spent_food = 1;

public:
    Woodworker() { count++; };

    void to_work(Resources &res) override
    {
        if (get_energy() != 0)
        {
            res.add_wood(amount_of_work);
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
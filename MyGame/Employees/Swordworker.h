#ifndef SWORDWORKER
#define SWORDWORKER
#include <iostream>
#include "Employee.h"
#include "../Resources/Resources.h"

class Swordworker : public Employee
{
public:
    static Resources cost()
    {
        Resources res;
        res.add_money((15 * count) + 15);
        res.add_wood(14 + count);
        res.add_stone((5 * count) + 5);
        return res;
    }
    static char count;

private:
    // to_work
    static const char amount_of_work = 1;
    static const char energy_spent = 10;
    static const char spent_iron = 1;

    // gather_energy
    static const char collected_energy = 10;
    static const char spent_food = 1;

public:
    Swordworker() { count++; };

    void to_work(Resources &res) override
    {
        if (get_energy() != 0 && res.get_iron() != 0)
        {
            res.add_sword(amount_of_work);
            res.add_iron(-spent_iron);
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
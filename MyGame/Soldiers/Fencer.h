#ifndef FENCER
#define FENCER
#include <iostream>
#include <math.h>
#include "Soldier.h"
#include "../Resources/Resources.h"

enum FencerPicture
{
    enemy = 1,
    my = 2
};

class Fencer : public Soldier // սուսերամարտիկ
{
public:
    static Resources cost()
    {
        Resources res;
        res.add_money(7);
        res.add_sword(4);
        return res;
    }

private:
    // life
    static const short life_count = 100;
    // to_hit
    static const char hitting_power = 50;
    static const char energy_spent_for_hit = 10;

    // to move
    static const char energy_spent_for_move = 5;

    // gather_energy
    static const char collected_energy = 15;
    static const char spent_food = 2;

public:
    Fencer() : Soldier(life_count){};
    Fencer(Point p) : Soldier(life_count)
    {
        set_point(p);
    };

    void add_in_board(Board &map, char pictur) override
    {
        if (!map.set_figure(m_point, pictur /*figure*/))
        {
            m_point.set_x(0);
            m_point.set_y(0);
        }
    }
    bool can_hit(Soldier *enemy) override
    {
        Point enemy_p = enemy->get_point();
        double d = std::sqrt(std::pow(enemy_p.get_x() - m_point.get_x(), 2) + std::pow(enemy_p.get_y() - m_point.get_y(), 2));
        if (d <= 1.5)
        {
            return true;
        }
        return false;
    }
    void to_hit(Resources &res, Soldier *enemy) override
    {
        if (get_energy() != 0)
        {
            enemy->add_life(-hitting_power);
            add_energy(-energy_spent_for_hit);
        }
    }
    void to_move() override
    {
        if (m_path.size() > 0 && get_energy() > 0)
        {
            set_point(m_path.back());
            if (get_energy() != 0)
            {
                add_energy(-energy_spent_for_move);
            }
            m_path.pop_back();
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
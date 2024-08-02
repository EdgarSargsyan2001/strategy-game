#ifndef MYGAME
#define MYGAME
#include <iostream>
#include <unistd.h>
#include <vector>
#include <list>
#include <map>
#include "Resources/Resources.h"
#include "Employees/Employee.h"
#include "Employees/Employee.h"
#include "Employees/Woodworker.h"
#include "Employees/Stoneworker.h"
#include "Employees/Foodworker.h"
#include "Employees/Ironworker.h"
#include "Employees/Swordworker.h"
#include "Soldiers/Soldier.h"
#include "Soldiers/Fencer.h"
#include "Board/Board.h"
#include "Board/Square.h"

class MyGame
{
public:
    MyGame();
    ~MyGame();

public:
    void print_day_in_screen() const;
    void print_resources_in_screen() const;
    void print_board_in_screen() const;
    void run_day();
    void change_day() { day++; }

    //
    void buy_worker();
    void buy_soldier();
    void resource_store();
    void resource_management();
    void move_soldier();

private:
    void sell_resources_auto();
    void soldier_hit_day(std::list<Soldier *>, std::list<Soldier *> &);
    bool can_buy_employee(const Resource_enum);
    bool can_buy_soldier(const Soldier_enum);
    char get_soldier_pictur(const Soldier_enum);
    Employee *buy_employee(const Resource_enum);
    Soldier *buy_soldier(const Soldier_enum);

private:
    void buy_worker_helper(const Resource_enum n);
    void buy_soldier_helper(const Soldier_enum n);

    void resource_store_helper(const std::string &name, int count, const Resource_enum n);
    void resource_management_helper(const std::string &name, const Resource_enum res);

private:
    std::list<Employee *> m_employees;     // workers աշխատողներ
    std::list<Soldier *> m_soldiers;       // Soldiers զինվորներ
    std::list<Soldier *> m_enemy_soldiers; // թշնամու զինվորներ
    std::map<Resource_enum, int> m_resource_mgmt;
    Board m_board;
    Resources m_resources{10, 30, 10, 10000, 0};
    Resources m_enemy_resources{30000, 30000, 30000, 30000, 30000};
    int day{0};
};

#endif
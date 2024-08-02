#ifndef SOLDIER
#define SOLDIER
#include "../Board/Board.h"
#include "../Resources/Resources.h"
#include "../Board/Point.h"

enum class Soldier_enum : char
{
    Fencer,
};

class Soldier
{
public:
    Soldier(short l) : m_life(l){};
    virtual ~Soldier(){};
    //
    virtual void to_hit(Resources &res, Soldier *enemy) = 0;
    virtual bool can_hit(Soldier *enemy) = 0;
    virtual void gather_energy(Resources &res) = 0;
    virtual void add_in_board(Board &map, char pictur) = 0;
    virtual void to_move() = 0;

    // setters
    void set_path(std::vector<Point> p) { m_path = std::move(p); };
    void set_point(Point p) { m_point = p; };
    void add_life(short n) { m_life += n; };

    // getters
    short get_path_length() { return m_path.size(); };
    bool is_die() { return m_life <= 0; };
    Point get_point() const { return m_point; };
    short get_life() { return m_life; };

protected:
    void add_energy(short n) { m_energy += n; };
    short get_energy() { return m_energy; };

protected:
    std::vector<Point> m_path;
    Point m_point{0, 0};
    short m_energy{80};
    short m_life;
};

#endif
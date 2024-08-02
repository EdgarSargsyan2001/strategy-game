#ifndef POINT_H
#define POINT_H

class Point
{

public:
    Point() : m_x(-1), m_y(-1){};
    Point(int a, int b) : m_x(a), m_y(b){};

    int get_x() const { return m_x; };
    int get_y() const { return m_y; };
    void set_x(int x) { m_x = x; };
    void set_y(int y) { m_y = y; };
    bool is_equal(const Point &p)
    {
        if ((m_x == p.m_x) && (m_y == p.m_y))
        {
            return true;
        }
        return false;
    }

private:
    int m_x;
    int m_y;
};

#endif
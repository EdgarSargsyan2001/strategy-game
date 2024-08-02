#ifndef SQUARE
#define SQUARE

class Square
{
public:
    Square() {}
    Square(char a, char b) : m_count(a), m_figure(b) {}

    //
    bool is_same_figure(char f) const
    {
        return m_figure == f;
    }
    void clean_square()
    {
        set_figure(':');
        set_count(0);
    }
    bool is_figure_soldiar()
    {
        if (m_figure == ']' || m_figure == ':')
        {
            return false;
        }

        return true;
    }

    //
    char get_figure() const { return m_figure; };
    char get_count() const { return m_count; };

    //
    void set_figure(char f) { m_figure = f; };
    void set_count(char n) { m_count = n; };
    void inc_count() { m_count += 1; };

    //
    void print(bool type) const
    {
        if (m_figure == ':')
        {
            std::cout << ':' << ':';
        }
        else if (m_figure == ']')
        {
            std::cout << m_count << m_figure;
        }
        else
        {
            std::cout << (short)m_count << m_figure;
        }
    }

private:
    char m_count{0};
    char m_figure{':'};
};

#endif

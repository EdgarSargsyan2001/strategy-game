#ifndef RESOURCES
#define RESOURCES
#include <iostream>
#include <string>

enum class Resource_enum : char
{
    wood,
    food,
    iron,
    stone,
    sword,
};

class Resources
{
public:
    static short resource_price_to_sell(Resource_enum n)
    {
        switch (n)
        {
        case Resource_enum::wood:
            return 1; // wood price to sell
        case Resource_enum::iron:
            return 2; // iron price to sell
        case Resource_enum::stone:
            return 1; // stone price to sell
        case Resource_enum::food:
            return 1; // food price to sell
        case Resource_enum::sword:
            return 3; // food price to sell
        }
        return -1;
    }
    static short resource_price_to_buy(const Resource_enum n)
    {
        switch (n)
        {
        case Resource_enum::wood:
            return 3; // wood price to buy
        case Resource_enum::iron:
            return 5; // iron price to buy
        case Resource_enum::stone:
            return 4; // stone price to buy
        case Resource_enum::food:
            return 3; // food price to buy
        case Resource_enum::sword:
            return 5;
        }
        return -1;
    }

public:
    Resources(){};
    Resources(short money, short wood, short stone, short food, short iron)
        : m_money(money), m_wood(wood), m_stone(stone), m_food(food), m_iron(iron){};

    //
    bool buy_resoure(const Resource_enum res, const short count)
    {
        short price = resource_price_to_buy(res) * count;
        if (m_money >= price)
        {
            add_money(-price);
            switch (res)
            {
            case Resource_enum::wood:
                add_wood(count);
                break;
            case Resource_enum::iron:
                add_iron(count);
                break;
            case Resource_enum::stone:
                add_stone(count);
                break;
            case Resource_enum::food:
                add_food(count);
                break;
            case Resource_enum::sword:
                add_food(count);
                break;
            }
            return true;
        }

        return false;
    }
    bool sell_resoure(const Resource_enum res, const short count)
    {
        switch (res)
        {
        case Resource_enum::wood:
            if (m_wood < count)
            {
                return false;
            }
            add_wood(-count);
            break;
        case Resource_enum::iron:
            if (m_iron < count)
            {
                return false;
            }
            add_iron(-count);
            break;
        case Resource_enum::stone:
            if (m_stone < count)
            {
                return false;
            }
            add_stone(-count);
            break;
        case Resource_enum::food:
            if (m_food < count)
            {
                return false;
            }
            add_food(-count);
            break;
        case Resource_enum::sword:
            if (m_sword < count)
            {
                return false;
            }
            add_sword(-count);
            break;
        }
        short price = resource_price_to_sell(res) * count;
        add_money(price);
        return true;
    }

    //
    bool can_buy(const Resources &r)
    {
        if (this == &r)
        {
            return false;
        }
        if ((m_food >= r.m_food) && (m_money >= r.m_money) && (m_wood >= r.m_wood) && (m_iron >= r.m_iron) && (m_stone >= r.m_stone) && (m_sword >= r.m_sword))
        {
            return true;
        }
        return false;
    }
    short get_resoure(const Resource_enum res)
    {
        switch (res)
        {
        case Resource_enum::wood:
            return get_wood();
        case Resource_enum::iron:
            return get_iron();
        case Resource_enum::stone:
            return get_stone();
        case Resource_enum::food:
            return get_food();
        case Resource_enum::sword:
            return get_sword();
        }
        return -1;
    }
    void buy(const Resources &r)
    {
        add_food(-r.m_food);
        add_money(-r.m_money);
        add_iron(-r.m_iron);
        add_wood(-r.m_wood);
        add_stone(-r.m_stone);
        add_sword(-r.m_sword);
    }

    // setters
    // void set_money(short n) { m_money = n; };
    // void set_wood(short n) { m_wood = n; };
    // void set_stone(short n) { m_stone = n; };
    // void set_food(short n) { m_food = n; };
    // void set_iron(short n) { m_iron = n; };

    void add_money(short n) { m_money += n; };
    void add_wood(short n) { m_wood += n; };
    void add_stone(short n) { m_stone += n; };
    void add_food(short n) { m_food += n; };
    void add_iron(short n) { m_iron += n; };
    void add_sword(short n) { m_sword += n; };

    // getters
    short get_money() const { return m_money; };
    short get_wood() const { return m_wood; };
    short get_stone() const { return m_stone; };
    short get_food() const { return m_food; };
    short get_iron() const { return m_iron; };
    short get_sword() const { return m_sword; };

    //
    void print_screen(short woodworker_count, short stoneworker_count, short foodworker_count, short ironworker_count, short swordworker_count) const
    {
        std::cout << "Money:[" << m_money << "]  ";
        std::cout << "\t\tWood:[" << m_wood << "]/" << woodworker_count << "  ";
        std::cout << "Stone:[" << m_stone << "]/" << stoneworker_count << "  ";
        std::cout << "Food:[" << m_food << "]/" << foodworker_count << "  ";
        std::cout << "Iron:[" << m_iron << "]/" << ironworker_count << "  ";
        std::cout << "Sword:[" << m_sword << "]/" << swordworker_count << "  ";
    }
    std::string to_str() const
    {
        std::string str = "";
        if (m_money != 0)
        {
            str += " [" + std::to_string(m_money) + " money ] ";
        }
        if (m_food != 0)
        {
            str += " [" + std::to_string(m_food) + " food ] ";
        }
        if (m_iron != 0)
        {
            str += " [" + std::to_string(m_iron) + " iron ] ";
        }
        if (m_stone != 0)
        {
            str += " [" + std::to_string(m_stone) + " stone ] ";
        }
        if (m_wood != 0)
        {
            str += " [" + std::to_string(m_wood) + " wood ] ";
        }
        if (m_sword != 0)
        {
            str += " [" + std::to_string(m_sword) + " sword ] ";
        }

        return str;
    }

private:
    short m_money{0};
    short m_wood{0};
    short m_stone{0};
    short m_food{0};
    short m_iron{0};
    short m_sword{0};
};

#endif
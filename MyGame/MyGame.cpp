#include "MyGame.h"

MyGame::MyGame()
{
    m_resource_mgmt.insert({Resource_enum::wood, 0});
    m_resource_mgmt.insert({Resource_enum::food, 0});
    m_resource_mgmt.insert({Resource_enum::iron, 0});
    m_resource_mgmt.insert({Resource_enum::stone, 0});

    // m_resources.add_sword(400);
    // m_resources.add_iron(200);
    // m_resources.add_stone(200);
    // m_resources.add_money(1000);

    for (int k = 0; k < 3; ++k)
    {
        for (int i = 0; i < 8; ++i)
        {
            m_enemy_soldiers.push_back(new Fencer(Point(0 + k, 9)));
            m_enemy_soldiers.back()->add_in_board(m_board, FencerPicture::enemy);
        }
    }
};
MyGame::~MyGame()
{
    for (auto ptr : m_employees)
    {
        delete ptr;
    }
    for (auto ptr : m_soldiers)
    {
        delete ptr;
    }
    for (auto ptr : m_enemy_soldiers)
    {
        delete ptr;
    }
}

void MyGame::buy_worker()
{
    int n = 0;
    std::cout << "\n  ==== Buy Worker ==== \n";
    std::cout << "\n  :0: go back \n";
    std::cout << "  :1: wood worker:  cost's" << Woodworker::cost().to_str() << "\t\t\t\t" << (can_buy_employee(Resource_enum::wood) ? '+' : '-') << '\n';
    std::cout << "  :2: stone worker: cost's" << Stoneworker::cost().to_str() << "\t\t" << (can_buy_employee(Resource_enum::stone) ? '+' : '-') << '\n';
    std::cout << "  :3: food worker:  cost's" << Foodworker::cost().to_str() << "\t" << (can_buy_employee(Resource_enum::food) ? '+' : '-') << '\n';
    std::cout << "  :4: iron worker:  cost's" << Ironworker::cost().to_str() << "\t" << (can_buy_employee(Resource_enum::iron) ? '+' : '-') << '\n';
    std::cout << "  :5: sword worker: cost's" << Swordworker::cost().to_str() << " " << (can_buy_employee(Resource_enum::sword) ? '+' : '-') << '\n';

    std::cout << "  Enter command number: ";
    std::cin >> n;
    switch (n)
    {
    case 0:
        return;
    case 1:
        buy_worker_helper(Resource_enum::wood);
        break;
    case 2:
        buy_worker_helper(Resource_enum::stone);
        break;
    case 3:
        buy_worker_helper(Resource_enum::food);
        break;
    case 4:
        buy_worker_helper(Resource_enum::iron);
        break;
    case 5:
        buy_worker_helper(Resource_enum::sword);
        break;
    }
}

void MyGame::buy_worker_helper(const Resource_enum name)
{
    if (can_buy_employee(name))
    {
        m_employees.push_back(buy_employee(name));
    }
    else
    {
        std::cout << "Not Enough Resources!!!\n";
        sleep(1);
    }
}

bool MyGame::can_buy_employee(const Resource_enum n)
{
    switch (n)
    {
    case Resource_enum::wood:
        return m_resources.can_buy(Woodworker::cost());
    case Resource_enum::food:
        return m_resources.can_buy(Foodworker::cost());
    case Resource_enum::iron:
        return m_resources.can_buy(Ironworker::cost());
    case Resource_enum::stone:
        return m_resources.can_buy(Stoneworker::cost());
    case Resource_enum::sword:
        return m_resources.can_buy(Swordworker::cost());
    }
    return false;
}

Employee *MyGame::buy_employee(const Resource_enum n)
{
    switch (n)
    {
    case Resource_enum::wood:
        m_resources.buy(Woodworker::cost());
        return (new Woodworker());

    case Resource_enum::food:
        m_resources.buy(Foodworker::cost());
        return (new Foodworker());

    case Resource_enum::iron:
        m_resources.buy(Ironworker::cost());
        return (new Ironworker());

    case Resource_enum::stone:
        m_resources.buy(Stoneworker::cost());
        return (new Stoneworker());
    case Resource_enum::sword:
        m_resources.buy(Swordworker::cost());
        return (new Swordworker());
    }
    return nullptr;
}
void MyGame::resource_store()
{
    int n = 0;
    int count;
    std::cout << "\n  ==== Resource Store ==== \n";
    std::cout << "\n  :0: go back \n";
    std::cout << "  :1: -[" << Resources::resource_price_to_sell(Resource_enum::wood) << "] wood  +[" << Resources::resource_price_to_buy(Resource_enum::wood) << "]\n";
    std::cout << "  :2: -[" << Resources::resource_price_to_sell(Resource_enum::stone) << "] stone +[" << Resources::resource_price_to_buy(Resource_enum::stone) << "]\n";
    std::cout << "  :3: -[" << Resources::resource_price_to_sell(Resource_enum::food) << "] food  +[" << Resources::resource_price_to_buy(Resource_enum::food) << "]\n";
    std::cout << "  :4: -[" << Resources::resource_price_to_sell(Resource_enum::iron) << "] iron  +[" << Resources::resource_price_to_buy(Resource_enum::iron) << "]\n";
    std::cout << "  :5: -[" << Resources::resource_price_to_sell(Resource_enum::sword) << "] sword  +[" << Resources::resource_price_to_buy(Resource_enum::sword) << "]\n";
    std::cout << "  Enter command number: ";
    std::cin >> n;
    if (n == 0)
    {
        return;
    }
    std::cout << "  Enter count of resource: ";
    std::cin >> count;

    switch (n)
    {
    case 0:
        return;
    case 1:
        resource_store_helper("wood", count, Resource_enum::wood);
        break;
    case 2:
        resource_store_helper("stone", count, Resource_enum::stone);
        break;
    case 3:
        resource_store_helper("food", count, Resource_enum::food);
        break;
    case 4:
        resource_store_helper("iron", count, Resource_enum::iron);
        break;
    case 5:
        resource_store_helper("sword", count, Resource_enum::sword);
        break;
    }
}

void MyGame::resource_store_helper(const std::string &name, int count, const Resource_enum res)
{
    int n;
    std::cout << "    -> " << name << "\n";
    std::cout << "    :1: sell  [" << count << " " << name << "] -> [ " << Resources::resource_price_to_sell(res) * count << " money ]\n";
    std::cout << "    :2: buy   [" << count << " " << name << "] <- [ " << Resources::resource_price_to_buy(res) * count << " money ]\n";
    std::cout << "    Enter command number: ";
    std::cin >> n;
    switch (n)
    {
    case 0:
        return;
    case 1:
        if (!m_resources.sell_resoure(res, count))
        {
            std::cout << "Not Enough Resources!!!\n";
            sleep(1);
        }
        break;
    case 2:
        if (!m_resources.buy_resoure(res, count))
        {
            std::cout << "Not Enough Resources!!!\n";
            sleep(1);
        }
        break;
    }
}
void MyGame::sell_resources_auto()
{
    short max_count = 0;
    short my_res_count = 0;
    for (auto it = m_resource_mgmt.begin(); it != m_resource_mgmt.end(); ++it)
    {

        max_count = it->second;                            //  Value -> it->second
        my_res_count = m_resources.get_resoure(it->first); //  Key -> it->first

        if ((max_count > 0) && (my_res_count > max_count))
        {
            m_resources.sell_resoure(it->first, my_res_count - max_count);
        }
    }
}

void MyGame::resource_management_helper(const std::string &name, const Resource_enum res)
{
    int n = 0;
    std::cout << "  -> " << name << '\n';
    std::cout << "    Enter maximum count: ";
    std::cin >> n;
    m_resource_mgmt[res] = n;
}

void MyGame::resource_management()
{

    int n = 0;
    std::cout << "\n  ==== Resource Management ==== \n";
    std::cout << "\n  :0: go back \n";
    std::cout << "  :1: wood  max -> [ " << m_resource_mgmt[Resource_enum::wood] << " ]\n";
    std::cout << "  :2: stone max -> [ " << m_resource_mgmt[Resource_enum::stone] << " ]\n";
    std::cout << "  :3: food  max -> [ " << m_resource_mgmt[Resource_enum::food] << " ]\n";
    std::cout << "  :4: iron  max -> [ " << m_resource_mgmt[Resource_enum::iron] << " ]\n";
    std::cout << "  Enter command number: to change: ";
    std::cin >> n;
    switch (n)
    {
    case 0:
        return;
    case 1:
        resource_management_helper("wood", Resource_enum::wood);
        break;
    case 2:
        resource_management_helper("stone", Resource_enum::stone);
        break;
    case 3:
        resource_management_helper("food", Resource_enum::food);
        break;
    case 4:
        resource_management_helper("iron", Resource_enum::iron);
        break;
    }
    sell_resources_auto();
}

void MyGame::buy_soldier()
{
    std::cout << "\n  ==== Buy Soldier ==== \n";
    std::cout << "\n  :0: go back \n";
    std::cout << "  :1: Fencer:  cost's " << Fencer::cost().to_str() << "\t\t" << (can_buy_soldier(Soldier_enum::Fencer) ? '+' : '-') << '\n';
    int n;
    std::cin >> n;
    switch (n)
    {
    case 0:
        return;
    case 1:
        buy_soldier_helper(Soldier_enum::Fencer);
    }
}
void MyGame::buy_soldier_helper(const Soldier_enum name)
{
    if (can_buy_soldier(name))
    {
        m_soldiers.push_back(buy_soldier(name));
        m_soldiers.back()->add_in_board(m_board, get_soldier_pictur(name));
    }
    else
    {
        std::cout << "Not Enough Resources!!!\n";
        sleep(1);
    }
}

char MyGame::get_soldier_pictur(const Soldier_enum n)
{
    switch (n)
    {
    case Soldier_enum::Fencer:
        return FencerPicture::my;
    }
    return 'A';
}

bool MyGame::can_buy_soldier(const Soldier_enum n)
{
    switch (n)
    {
    case Soldier_enum::Fencer:
        return m_resources.can_buy(Fencer::cost());
    }
    return false;
}
Soldier *MyGame::buy_soldier(const Soldier_enum n)
{
    switch (n)
    {
    case Soldier_enum::Fencer:
        m_resources.buy(Fencer::cost());
        return (new Fencer());
    }
    return nullptr;
}
void MyGame::move_soldier()
{
    std::cout << "Enter start point ";
    int x, y;
    std::cin >> x >> y;
    Point start_p(x, y);
    char start_fig = m_board.get_figure(start_p);
    if (start_fig != FencerPicture::my)
    {
        std::cout << "there isn't soldier ";
        sleep(1);
        return;
    }

    std::cout << "Enter end point ";
    std::cin >> x >> y;
    Point end_p(x, y);
    char end_fig = m_board.get_figure(end_p);

    if ((end_fig != ':') && (end_fig != start_fig))
    {
        std::cout << "there isn't come ";
        sleep(1);
        return;
    }
    std::cout << "Enter soldier count ";
    std::cin >> x;

    if (m_board.get_count(start_p) < x)
    {
        std::cout << "there are not so many soldiers ";
        sleep(1);
        return;
    }

    auto new_path = std::move(m_board.findShortestPath(start_p, end_p, start_fig));
    if (new_path.size() == 0)
    {
        std::cout << "there isn't path ";
        sleep(1);
        return;
    }
    for (auto soldier : m_soldiers)
    {
        if (soldier->get_point().is_equal(start_p) && x)
        {
            soldier->set_path(new_path);
            soldier->to_move();
            --x;
        }
    }
}

void MyGame::soldier_hit_day(std::list<Soldier *> soldiers, std::list<Soldier *> &enemy_soldiers)
{
    std::list<Soldier *> pointersToDelete;
    for (auto soldier : soldiers)
    {
        for (auto enemy_soldier : enemy_soldiers)
        {
            if (soldier->can_hit(enemy_soldier) && !enemy_soldier->is_die())
            {
                soldier->to_hit(m_resources, enemy_soldier);
                if (enemy_soldier->is_die())
                {
                    pointersToDelete.push_back(enemy_soldier);
                }
                break;
            }
        }
    }

    for (auto ptr : pointersToDelete)
    {
        enemy_soldiers.remove(ptr);
        delete ptr;
    }
}

void MyGame::run_day()
{
    m_board.clean_board();
    if (day == 50)
    {
        Point start_p1(0, 9);
        Point start_p2(1, 9);

        auto path1 = std::move(m_board.findShortestPath(start_p1, Point(1, 1), FencerPicture::enemy));
        auto path2 = std::move(m_board.findShortestPath(start_p2, Point(2, 2), FencerPicture::enemy));

        for (auto enemy_soldier : m_enemy_soldiers)
        {

            if (enemy_soldier->get_point().is_equal(start_p1))
            {
                enemy_soldier->set_path(path1);
                enemy_soldier->to_move();
            }
            else if (enemy_soldier->get_point().is_equal(start_p2))
            {
                enemy_soldier->set_path(path2);
                enemy_soldier->to_move();
            }
        }
    }
    for (auto employee : m_employees)
    {
        employee->to_work(m_resources);
        employee->gather_energy(m_resources);
    }

    if (day % 2 == 0)
    {
        soldier_hit_day(m_soldiers, m_enemy_soldiers);
        soldier_hit_day(m_enemy_soldiers, m_soldiers);
    }
    else
    {
        soldier_hit_day(m_enemy_soldiers, m_soldiers);
        soldier_hit_day(m_soldiers, m_enemy_soldiers);
    }

    for (auto soldier : m_soldiers)
    {
        soldier->gather_energy(m_resources);

        if (soldier->get_path_length() > 0)
        {
            soldier->to_move();
        }
        soldier->add_in_board(m_board, FencerPicture::my);
    }
    for (auto enemy_soldier : m_enemy_soldiers)
    {
        enemy_soldier->gather_energy(m_enemy_resources);
        if (enemy_soldier->get_path_length() > 0)
        {
            enemy_soldier->to_move();
        }
        enemy_soldier->add_in_board(m_board, FencerPicture::enemy);
    }

    sell_resources_auto();
}
void MyGame::print_day_in_screen() const
{
    std::cout << "\t\tDay: " << day << '\n';
}

//
char Woodworker::count = 0;
char Stoneworker::count = 0;
char Foodworker::count = 0;
char Ironworker::count = 0;
char Swordworker::count = 0;
void MyGame::print_resources_in_screen() const
{
    m_resources.print_screen(Woodworker::count, Stoneworker::count, Foodworker::count, Ironworker::count, Swordworker::count);
}

void MyGame::print_board_in_screen() const
{
    m_board.print();
}
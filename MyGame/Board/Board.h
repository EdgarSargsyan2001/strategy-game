#ifndef BOARD
#define BOARD
#include <algorithm> // std::reverse
#include <iostream>
#include <vector>
#include <queue>
#include "Square.h"
#include "Point.h"
class Board
{
public:
    static const int height = 10;
    static const int weight = 10;

public:
    Board()
    {
        for (int i = 0; i < height; ++i)
        {
            std::vector<Square> v;
            for (int j = 0; j < weight; ++j)
            {
                if (i < 5 && (j > 3 && j < 7))
                {
                    v.push_back(Square('[', ']'));
                }
                else
                {
                    v.push_back(Square());
                }
            }
            m_map.push_back(v);
        }
    }
    char get_figure(Point p)
    {
        short x = p.get_x();
        short y = p.get_y();

        if ((x >= 0 && x < height) && (y >= 0 && y < weight))
        {
            return m_map[x][y].get_figure();
        }
        return '\0';
    }
    void clean_board()
    {
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < weight; ++j)
            {
                if (m_map[i][j].is_figure_soldiar())
                {
                    m_map[i][j].clean_square();
                }
            }
        }
    }

    short get_count(Point p)
    {
        short x = p.get_x();
        short y = p.get_y();

        if ((x >= 0 && x < height) && (y >= 0 && y < weight))
        {
            return m_map[x][y].get_count();
        }
        return -1;
    }
    bool set_figure(Point p, char figure)
    {
        short x = p.get_x();
        short y = p.get_y();

        if ((x >= 0 && x < height) && (y >= 0 && y < weight))
        {
            if (!m_map[x][y].is_same_figure(figure))
            {
                m_map[x][y].set_figure(figure);
            }
            m_map[x][y].inc_count();
            return true;
        }
        return false;
    }
    std::vector<Point> findShortestPath(Point start, Point end, char figure)
    {
        int startX = start.get_x();
        int startY = start.get_y();
        if (startX < 0 || startX >= height || startY < 0 || startY >= weight)
        {
            throw std::out_of_range("Invalid start point.");
        }
        bool visited[height][weight] = {false};
        Point prev[height][weight];

        std::queue<Point> q;
        q.push(Point(startX, startY));
        visited[startX][startY] = true;

        std::vector<Point> path;

        while (!q.empty())
        {
            int x = q.front().get_x();
            int y = q.front().get_y();
            q.pop();

            if (x == end.get_x() && y == end.get_y())
            {
                while (x != -1 && y != -1)
                {
                    path.emplace_back(x, y);
                    int px = prev[x][y].get_x();
                    int py = prev[x][y].get_y();
                    x = px;
                    y = py;
                }
            }

            // Explore the neighboring cells (up, down, left, right)
            const int dx[] = {-1, 1, 0, 0, 1, -1, 1, -1};
            const int dy[] = {0, 0, -1, 1, 1, -1, -1, 1};

            for (int k = 0; k < 8; ++k)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                // Check if the next position is within the matrix boundaries and not visited
                if (nx >= 0 && nx < height && ny >= 0 && ny < weight && !visited[nx][ny] && (m_map[nx][ny].is_same_figure(':') || m_map[nx][ny].is_same_figure(figure)))
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    prev[nx][ny] = {x, y};
                }
            }
        }

        // path.pop_back();
        // std::reverse(path.begin(), path.end());
        return std::move(path);
    }

    void print() const
    {
        std::cout << "\n   ";
        for (int k = 0; k < weight; ++k)
        {
            std::cout << k << ((k < 10) ? "  " : " ");
        }
        std::cout << '\n';
        for (int i = 0; i < height; ++i)
        {
            std::cout << i << ((i < 10) ? "  " : " ");
            for (int j = 0; j < weight; ++j)
            {
                m_map[i][j].print(0);
                std::cout << " ";
            }
            std::cout << "\n";
        }
    }

private:
    std::vector<std::vector<Square>> m_map;
};

#endif
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <cstdlib>
#include<map>
#include<ctime>

using namespace std;


class Minesweeper
{
public:

    //assuming grid is from 1 - 9
    Minesweeper(int n) : size(n)
    {
        grid.resize(n, vector<bool>(n, true));
    }

    void constructMineSweeper()
    {
        srand(time(NULL));
        //generate numbers from 1 - 100
        int min = 0;
        int max = size - 1;
        int randomNo = rand() % 3 + 1;        
        while (randomNo > 0)
        {
            int randX = rand() % (max - min + 1) + min;
            int randY = rand() % (max - min + 1) + min;
            if (grid[randX][randY])
            {
                grid[randX][randY] = false;
            }
            --randomNo;
        }
    }

    void printMineSweeper()
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                cout << grid[i][j] << "    ";
            }
            cout << endl;
        }
    }


    bool isMine(int x, int y)
    {
        return grid[x][y];
    }

    int surroundingMines(int x, int y)
    {
        int count = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if ((i == 0 && j == 0) || x-i < 0 || x+i >= grid.size() || y-i < 0 || y+i >= grid[x].size() )
                {
                    continue;
                }
                try
                {
                    if (grid[x + i][y + j] == false)
                        count++;
                }
                catch (std::out_of_range e)
                {
                    cout << "ignore as it is expected when it goes below 0 or over the size";
                    continue;
                }
            }
        }
        return count;
    }



private:
    vector<vector<bool>> grid;
    int size;
};
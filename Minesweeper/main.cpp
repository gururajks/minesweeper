#include "pch.h"
#include<iostream>
#include "Minesweeper.h"
using namespace std;


int main()
{

    Minesweeper mn(3);
    mn.constructMineSweeper();
    mn.printMineSweeper();
    if (!mn.isMine(1, 2))
        cout << mn.surroundingMines(1, 2);

}


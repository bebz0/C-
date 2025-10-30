#include <iostream>
using namespace std;
#include "task10_1.cpp"
struct Cell
{
    int num;
    char letter;
};

bool ValidateCell(const Cell &c)
{
    return (c.letter >= 'a' && c.letter <= 'h') && (c.num >= 1 && c.num <= 8);
}

void InputCell(Cell &c)
{
    cout << "Enter cell num and cell letter by space: ";
    cin >> c.num >> c.letter;
}

void OutputCell(Cell &c)
{
    if (!ValidateCell(c))
    {
        cout << "Invalid input";
    }
    else
        cout << "The cell: " << c.num << c.letter << endl;
}

bool CanQueenMove(const Cell &from_cell, const Cell &to_cell)
{
    if (!ValidateCell(from_cell) || !ValidateCell(to_cell))
        return false;

    if (from_cell.letter == to_cell.letter || from_cell.num == to_cell.num)
        return true;

    // diagonale
    int dx = abs(from_cell.letter - to_cell.letter);
    int dy = abs(from_cell.num - to_cell.num);
    return dx == dy;
}

int main()
{
    Cell start_cell, end_cell;
    InputCell(start_cell);
    InputCell(end_cell);

    if (CanQueenMove(start_cell, end_cell))
        cout << "The queen can move from " << start_cell.letter << start_cell.num << " to " << end_cell.letter << end_cell.num << "\n";
    else
        cout << "The queen can't move from " << start_cell.letter << start_cell.num << " to " << end_cell.letter << end_cell.num << "\n";

    return 0;
}
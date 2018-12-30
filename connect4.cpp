#include <iostream>

class board
{
  public:
    int position[7][6] = {0};
};

void drop_stone(board *board, int column, int colour)
{
    int i = 6;
    while (i != 0)
    {
        if (board->position[column - 1][i - 1] != 0)
        {
            break;
        }
        i--;
    }
    board->position[column - 1][i] = colour;
}

void display(board *board)
{
    for (int i = 5; i != -1; i--)
    {
        for (int j = 0; j != 7; j++)
        {
            std::cout << board->position[j][i] << " ";
        }
        std::cout << std::endl;
    }
}

int check_if_win(board *board)
{
    int what_to_look_for = 1;
    int counter = 0;
    //check horizontally
    for (int row = 0; row != 6; row++)
    {
        counter = 0;
        for (int i = 0; i != 7; i++)
        {
            if (board->position[i][row] == 0){
                counter = 0;
                continue;
            }
            else if (what_to_look_for == board->position[i][row])
            {
                counter++;
                if (counter == 4){
                    return what_to_look_for;
                }
            }
            else
            {
                counter = 1;
                what_to_look_for = board->position[i][row];
            }
        }
    }
    //check vertically
    for (int column = 0; column != 7; column++)
    {
        counter = 0;
        for (int i = 0; i != 6; i++)
        {
            if (board->position[column][i] == 0){
                break;
            }
            else if (what_to_look_for == board->position[column][i])
            {
                counter++;
                if (counter == 4)
                    return what_to_look_for;
            }
            else
            {
                counter = 1;
                what_to_look_for = board->position[column][i];
            }
        }
    }
    //check diagonally

    return 0;
}

int main(int argc, char const *argv[])
{
    board b1;
    drop_stone(&b1, 1, 2);
    display(&b1);
    std::cout << std::endl;
    drop_stone(&b1, 2, 2);
    drop_stone(&b1, 3, 2);
    drop_stone(&b1, 4, 2);
    display(&b1);
    std::cout << check_if_win(&b1) << std::endl;
    return 0;
}

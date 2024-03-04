#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

void to_camel_case(const char *text, char *camel) {
    int i = 0;
    int j = 0;
    while (text[i] != '\0') {
        if (text[i] == '-' || text[i] == '_') {
            i++;
            if (islower(text[i])) {
                camel[j] = text[i] - 32;
            } else {
                camel[j] = text[i];
            }
        } else {
            camel[j] = text[i];
        }
        i++;
        j++;
    }
    camel[j] = '\0';
    printf("%s\n", camel);
}


bool check_if_king_is_in_line (const char line[8] , int column)
{
   
}


bool check_if_king_is_in_column(const char chessboard[8][8], int column)
{
    for (int i = 0; i < 8; i++)
    {
        if (chessboard[i][column] == 'K')
        {
            return true;
        }
    }
    return false;
}


check_if_king_is_in_diagonal(const char chessboard[8][8], int i, int j)
{
    int k = i;
    int l = j;
    while (k < 8 && l < 8)
    {
        if (chessboard[k][l] == 'K')
        {
            return true;
        }
        k++;
        l++;
    }
    k = i;
    l = j;
    while (k >= 0 && l >= 0)
    {
        if (chessboard[k][l] == 'K')
        {
            return true;
        }
        k--;
        l--;
    }
    k = i;
    l = j;
    while (k >= 0 && l < 8)
    {
        if (chessboard[k][l] == 'K')
        {
            return true;
        }
        k--;
        l++;
    }
    k = i;
    l = j;
    while (k < 8 && l >= 0)
    {
        if (chessboard[k][l] == 'K')
        {
            return true;
        }
        k++;
        l--;
    }
    return false;
}

bool check_l_for_king (const char chessboard[8][8], int i, int j)
{
    if (i-2>=0 && j-1>=0 && chessboard[i-2][j-1]=='K')
    {
        return true;
    }
    if (i-2>=0 && j+1<8 && chessboard[i-2][j+1]=='K')
    {
        return true;
    }
    if (i+2<8 && j-1>=0 && chessboard[i+2][j-1]=='K')
    {
        return true;
    }
    if (i+2<8 && j+1<8 && chessboard[i+2][j+1]=='K')
    {
        return true;
    }
    if (i-1>=0 && j-2>=0 && chessboard[i-1][j-2]=='K')
    {
        return true;
    }
    if (i-1>=0 && j+2<8 && chessboard[i-1][j+2]=='K')
    {
        return true;
    }
    if (i+1<8 && j-2>=0 && chessboard[i+1][j-2]=='K')
    {
        return true;
    }
    if (i+1<8 && j+2<8 && chessboard[i+1][j+2]=='K')
    {
        return true;
    }
    return false;
}

bool king_is_in_check (const char chessboard[8][8])
{
    bool king_is_in_check = false;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chessboard[i][j]=='R')
            {
                king_is_in_check |= check_if_king_is_in_line(chessboard[i]) || check_if_king_is_in_column(chessboard, j);
            }
            else if (chessboard[i][j]=='B')
            {
                king_is_in_check |= check_if_king_is_in_diagonal(chessboard, i, j);
            }
            else if (chessboard[i][j]=='Q')
            {
                king_is_in_check |= check_if_king_is_in_line(chessboard[i]) || check_if_king_is_in_column(chessboard, j) || check_if_king_is_in_diagonal(chessboard, i, j);
            }
            else if (chessboard[i][j]=='N')
            {
                king_is_in_check |= check_l_for_king(chessboard, i, j);
            }
            else if (chessboard[i][j]=='P')
            {
                if (i-1>=0 && j-1>=0 && chessboard[i-1][j-1]=='K')
                {
                    king_is_in_check = true;
                }
                if (i-1>=0 && j+1<8 && chessboard[i-1][j+1]=='K')
                {
                    king_is_in_check = true;
                }
            }
        }
    }
    return king_is_in_check;
}
void test_king_is_in_check() {


}
int main(int argc, char *argv[]) {
    char camel[100];
    to_camel_case("the-stealth-warrior", camel);
    to_camel_case("The_Stealth_Warrior", camel);
    char chessboard[8][8] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', 'K', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', 'R', ' '}
    };
    assert(king_is_in_check(chessboard) == false);
    return 0;
}

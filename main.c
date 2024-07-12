#include <stdio.h>
#include <stdbool.h>    // Integer could have been used for flags, but that may confuse those reading this code.

// Define the tic-tac-toe board as a 3x3 array. Here, '_' symbolizes an open tile.
char board[3][3] = { {'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'} };

char player_token = 'X';

// Subroutine for illustrating the tic-tac-toe board
void draw_board() {
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

bool insert(int x, int y) {
    scanf("%d",&x);
    scanf("%d", &y);

    printf("\n");

    if (board[x][y] == '_') {
        board[x][y] = player_token;
        return true;
    } else {
        printf("INVALID MOVE!\n");
        return false;
    }
}

// TODO: Add a function to check for a win.

int main() {
    int _x, _y;   //coordinates to place tiles
    bool move;
    int counter = 0;
    while(counter < 9) {
        draw_board();
        move = insert(_x, _y);
        // add a function to check for win here.
        if(move) counter++;
    }
    printf("\nGAME!\n-----\n");
    draw_board();
    return 0;
}
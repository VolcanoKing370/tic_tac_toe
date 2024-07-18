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

// This function allows player to make a VALID move
bool insert(int x, int y) {
    printf("%c's turn!\n", player_token);
    printf("Enter vertical coord: ");
    scanf("%d", &x);
    printf("Enter horizontal coord: ");
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
bool check_win(char brd[3][3], char token) {
    // Horizontal top row
    if(brd[0][0] == brd[0][1] && brd[0][1] == brd[0][2] && brd[0][0] == token) {
        printf("%c WINS!\n", player_token);
        return true;
    }
    // Horitontal middle row
    if(brd[1][0] == brd[1][1] && brd[1][1] == brd[1][2] && brd[1][0] == token) {
        printf("%c WINS!\n", player_token);
        return true;
    }
    // Horitontal bottom row
    if(brd[2][0] == brd[2][1] && brd[2][1] == brd[2][2] && brd[2][0] == token) {
        printf("%c WINS!\n", player_token);
        return true;
    }
    // Vertical left column
    if(brd[0][0] == brd[1][0] && brd[1][0] == brd[2][0] && brd[0][0] == token) {
        printf("%c WINS!\n", player_token);
        return true;
    }
    // Vertical middle column
    if(brd[0][1] == brd[1][1] && brd[1][1] == brd[2][1] && brd[0][1] == token) {
        printf("%c WINS!\n", player_token);
        return true;
    }
    // Vertical right column
    if(brd[0][2] == brd[1][2] && brd[1][2] == brd[2][2] && brd[0][2] == token) {
        printf("%c WINS!\n", player_token);
        return true;
    }
    // Diagonal from top-left to bottom-right
    if(brd[0][0] == brd[1][1] && brd[1][1] == brd[2][2] && brd[0][0] == token) {
        printf("%c WINS!\n", player_token);
        return true;
    }
    // Diagonal from top-right to bottom-left
    if(brd[0][2] == brd[1][1] && brd[1][1] == brd[2][0] && brd[0][2] == token) {
        printf("%c WINS!\n", player_token);
        return true;
    }
    return false;
}

int main() {
    int _x, _y;   //coordinates to place tiles
    bool move;
    int counter = 0;
    while(counter < 9) {
        draw_board();
        move = insert(_x, _y);
        if(move) counter++;
        // add a function to check for win here.
        if(check_win(board, player_token)) {
            break;
        }
        if(move) {
            // switch player_token character after turn
            player_token = (player_token == 'X') ? 'O' : 'X';
        }
        printf("\ncounter: %d\n", counter);
        
    }
    printf("\nGAME!\n-----\n");
    draw_board();
    return 0;
}
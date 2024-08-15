#include <iostream>
using namespace std;

char Board[9] = {' ',' ',' ', 
                  ' ',' ',' ', 
                  ' ',' ',' ' };

void printBoard() {
    cout << Board[0] << '|' << Board[1] <<  '|'  << Board[2] << '\n';
    cout << Board[3] << '|'  << Board[4] <<  '|'  << Board[5] << '\n';
    cout << Board[6] <<  '|'  << Board[7] <<  '|'  << Board[8] << '\n';
    
}

bool checkWin(char curPlayer) {
    if ((Board[0] == curPlayer && Board[1] == curPlayer && Board[2] == curPlayer) //Across Top
        || (Board[3] == curPlayer && Board[4] == curPlayer && Board[5] == curPlayer) //Across Middle
        || (Board[6] == curPlayer && Board[7] == curPlayer && Board[8] == curPlayer) // Across Bottom
        || (Board[0] == curPlayer && Board[4] == curPlayer && Board[7] == curPlayer) //Down left
        || (Board[1] == curPlayer && Board[5] == curPlayer && Board[8] == curPlayer) //Down Middle
        || (Board[2] == curPlayer && Board[5] == curPlayer && Board[8] == curPlayer) //Down Right
        || (Board[0] == curPlayer && Board[4] == curPlayer && Board[8] == curPlayer) //Diagonal top left to bottom right
        || (Board[2] == curPlayer && Board[4] == curPlayer && Board[6] == curPlayer) //Diagonal top right to bottom left
      ) {
        return true;
       }
    else { 
        return false;
    }
}

bool checkFull(){
    if (Board[0] == ' ' ||
        Board[1] == ' ' ||
        Board[2] == ' ' ||
        Board[3] == ' ' ||
        Board[4] == ' ' ||
        Board[5] == ' ' ||
        Board[6] == ' ' ||
        Board[7] == ' ' ||
        Board[8] == ' ' ) {
            return false;
        }
    else { 
        return true; }
}

void reset() {
    for (int i = 0; i < 9; i++) {
        Board[i] = ' ';
    }
}

void move(char CurPlayer) {
    cout << "Enter Position (space 1-9, 1 in top left, 9 bottom right): \n";
    int pos;
    cin >> pos;
    while (Board[(pos - 1)] != ' ' || pos < 1 || pos > 9) {
        cout << "Invalid move try again! \n";
        cin >> pos;
    }
    pos -= 1;
    Board[pos] = CurPlayer;
}

int main() {
    bool PlayGame = true;
    char PlayerOne = 'X';
    char curPlayer = PlayerOne;
    while (PlayGame) {
        cout << "Player " << curPlayer << " Turn\n";
        cout << "Current Board \n";
        printBoard();
        move(curPlayer);
        printBoard();
        if (checkWin(curPlayer)) {
            cout << "Player " << curPlayer << " Wins! \n";
            PlayGame = false;
        }
        if (checkFull()) {
            char again;
            cout << "Board is Full! Nobody wins \n";
            cout << "Playagain? (y or n) \n";
            cin >> again;
            while (again != 'y' && again != 'n') {
                cout << "Wrong input try again! \n";
                cin >> again;
            }
            if (again == 'y') {
                reset();
            }
            else {
                PlayGame = false;
            }
        }
        if (curPlayer == 'X') { curPlayer = 'O'; } else { curPlayer = 'X'; } 
    }
    return 0;
}





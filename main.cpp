#include <iostream> 
#include <algorithm> 

using namespace std;   
struct Move 
{ 
    int row, col;
}; 

/* Prints current board state. Example output:{ x _ o }
                                            { _ o o }
                                            { _ _ x } 
*/ 
int printBoard(char board[3][3]){ 
    for(int i = 0; i < 3; i++){
        cout << "{" << " "<< board[i][0]<< " " << board[i][1] << " " << board[i][2] << " " << "}" << endl;  
    } 
    return 0;
}  
bool movesLeft(char board[3][3]){  
    for(int i = 0; i < 3; i++){ 
        for(int j = 0; j < 3; j++){ 
            if(board[i][j] == '_'){ 
                return true;
            }

        }
    } 
    return false; 
} 
int evaluateBoard(char board[3][3]){  
    //Check for player or computer victory on each row. 
    for(int i = 0; i < 3; i++){  
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){ 
                if(board[i][0] == 'x') 
                    return 10; 
                else if(board[i][0] == 'o') 
                    return -10; 
            }     
        }  
    //Check for player or computer victory on each column.
    for(int i = 0; i < 3; i++){  
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){ 
                if(board[0][i] == 'x') 
                    return 10; 
                else if(board[0][i] == 'o') 
                    return -10; 
            }
                
        }  
    //Check for player or computer victory on each diagonal. 
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){ 
            if(board[0][0] == 'x') 
                return 10; 
            else if(board[0][0] == 'o')
                return -10;  
        }
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){ 
            if(board[0][2] == 'x') 
                return 10; 
            else if(board[0][2] == 'o')
                return -10;  
        } 
    //Return 0 in case of tie.  
    return 0;
} 


    
int minimax(char board[3][3], int depth, bool isMaximizing) { 
    int bestScore; 
     int score = evaluateBoard(board); 
     if(score == 10) 
        return score; 
    if(score == -10) 
        return score; 
    if(movesLeft(board) == false) 
        return 0; 
    
    if (isMaximizing) {
         bestScore = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = 'x';
                    int score = minimax(board, depth + 1, false);
                    board[i][j] = '_';
                    bestScore = max(bestScore, score);
                }
            }
        }
        return bestScore - depth;
    } else {
         bestScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = 'o';
                    int score = minimax(board, depth + 1, true); 
                    board[i][j] = '_';
                    bestScore = min(bestScore, score); 
                }
            }
        }
        return bestScore + depth;
    }
}

void nextMinimaxMove(char board[3][3]) {
    int bestScore = -1000;
    int bestRow = -1;
    int bestColumn = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '_') {
                board[i][j] = 'x';  
                int score = minimax(board, 0, false);
                board[i][j] = '_';

                if (score > bestScore) {
                    bestRow = i; 
                    bestColumn = j; 
                    bestScore = score;
                }
            }
        }
    }
    board[bestRow][bestColumn] = 'x'; 
    printBoard(board);
}

//Request human player to input their next move's coordinates and calls printBoard() to print the updated board. 
void nextPlayerMove(char board[3][3]){ 
    int row;
    int column; 
    cout << "Please type in your next move: "; 
    cin >> row >> column;   
    board[row][column] = 'o'; 
    printBoard(board);    
}
int main(){   
    char board[3][3] =
    { 
        { 'o', '_', '_'},
        { 'o', '_', '_'},
        { '_', '_', '_'}
    };     
    nextMinimaxMove(board);

    return 0;
}


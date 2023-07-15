#include <iostream> 
#include <vector>  
#include <cstdlib> 
#include <time.h>

using namespace std;   
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
    //Return 0 if no one has won yet. 
    return 0;
} 

void nextComputerMove(char board[3][3]){    
    srand(time(0));
    bool isMoveValid = false;
    char workBoard[3][3];   
    for(int i = 0; i < 3; i++){ 
            for(int j = 0; j < 3; j++){ 
                workBoard[i][j] = board[i][j];
            }
        }
    int row; 
    int column; 
    for(int i = 0; i < 3; i++){ 
        for(int j = 0; j < 3; j++){ 
            if(workBoard[i][j] == '_'){ 
                workBoard[i][j] = 'o'; 
                if(evaluateBoard(workBoard) == -10){ 
                    row = i; 
                    column = j;  
                    goto end;
                } 
                 for(int i = 0; i < 3; i++){ 
                    for(int j = 0; j < 3; j++){ 
                workBoard[i][j] = board[i][j];
            }
        }
            }
        }
    } 
     for(int i = 0; i < 3; i++){ 
        for(int j = 0; j < 3; j++){ 
            if(workBoard[i][j] == '_'){ 
                workBoard[i][j] = 'x'; 
                if(evaluateBoard(workBoard) == 10){ 
                    row = i; 
                    column = j;  
                    goto end; 
                } 
                 for(int i = 0; i < 3; i++){ 
                    for(int j = 0; j < 3; j++){ 
                workBoard[i][j] = board[i][j];
            }
        }
            }
        }
    }  
     
    while( isMoveValid == false){ 
        row = (rand() % (2 - 0 + 1)) + 0; 
        column = (rand() % (2 - 0 + 1)) + 0;
        if(board[row][column] == '_') 
            isMoveValid = true; 
    } 
    if(isMoveValid == true) 
        goto end; 
            
end: 
board[row][column] = 'o'; 
cout << "Computer move: " << endl; 
printBoard(board);
}


//Request human player to input their next move's coordinates and calls printBoard() to print the updated board. 
void nextPlayerMove(char board[3][3]){ 
    int row;
    int column; 
    cout << "Please type in your next move: "; 
    cin >> row >> column;   
    board[row][column] = 'x'; 
    printBoard(board);    
}
int main(){  
    int i = 0;
    char b[3][3] =
    {
        { '_', '_', '_'},
        { '_', '_', '_'},
        { '_', '_', '_'}
    };   
     while(i <= 2){ 
        nextComputerMove(b);
     }
    
    return 0;
}


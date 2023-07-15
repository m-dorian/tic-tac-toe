#include <iostream> 
#include <string> 
#include <vector> 

using namespace std;  

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
    //Return 0 if no one has won. 
    return 0;
} 

 /* vector<int> nextMove(char board[3][3]){ 
    char originalBoard[3][3];
        for(int i = 0; i < 3; i++){ 
            for(int j = 0; j < 3; j++){ 
                originalBoard[i][j] = board[i][j];
            }
        }
    vector<int> winningMoves;
    for(int i = 0; i < 3; i++){ 
        for( int j = 0; j < 3; j++){ 
            if(board[i][j] == '_'){ 
                board[i][j] = 'x'; 
                if(evaluateBoard(board) == 10){
                    winningMoves.push_back(i); 
                    winningMoves.push_back(j); 
                     
                }
                board[i][j] = 'o'; 
                if(evaluateBoard(board) == -10){
                    winningMoves.push_back(i); 
                    winningMoves.push_back(j); 
                    
                 }
} 
             for(int i = 0; i < 3; i++){ 
            for(int j = 0; j < 3; j++){ 
                board[i][j] = originalBoard[i][j];
            }
        }
} 
} 
    return winningMoves;
}  
*/  

/* Print current board state. Example output:{ x _ o }
                                            { _ o o }
                                            { _ _ x } 
*/ 
int printBoard(char board[3][3]){ 
    for(int i = 0; i < 3; i++){
        cout << "{" << " "<< board[i][0]<< " " << board[i][1] << " " << board[i][2] << " " << "}" << endl;  
    } 
    return 0;
}
int main(){ 
    char board[3][3] =
    {
        { 'x', '_', 'o'},
        { '_', 'o', 'o'},
        { '_', '_', 'x'}
    };   
    printBoard(board);
    
    return 0;
}


// 2:06
#include <bits/stdc++.h>
using namespace std;

class TictactoeManager{
    private:
        int board[3][3];
        int playerTurn;
        string winner;
        
        
        void playplayerTurn(){
            printBoard();
            int x,y;
            cout<<"Player "<<playerTurn<<" play, by typing (x,y)"<<endl;
            cin>>x>>y;
            board[x][y]=playerTurn;
            if(checkWon(playerTurn)){
                winner="PLAYER_"+to_string(playerTurn);
                endGame();
            }
            else{
                playerTurn = (playerTurn == 1)?2:1;
                playplayerTurn();
            }            
                
        }
        bool checkWon(int playerTurn){
            //check rows
            for(int i=0;i<3;i++){
                bool sameRow=true;
                for(int j=0;j<3;j++)
                    if(board[i][j] != playerTurn)
                        sameRow=false;
                
                if(sameRow)
                    return true;
            }
            
            //check colums
            for(int j=0;j<3;j++){
                bool sameCol=true;
                for(int i=0;i<3;i++)
                    if(board[i][j] != playerTurn)
                        sameCol=false;
                
                if(sameCol)
                    return true;
            }
            
            //check diag1
            bool diag1=true;
            for(int i=0;i<3;i++)
                if(board[i][i] != playerTurn)
                    diag1=false;
            if(diag1)
                return true;

            //check diag2
            bool diag2=true;
            for(int i=2;i>=0;i--)
                if(board[i][2-i] != playerTurn)
                    diag2=false;
            if(diag2)
                return true;
            return false;    
        }
        
        void printBoard(){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++)
                    cout<<board[i][j]<<" ";
                cout<<endl;    
            }
        }
    public:
        TictactoeManager(){
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    board[i][j]=0;
            playerTurn=1;
            winner="NONE";
        }
        void startGame(){
            playplayerTurn();
        }
        
        void endGame(){
            cout<<"GAME ENDED : winner = "<<winner<<endl;
        }
        
        
};




int main(){
    TictactoeManager    *tm = new TictactoeManager();
    tm->startGame();
    
    return 0;
}



/* GAMEPLAY
0 0 0 
0 0 0 
0 0 0 
Player 1 play, by typing (x,y)
0 0
1 0 0 
0 0 0 
0 0 0 
Player 2 play, by typing (x,y)
2 0
1 0 0 
0 0 0 
2 0 0 
Player 1 play, by typing (x,y)
1 1
1 0 0 
0 1 0 
2 0 0 
Player 2 play, by typing (x,y)
1 2
1 0 0 
0 1 2 
2 0 0 
Player 1 play, by typing (x,y)
2 2
GAME ENDED : winner = PLAYER_1


*/

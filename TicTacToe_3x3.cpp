//Machine code a 3*3 Tic Tac Toe
// 1)  Game start with 2 Players 
// 2)  If any player quits match other player wins
// 3)  At end of game - > player 'x' won the match
// 4)  each player can choose their own char like 'X','O','N'....  
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Player{
public:
    string name;
    char symbol;
};

class Board{
private:
    vector< vector<int> > matrix;
public:
    Board(){
        matrix.resize(3,vector<int> (3,-1));
    }

    bool checkplayerWonInBoard(int playerId){
        //check rows
        for(int i=0;i<matrix.size();i++){
            bool allColGreen=true;
            for(int j=0;j<matrix[0].size();j++)
                if(matrix[i][j] != playerId){
                    allColGreen=false;
                    break;
                }
            if(allColGreen) 
                return true;   
        }

        //check cols
        for(int j=0;j<matrix[0].size();j++){
            bool allRowGreen=true;
            for(int i=0;i<matrix.size();i++)
                if(matrix[i][j] != playerId){
                    allRowGreen=false;
                    break;
                }
            if(allRowGreen) 
                return true;   
        }

        //check diag1
        bool diag1True=true;
        for(int i=0;i<matrix.size();i++)
            if(matrix[i][i] != playerId){
                diag1True = false;
                break;
            }
        if(diag1True)
            return true;    


        //check diag2
        bool diag2True=true;
        for(int i=0;i<matrix.size();i++)
            if(matrix[i][matrix.size()-1-i] != playerId){
                diag2True = false;
                break;
            }
        if(diag2True)
            return true;    
        return false;
    }

    bool put(int x,int y,int playerId){
        // cout<<"Board put() : x="<<x<<" y="<<y<<" playerId="<<playerId<<endl;
        if(x<0 || x>=3 || y<0 || y>=3){
            cout<<"INVALID put , Game Broke"<<endl;
            return false;
        }
        else if(matrix[x][y] != -1){
            cout<<"put on marked cell"<<endl;
            return false;
        }

        matrix[x][y] = playerId;

        return true;
    }

    void print(const vector<Player> &players){
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                char symbol='.';

                if(matrix[i][j] != -1)
                    symbol = players[matrix[i][j]].symbol;
                cout<<symbol<<" ";
            }
            cout<<endl;
        }

    }
        
};

class Organizer{
private:
        vector<Player> players;
        Board b;

        void initPlayers(string player1, string player2, char symbolplayer1, char symbolplayer2){
            players.resize(2);
            players[0].name=player1;
            players[0].symbol=symbolplayer1;
            players[1].name=player2;
            players[1].symbol=symbolplayer2;

        }

        void endGame(int playerwon){
            cout<<"Congrats !! player "<<players[playerwon].name<<" wins"<<endl;
        }

        bool checkplayerWon(int playerId){
            return b.checkplayerWonInBoard(playerId);
        }

public:
        void startNewGame( string player1, string player2, char symbolplayer1, char symbolplayer2){
            initPlayers(player1,player2,symbolplayer1,symbolplayer2);
            nextTurn(0);

        }

        bool nextTurn(int playerId){
            b.print(players);
            cout<<"player "<<players[playerId].name<<" enter x and y"<<endl;
            int x,y;
            cin>>x>>y;
            // cout<<"Entered x="<<x<<" y="<<y<<endl;
            b.put(x,y,playerId);

            bool playerWon = checkplayerWon(playerId);

            if(playerWon){
                    endGame(playerId);
                    return false;
                }
            return nextTurn((playerId+1)%2);    
        }

};

int main(){
    Organizer o;
    o.startNewGame("gaurav","anand",'G','A');


    return 0;


}

/* GAME PLAY

╭─gauravanand@Gauravs-MacBook-Pro-4  ~/Desktop/Code ‹node-›  ‹›
╰─$ ./a.out
. . .
. . .
. . .
player gaurav enter x and y
1 1
. . .
. G .
. . .
player anand enter x and y
2 1
. . .
. G .
. A .
player gaurav enter x and y
0 0
G . .
. G .
. A .
player anand enter x and y
2 0
G . .
. G .
A A .
player gaurav enter x and y
2 2
Congrats !! player gaurav wins

*/

//Design Snakes and ladder Game 1:47am - 
// Rules
// 1) Game is played by n players, mentioned at starting 0,1,.... n-1
// 2) Each player play in turns , starting from 0 -> n-1 then repeats
// 3) number of snakes/ladders, snakes/ladders start and end is give before game start
// 4) Board is numbered from 1-100 , 0=blocked position
// 5) Game Halts if any player reachs 100, that player wins game
// 6) If player occupied a cell , all player in that cell dies and reached to 0 again
// 7) player cames from 0-1 on getting 1 only on dice

#include <bits/stdc++.h>	
using namespace std;
class Dice{
  private:
    int  counter;
    vector<int> outcomes={2,1};

  public:
  Dice(){
      counter=0;
  }
    int roll(){
        if(counter >=outcomes.size())
            counter=0;
        return outcomes[counter++];
    }
};
class SnakeAndLadders{
    private:
        unordered_map<int,int> snakesPortals;
        unordered_map<int,int> laddersPortals;
        vector<int> playersPosition;
        int currentTurnPlayer;
        void updateCurrentTurnPlayer(){
            currentTurnPlayer++;
            if(currentTurnPlayer>=playersPosition.size())
                currentTurnPlayer=0;
        }
        Dice d;
        void endGame(){
            cout<<"GAME END : Player="<<currentTurnPlayer<<" won"<<endl;
        }
        
        void printPlayers(){
            for(int i=0;i<playersPosition.size();i++)
                cout<<"Player="<<i<<" position="<<playersPosition[i]<<endl;
            cout<<"------------------------------"<<endl;    
        }
        
        void playTurn(){
            printPlayers();
            cout<<"Player="<<currentTurnPlayer<<" is playing"<<endl;
            int diceOutput = d.roll();
            cout<<" dice roll = "<<diceOutput<<endl;
            
            if(playersPosition[currentTurnPlayer] ==0){
                if(diceOutput == 1)
                    playersPosition[currentTurnPlayer] =1;
                updateCurrentTurnPlayer();
                playTurn(); 
                return ;
            }
            if(playersPosition[currentTurnPlayer] + diceOutput >100){
                updateCurrentTurnPlayer();
                playTurn();
                return ;
            }
            
            //valid move move goti
            playersPosition[currentTurnPlayer] += diceOutput;
            if(playersPosition[currentTurnPlayer] == 100){
                endGame();
                return ;
            }
            //check snakes
            if(snakesPortals.find(playersPosition[currentTurnPlayer]) != snakesPortals.end()){
                int snakeTail = snakesPortals[playersPosition[currentTurnPlayer]];
                playersPosition[currentTurnPlayer] = snakeTail;
            
            //check ladders
            if(laddersPortals.find(playersPosition[currentTurnPlayer]) != laddersPortals.end()){
                int ladderEnd = snakesPortals[playersPosition[currentTurnPlayer]];
                playersPosition[currentTurnPlayer] = ladderEnd;
            }
            
            //dusri player ko katna
            for(int i=0;i<playersPosition.size();i++)
                if(i != currentTurnPlayer && playersPosition[i] == playersPosition[currentTurnPlayer]){
                    playersPosition[i] =0;
                }
            updateCurrentTurnPlayer();
            playTurn();    
        }
    public:
        SnakeAndLadders(vector<pair<int,int>> snakes, vector<pair<int,int>> ladders, int numPlayers){
            for(int i=0;i<snakes.size();i++)
                snakesPortals[snakes[i].first] = snakes[i].second;
            
            for(int i=0;i<ladders.size();i++)
                laddersPortals[ladders[i].first] = ladders[i].second;
            playersPosition.resize(numPlayers);  
            currentTurnPlayer=0;
        }
        
        void playGame(){
            cout<<"Starting Game"<<endl;
            playTurn();
        }
};
int main(){
    vector<pair<int,int>> snakes;
    vector<pair<int,int>> ladders;
    int numPlayers=2;
    
    SnakeAndLadders game(snakes,ladders,numPlayers);
    game.playGame();
    
    
	return 0;
}

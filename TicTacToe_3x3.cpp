//Design Tic tac toe

// Features
// 1) Game is played between 2 players player1,player2
// 2) player1 plays first then each player move 1by1
// 3) user cannot play invalid move
// 4) Game halts if 
// 		1) player1/player2 won => show who won
// 		2) draw state => show draw
// 5) Show board after each move [Optional]

#include <bits/stdc++.h>	
using namespace std;
class TicTacToe{
private:
	vector< vector<int> > grid;

	void gameEnd(){
		cout<<"========= GAME ENDED ========="<<endl;
	}
	bool validMark(int x,int y){
		if(x<0 || x>=3)
			return false;
		if(y<0 || y>=3)
			return false;
		if(grid[x][y] !=0)
			return false;
		return true;
	}
	bool gameWon(int player,int x,int y){
		bool won=true;
		//check row x
		for(int j=0;j<3;j++)
			if(grid[x][j] != player){
				won=false;
				break;
			}
		if(won)
			return true;

		//check col y
		won =true;
		for(int i=0;i<3;i++)
			if(grid[i][y] != player){
				won=false;
				break;
			}
		if(won)
			return true;

		//check diag1
		won =true;
		for(int i=0;i<3;i++)
			if(grid[i][i] != player){
				won=false;
				break;
			}
		if(won)
			return true;

		//check diag2
		won =true;
		for(int i=0;i<3;i++)
			if(grid[i][2-i] != player){
				won=false;
				break;
			}
		if(won)
			return true;

		return false;		
	}
    bool gameDraw(){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(grid[i][j] == 0)
                    return false;
        return true;            
    }
	void playTurn(int player){
	    displayBoard();
		cout<<"player"<<player<<" enter x,y"<<endl;
		int x;
		int y;
		cin>>x>>y;

		if(!validMark(x,y)){
			cout<<"Error : Inavlid Move"<<endl;
			playTurn(player);
		}
		grid[x][y] = player;

		if(gameWon(player,x,y)){
			cout<<"Game Won : player"<<player<<endl;
			gameEnd();
		}
		else if(gameDraw()){
			cout<<"Game Draw:"<<endl;
			gameEnd();
		}
		else{
		    if(player == 1)
			    playTurn(2);
			else
			    playTurn(1);

		}
}
	void displayBoard(){
	    for(int i=0;i<3;i++){
	        for(int j=0;j<3;j++){
	            if(grid[i][j] == 0)
	                cout<<". ";
	            else
	                cout<<grid[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	}
public:
	void playNewGame(){
		grid.resize(3,vector<int> (3,0));
		playTurn(1);
	}	
	
};

int main(){
	TicTacToe t;

	t.playNewGame();


	return 0;
}

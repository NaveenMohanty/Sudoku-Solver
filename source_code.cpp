#include<iostream>
using namespace std;
void fillRow(int board[9][9],int missing[],int row){
    for(int i=0;i<9;i++){
        if(board[row][i]==0)
            continue;
        missing[(board[row][i])-1]++;
    }
}
void fillCol(int board[9][9],int missing[],int col){
    for(int i=0;i<9;i++){
        if(board[i][col]==0)
            continue;
        missing[(board[i][col])-1]++;
    }
}
void fillSmallSquare(int board[9][9],int missing[],int row,int col){
    int c=col-(col%3);
    int r=row-(row%3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[r+i][c+j]==0)
            continue;
        missing[(board[r+i][c+j])-1]++;
        }
    }
}
bool isRepeat(int missing[]){
    for(int i=0;i<9;i++){
        if(missing[i]>1)
            return false;
    }
    return true;
}
bool sudokuSolver(int board[9][9],int row,int col){
    if(row==9){
        return true;
    }
    if(board[row][col]!=0){
        if(col==8)
            return sudokuSolver(board,row+1,0);        
        else
            return sudokuSolver(board,row,col+1);
    }  
    int* missing=new int[9];
    for(int i=0;i<9;i++){
        missing[i]=0;
        }
    fillRow(board,missing,row);
    fillCol(board,missing,col);
    fillSmallSquare(board,missing,row,col);
    bool ans;
    if(isRepeat(missing)){
      return false;
    }
   else{
        
        for(int i=0;i<9;i++){
            if(missing[i]==0){
                board[row][col]=i+1;
                if(col==8){
                   if(!sudokuSolver(board,row+1,0)){
                       board[row][col]=0;
                       continue;
                   }
                    else
                        return true;
                }   
                else{
                   if(!sudokuSolver(board,row,col+1)){
                       board[row][col]=0;
                       continue;
                   }
                    else
                        return true;
                }
            }
        }
    }
    return false;
}
int main(){

  int n = 9; 
  int board[9][9];
  cout<<"\nEnter the Unsolved Sudoku";
  cout<<"\nIt should be in 9X9 Matrix format and must have space between each element.";
  cout<<"\nEnter '0' for blank space in Sudoku.\n";
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board,0,0)){
    cout<<"\nSolved Sudoku is:\n";
	for(int i = 0; i < n ;i++){
	    for(int j = 0; j < n; j++){
        	cout<<board[i][j]<<" ";
        }
        cout<<endl;		
  }
  }else{
	cout << "\nThis Sudoku in Unsolvable.\n";	
  }
  return 0;
}

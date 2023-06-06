class Solution {
public:
    bool valid(int row,int col,char c,vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            if(board[row][i]==c)return false;
            if(board[i][col]==c)return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)return false;
        }
        return true;
    }
    bool f(vector<vector<char>>&board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(valid(i,j,c,board)){
                            board[i][j]=c;
                            if(f(board)==true)return true;
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
};
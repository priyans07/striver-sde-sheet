class Solution {
public:
    bool possible(int row,int col,vector<string>&board,int n){
        int x=row;
        int y=col;
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
        row=x;
        col=y;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')return false;
            row--;
            col--;
        }
        row=x;
        col=y;
        while(row<n && col>=0){
            if(board[row][col]=='Q')return false;
            row++;
            col--;
        }
        return true;
        
    }
    void f(vector<vector<string>>&ans,vector<string>&board,int col, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(possible(row,col,board,n)){
                board[row][col]='Q';
                f(ans,board,col+1,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> pre(n);
        string s(n,'.');
        for(int i=0;i<n;i++)pre[i]=s;
        f(ans,pre,0,n);
        return ans;
    }
};
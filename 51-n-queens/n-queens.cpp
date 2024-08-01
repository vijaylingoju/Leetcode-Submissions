class Solution {
public:
    bool isValid(int row, int col, vector<string>&board, int n){
        //up
        for(int i = row-1; i >= 0; i--){
            if(board[i][col]=='Q')return false;
        }
        
        //left top to right bottom diagnol
        int i = row-1, j = col - 1;
        while(i>=0 and j>=0){
            if(board[i][j]=='Q')return false;
            i-=1;
            j-=1;
        }
        
        //right top to left bottom diagnal
        i = row - 1, j = col + 1;
        while(i>=0 and j<n){
            if(board[i][j]=='Q')return false;
            i-=1;
            j+=1;
        }
        return true;
    }
    void solve(int row,int n, vector<string>&board, vector<vector<string>>&ans){
        
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col = 0; col < n; col++){
            if(isValid(row,col,board,n)){
                board[row][col]='Q';
                solve(row+1,n,board,ans);
                board[row][col]='.';
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i = 0 ; i < n; i++){
            board[i] = s;
        }
        solve(0,n,board,ans);
        return ans;
    }
};
//348. Design Tic-Tac-Toe
//https://leetcode.com/problems/design-tic-tac-toe/
class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<int> rows;
    vector<int> cols;
    int diag;
    int antidiag;
    int size;
    TicTacToe(int n) {
        rows=vector<int>(n,0);
        cols=vector<int>(n,0);
        diag=0;
        antidiag=0;
        size=n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int code=(player-1)*size +1;
        rows[row]+=code;
        if(rows[row]==code*size){
            return player;
        }
        cols[col]+=code;
        if(cols[col]==code*size){
            return player;
        }
        if(row==col){
            diag+=code;
            if(diag==code*size)
                return player;
        }
        if(row+col==size-1){
            antidiag+=code;
            if(antidiag==code*size)
                return player;
        }
        
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
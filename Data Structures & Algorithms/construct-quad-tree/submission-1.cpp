/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* solve(vector<vector<int>>& grid,int row_start,int row_end,int col_start,int col_end){
        if(row_start>row_end || col_start>col_end) return NULL;
        Node* root;
        int check = grid[row_start][col_start];
        bool same = true;
        for(int i=row_start;i<row_end;i++){
            for(int j=col_start;j<col_end;j++){
                if(check != grid[i][j]){
                    same=false;
                    break;
                }
            }
            if(!same) break;
        }

        if(!same){
            int midRow = (row_start + row_end) / 2;
            int midCol = (col_start + col_end) / 2;
            root = new Node(1,0); 
            root->topLeft = solve(grid,row_start,midRow,col_start,midCol);
            root->topRight = solve(grid,row_start,midRow,midCol,col_end);
            root->bottomLeft = solve(grid,midRow,row_end,col_start,midCol);
            root->bottomRight = solve(grid,midRow,row_end,midCol,col_end);
        }
        else{
            root = new Node(check,1);
        }
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return solve(grid,0,n,0,n);
    }
};
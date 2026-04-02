class Solution:
    def check_row(self,board,i,j)->bool:
        seen = set()
        for k in range(9):
            if board[i][k] != ".":
                if board[i][k] in seen:
                    return False
                seen.add(board[i][k])
        return True

    def check_col(self,board,i,j)->bool:
        seen = set()
        for k in range(9):
            if board[k][j] != ".":
                if board[k][j] in seen:
                    return False
                seen.add(board[k][j])
        return True

    def check_box(self,board,i,j)->bool:
        seen = set()
        p = i//3 * 3
        q = j//3 * 3

        for i in range(p,p+3):
            for j in range(q,q+3):
                if board[i][j] != ".":
                    if board[i][j] in seen:
                        return False
                    seen.add(board[i][j])
        return True


    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] != ".":
                    row = self.check_row(board,i,j)
                    col = self.check_col(board,i,j)
                    box = self.check_box(board,i,j)
                    if not (row and col and box):
                        return False

        return True
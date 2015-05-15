def dfs(board, visited, i,j):
    if i < 0 or j < 0 or i >= len(board) or j >= len(board[0]):
        return
    if board[i][j] != 'O':
        return
    if visited[i][j] == True:
        return
    visited[i][j] = True
    dfs(board,visited,i - 1,j)
    dfs(board,visited,i + 1,j)
    dfs(board,visited,i,j - 1)
    dfs(board,visited,i,j + 1)
    return

def fun(n):
    if (len(n) == 0):
        return
    visited = [[False for i in range(len(n))] for j in range(len(n[0]))]
    for i in range(len(n)):
         for j in range(len(n[0])):
             if i == 0 or j == 0 or i == len(n) - 1 or j == len(n[0]) - 1:
                 dfs(board,visited, i, j)
    for i in range(len(n)):
        for j in range(len(n[0])):
            if board[i][j] == 'O' and visited[i][j] == False:
                board[i][j] = '2'
    return

board = [['X' for i in range(4)] for j in range(4)]
board[1][1] = 'O'
board[1][2] = 'O'
board[2][2] = 'O'
board[3][1] = 'O'
board[3][2] = 'O'
fun(board)
print(board)
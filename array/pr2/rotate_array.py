def rotate_array(query, matrix):
    
    dx = [0,1,0,-1]
    dy = [1,0,-1,0]
    cur_dir = 0
    
    x = query[0]-1
    y = query[1]-1
    curr_num = matrix[x][y]
    min_v = curr_num
    while cur_dir < 4:
        nx = x + dx[cur_dir]
        ny = y + dy[cur_dir]
        if nx < query[0]-1 or nx > query[2]-1 or ny < query[1]-1 or ny > query[3]-1:
            cur_dir += 1
            continue
        temp = matrix[nx][ny]
        matrix[nx][ny] = curr_num
        curr_num = temp
        min_v = min(curr_num, min_v)
        x = nx
        y = ny
        
    return matrix, min_v

def solution(rows, columns, queries):
    answer = []
    array = []
    matrix = [[j+i*columns for j in range(1, columns+1)] for i in range(rows)]

    for query in queries:
        m, min_v = rotate_array(query, matrix)
        matrix = m
        answer.append(min_v)
    return answer
from queue import Queue

def solution(maps):
    r = len(maps)
    c = len(maps[0])
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]
    q = Queue()
    dis = [[-1 for j in range(c)] for i in range(r)]

    q.put([0,0])
    dis[0][0] = 0

    while(q.empty() == False):
        p = q.get()
        x = p[0]
        y = p[1]

        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]

            if nx >= r or nx < 0 or ny >= c or ny < 0:
                continue
            if dis[nx][ny] != -1 or maps[nx][ny] == 0:
                continue

            dis[nx][ny] = dis[x][y]+1
            q.put([nx,ny])

    return -1 if dis[r-1][c-1] == -1 else dis[r-1][c-1]+1

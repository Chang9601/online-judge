def calc(n,grid,pos):
    return abs(grid[n][0]-pos[0])+abs(grid[n][1]-pos[1])

def update(pos,n,grid,hand):
    pos[0] = grid[n][0]
    pos[1] = grid[n][1]
    return 'L' if hand == 'left' else 'R'

def solution(numbers, hand):
    ans = ''
    grid = [[3,1],[0,0],[0,1],[0,2],[1,0],[1,1],[1,2],[2,0],[2,1],[2,2]]

    lpos = [3,0]
    rpos = [3,2]

    for n in numbers:
        if n == 1 or n == 4 or n == 7:
            ans += update(lpos,n,grid,'left')
        elif n == 3 or n == 6 or n == 9:
            ans += update(rpos,n,grid,'right')
        else:
            ld = calc(n,grid,lpos)
            rd = calc(n,grid,rpos)

            if ld < rd:
                ans += update(lpos,n,grid,'left')
            elif ld > rd:
                ans += update(rpos,n,grid,'right')
            else:
                ans += update(lpos,n,grid,hand) if hand == 'left' else update(rpos,n,grid,hand)
    return ans

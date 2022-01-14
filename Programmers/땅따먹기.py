def solution(land):
    r, c = (len(land),4)
    dp = [[0 for i in range(c)] for j in range(r)]
    ans = -1

    for i in range(r):
        for j in range(c):
            if i == 0:
                dp[i][j] = land[i][j] 
            for k in range(c):
                if i-1 >= 0 and j != k:
                    dp[i][j] = max(dp[i][j],dp[i-1][k]+land[i][j])

    for j in range(0,c):
        ans = max(ans,dp[r-1][j])

    return ans

def solution(triangle):
    r = len(triangle)
    c = len(triangle[r-1])

    dp = [[-1 for j in range(c)] for i in range(r)]
    dp[0][0] = triangle[0][0]

    for i in range(1,r):
        for j in range(0,len(triangle[i])):
            dp[i][j] = max(dp[i][j],dp[i-1][j]+triangle[i][j])
            if j-1 >= 0:
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+triangle[i][j])

    ans = -1
    for j in range(0,c):
        ans = max(ans,dp[r-1][j])
    return ans

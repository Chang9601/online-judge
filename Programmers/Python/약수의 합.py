import math

def solution(n):
    ans = 0

    for i in range(1, int(math.sqrt(n))+1):
        if n%i == 0:
            ans += i
            j = n/i
            if i != j:
                ans += j
    return ans

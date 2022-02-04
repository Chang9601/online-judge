import math

def solution(n):
    ans = 0
    sqrt = math.sqrt(n)
    rsqrt = int(sqrt)

    if sqrt == rsqrt:
        ans = (rsqrt+1) ** 2
    else:
        ans = -1

    return ans

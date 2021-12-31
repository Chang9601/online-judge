def gcd(n,m):
    return n if m == 0 else gcd(m,n%m)

def lcm(n,m):
    return n//gcd(n,m)*m

def solution(arr):
    ans = 1
    for num in arr:
        ans = lcm(num,ans)
    return ans

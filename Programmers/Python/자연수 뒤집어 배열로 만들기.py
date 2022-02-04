def solution(n):
    ans = []
    
    while n:
        ans.append(n%10)
        n //= 10
    
    return ans

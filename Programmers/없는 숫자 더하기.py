def solution(numbers):
    ans = 0
    s = set(range(0,10)) 
    
    for num in s:
        if num not in numbers:
            ans += num
    return ans

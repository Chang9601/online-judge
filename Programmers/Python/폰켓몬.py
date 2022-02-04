def solution(nums):
    nums = sorted(nums)
    ans = 0
    size = len(nums)/2

    print(nums)

    last = -1
    for n in nums:
        if n != last:
            last = n
            if ans < size:
                ans += 1

    return ans

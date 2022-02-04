def solution(seoul):
    ans = ""
    for i, s in enumerate(seoul):
        if s == "Kim":
            ans = "김서방은 " + str(i) + "에 있다"
            break

    return ans

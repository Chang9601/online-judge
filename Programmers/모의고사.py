def solution(answers):
    one = [1,2,3,4,5]
    two = [2,1,2,3,2,4,2,5]
    three = [3,3,1,1,2,2,4,4,5,5]
    correct = [0,0,0]

    for i in range(0, len(answers)):
        correct[0] += 1 if one[i%len(one)] == answers[i] else 0
        correct[1] += 1 if two[i%len(two)] == answers[i] else 0
        correct[2] += 1 if three[i%len(three)] == answers[i] else 0

    mx = max(correct)
    ans = []

    for i in range(0, 3):
        if mx == correct[i]:
            ans.append(i+1)
    return ans

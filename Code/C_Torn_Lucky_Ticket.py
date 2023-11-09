n = int(input())

arr = input().split()

dp = [[0 for _ in range(46)] for __ in range(6)]
cnts = {}

for value in arr:
    dp[len(value)][sum([int(digit) for digit in value])] += 1
    cnts[value] = 1 if value not in cnts.keys() else cnts[value] + 1

ans = 0

for _,cnt in cnts.items():
    ans += cnt ** 2

# for value in arr:
#     for length in range(0,len(value)):
#         totalLength = len(value) + length
#         if totalLength % 2 == 0:
#             left = sum([int(digit) for digit in value[:totalLength // 2]])
#             extra = sum([int(digit) for digit in value[totalLength // 2:]])
#             if left - extra >= 0:
#                 ans += dp[length][left - extra]
for L in arr:
    for lenr in range(len(L) % 2, len(L), 2):
        l = len(L) + lenr
        suml = sum([int(c) for c in L[:l // 2]])
        sumr = sum([int(c) for c in L[l // 2:]])
        if suml - sumr >= 0:
            ans += dp[lenr][suml - sumr]

for value in arr:
    for length in range(0,len(value)):
        totalLength = len(value) + length
        if totalLength % 2 == 0:
            right = sum([int(digit) for digit in value[-totalLength // 2]])
            extra = sum([int(digit) for digit in value[:-totalLength // 2]])
            if right - extra >= 0:
                # print(right - extra)
                ans += dp[length][right - extra]
# for R in arr:
#     for lenl in range(len(R) % 2, len(R), 2):
#         l = len(R) + lenl
#         suml = sum([int(c) for c in R[-l // 2:]])
#         sumr = sum([int(c) for c in R[:-l // 2]])
#         if suml - sumr >= 0:
#             ans += dp[lenl][suml - sumr]

print(ans)

# n = int(input())
# s = input().split()
# ans = 0
# cnt = [[0 for k in range(46)] for k in range(6)]
# for y in s:
#     cnt[len(y)][sum([int(c) for c in y])] += 1
# for L in s:
#     for lenr in range(len(L) % 2, len(L) + 1, 2):
#         l = len(L) + lenr
#         suml = sum([int(c) for c in L[:l // 2]])
#         sumr = sum([int(c) for c in L[l // 2:]])
#         if suml - sumr >= 0:
#             ans += cnt[lenr][suml - sumr]
# for R in s:
#     for lenl in range(len(R) % 2, len(R), 2):
#         l = len(R) + lenl
#         suml = sum([int(c) for c in R[-l // 2:]])
#         sumr = sum([int(c) for c in R[:-l // 2]])
#         if suml - sumr >= 0:
#             ans += cnt[lenl][suml - sumr]
# print(ans)
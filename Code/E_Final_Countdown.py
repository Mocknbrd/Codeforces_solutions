t = int(input())

for _ in range(t):
    n: int = int(input())
    clock = input()
    ans,digit,total = 0,len(clock),0
    clock = clock[::-1]
    for curr_digit in clock[1:]:
        int_digit = int(curr_digit)
        ans += digit * int_digit
        total += int_digit
        digit -= 1
    ans += int(clock[::-1]) - total
    print(ans)

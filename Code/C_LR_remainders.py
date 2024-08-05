t = int(input())

for _ in range(t):
    n,m = [int(_) for _ in input().split()]
    arr = [int(_) for _ in input().split()]
    string = input()
    product = 1
    
    for value in arr:
        product *= value
    
    left,right = 0,n - 1

    print(product)

    for character in string:
        print(int(product % m),end = ' ')
        if character == "L":
            product /= arr[left]
            left += 1
        else:
            product /= arr[right]
            right -= 1
    print()

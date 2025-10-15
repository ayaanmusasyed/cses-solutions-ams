n = int(input())
arr = [n]
x = n
while x != 1: 
    if x % 2 == 1:
        x = 3*x + 1
    else: 
        x = x // 2
    
    arr.append(x)

print(*arr)
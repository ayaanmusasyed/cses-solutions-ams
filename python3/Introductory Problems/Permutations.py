n = int(input())
# print odd idx then even idx 
res = []

if n == 2 or n == 3: 
    print("NO SOLUTION")
else: 
    for i in range(2,n + 1,2):
        res.append(i) 
    for i in range(1,n + 1,2): 
        res.append(i)
    print(*res)


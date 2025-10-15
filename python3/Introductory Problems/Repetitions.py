s = input()
n = len(s) 
i = 0
res = 0
y = 0
while i < n:
    if i == 0: 
        i += 1
        y = 1
    else:
        prev = s[i - 1]
        curr = s[i] 
        if prev == curr: 
            y += 1
        else: 
            y = 1
        i += 1
    res = max(res, y)
print(res)
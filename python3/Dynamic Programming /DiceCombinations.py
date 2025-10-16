n = int(input())

dp = [0 for i in range(n + 1)]
dp[0] = 1
dice = [1,2,3,4,5,6]
for i in range(1, n + 1): 
    for d in dice: 
        if d <= n: 
            dp[i] += dp[i - d]
            dp[i] = dp[i] % (10**9 + 7)

print(dp[n])
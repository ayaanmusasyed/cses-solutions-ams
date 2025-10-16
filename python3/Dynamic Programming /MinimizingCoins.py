n, x = map(int,input().split())
coins = list(map(int,input().split()))
f = float("inf")
# 1D DP 
dp = [f for i in range(x + 1)]
dp[0] = 0
for i in range(1, x + 1):
    for c in coins: 
        if c > i:
            continue 
        elif dp[i - c] == f: 
            continue 
        dp[i] = min(dp[i], dp[i - c] + 1)

if dp[x] == f: 
    print(-1)
else: 
    print(dp[x])
n = int(input())
nums = list(map(int,input().split()))

S = (n*(n + 1))//2
print(S - sum(nums))
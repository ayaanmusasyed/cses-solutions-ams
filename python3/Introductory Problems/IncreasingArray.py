n = int(input())
nums = list(map(int,input().split()))

i = 1
res = 0
while i < n: 
    if nums[i] < nums[i - 1]:
        res += nums[i - 1] - nums[i] 
        nums[i] = nums[i - 1]
    i += 1
print(res) 

n = int(input())
L = {}
sum = 0
for i, v in enumerate(input().split(' ')):
    a = int(v)
    if a in L: L[a] += 1
    else: L[a] = 1
    sum += i*a + (n-i-1)*(-a);
    if a-1 in L: sum -= L[a-1]
    if a+1 in L: sum += L[a+1]

print(sum)

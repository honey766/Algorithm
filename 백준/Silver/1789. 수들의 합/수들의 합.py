s = int(input())
i, sum = 0, 0
while True:
    i += 1
    sum += i
    if s <= sum:
        break
if s == sum:
    print(i)
else:
    print(i - 1)
n = int(input().strip())
a = list(map(int, input().strip().split(' ')))

num_swap = 0

for i in range(n):
    count = 0

    for j in range(n - 1):
        if(a[j] > a[j + 1]):
            a[j], a[j + 1] = a[j + 1], a[j]
            count += 1

    if count == 0:
        break
    num_swap += count

print("Array is sorted in " + str(num_swap) + " swaps.")
print("First Element: " + str(a[0]))
print("Last Element: " + str(a[n - 1]))
    

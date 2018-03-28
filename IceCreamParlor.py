#The same idea as searching for two elements with a specific sum --
#using hashtable to achieve O(n) time complexity
t = int(input().strip())
for a0 in range(t):
    m = int(input().strip())
    n = int(input().strip())
    a = list(map(int, input().strip().split(' ')))

    first, second = 0, 0
    dic = dict()
    for i, j in enumerate(a):
        temp = m - j
        #print(temp)
        if temp in dic:
            first = dic[temp]
            second = i
            break
        else:
            dic[j] = i
    if first > second:
        first, second = second, first
    print(str(first + 1), str(second + 1))

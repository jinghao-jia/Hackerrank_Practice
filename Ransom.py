def ransom_note(magazine, ransom):
    table = {}

    for word in magazine:
        if word in table:
            table[word] += 1
        else:
            table[word] = 1

    for word in ransom:
        if word in table:
            table[word] -= 1
        else:
            return False

    for word in table:
        if table[word] < 0:
            return False

    return True

m, n = map(int, input().strip().split(' '))
magazine = input().strip().split(' ')
ransom = input().strip().split(' ')
answer = ransom_note(magazine, ransom)
if(answer):
    print("Yes")
else:
    print("No")

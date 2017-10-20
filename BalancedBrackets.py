# Algorithm: Keeps pushing front brackets, when encountered a back bracket
# check if the top element is its front bracket, if it is not, the string is
# not balanced; else, pop the stack once and repeat this process until reaches
# the end of the string. When finished, check if the stack is empty, if it is
# not, that means some of the front brackets do not have a pair and the string
# is not balanced.


def is_matched(expression):
    front = ("{", "[", "(") #Front brackets
    stack = [] #Stack to use

    #Loop through the whole input string
    for char in expression:

        #If it is a front bracket, push it into the stack
        if char in front:
            stack.append(char)

        #Else always do a top to look for pairs: if found,
        #then pop the stack; if it does not have a pair,
        #return False
        elif char == "}":
            if len(stack) == 0 or stack[len(stack) - 1] != "{":
                return False
            stack.pop()
        elif char == "]":
            if len(stack) == 0 or stack[len(stack) - 1] != "[":
                return False
            stack.pop()
        elif char == ")":
            if len(stack) == 0 or stack[len(stack) - 1] != "(":
                return False
            stack.pop()

    # Check if the stack is empty, if it is not, return False
    return len(stack) == 0


t = int(input().strip())
for a0 in range(t):
    expression = input().strip()
    if is_matched(expression) == True:
        print("YES")
    else:
        print("NO")

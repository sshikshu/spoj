'''arith2'''

T = int(input().strip())

for _ in range(T):
    _ = input()
    expression = [x for x in input().strip().split(' ') if x != '']
    value = int(expression[0])

    for i in range(1, len(expression) - 1, 2):
        if expression[i] == '+':
            value += int(expression[i + 1])
        elif expression[i] == '-':
            value -= int(expression[i + 1])
        elif expression[i] == '*':
            value *= int(expression[i + 1])
        elif expression[i] == '/':
            value //= int(expression[i + 1])
    print(value)

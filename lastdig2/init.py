'''lastdig2'''

VALUES = ((0, 0, 0, 0), (1, 1, 1, 1), (6, 2, 4, 8), (1, 3, 9, 7), (6, 4, 6, 4),
          (5, 5, 5, 5), (6, 6, 6, 6), (1, 7, 9, 3), (6, 8, 4, 2), (1, 9, 1, 9))
T = int(input().strip())
for _ in range(T):
    a, b = input().strip().split(' ')
    base = int(a[-1])
    index = int(b)
    if index == 0:
        print(1)
        continue
    print(VALUES[base][index%4])

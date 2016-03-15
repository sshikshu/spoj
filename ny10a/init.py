'''ny10a'''

T = int(input())

for _ in range(1, T + 1):
    n = int(input())
    data = input().replace('T', '0').replace('H', '1')
    freq = [0] * 8
    for i in range(0, len(data) - 2):
        freq[int(data[i:i + 3], 2)] += 1
    print(n, end=' ')
    for i, point in enumerate(freq):
        if i != 7:
            print(point, end=' ')
            continue
        print(point)

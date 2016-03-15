'''easyprob'''

from math import log2, floor

VALUES = [137, 1315, 73, 136, 255, 1384, 16385]


def make_str(num: int)->str:
    'converts to str'
    if num == 1:
        return '2(0)'
    if num == 2:
        return '2'
    highest_power = floor(log2(num))
    if highest_power == 1:
        string = '2'
    else:
        string = '2(' + make_str(highest_power) + ')'
    remaining = num - 2**highest_power
    if remaining != 0:
        string += '+' + make_str(remaining)
    return string

for value in VALUES:
    print('{0}={1}'.format(value, make_str(value)))

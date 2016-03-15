package main

import (
	"fmt"
)

var memoizeMap map[uint64]uint64

func f(n uint64) uint64 {
	if n == 0 || memoizeMap[n] != 0 {
		return memoizeMap[n]
	}
	val := f(n/2) + f(n/3) + f(n/4)
	memoizeMap[n] = val
	return val
}

func main() {
	memoizeMap = map[uint64]uint64{
		0:  0,
		1:  1,
		2:  2,
		3:  3,
		4:  4,
		5:  5,
		6:  6,
		7:  7,
		8:  8,
		9:  9,
		10: 10,
		11: 11,
	}
	var n uint64
	for {
		if t, err := fmt.Scanf("%d", &n); t != 1 || err != nil {
			break
		}
		fmt.Println(f(n))
	}
}

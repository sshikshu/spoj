package main

import (
	"fmt"
	"math"
)

func main() {
	var t int
	var n, a, x, y uint64
	fmt.Scanf("%d", &t)
	for ; t > 0; t-- {
		fmt.Scanf("%d", &n)
		a = uint64(math.Floor((3 + math.Sqrt(float64(8*n-7))) / 2))
		if a%2 == 0 {
			y = n - (a*a-3*a+2)/2
			x = a - y
		} else {
			x = n - (a*a-3*a+2)/2
			y = a - x
		}
		fmt.Printf("TERM %d IS %d/%d\n", n, x, y)
	}
}

package main

import (
	"fmt"
)

func main() {
	var i, n, sum, val int
	fmt.Scanf("%d", &n)
	sum = 0
	for i = 1; i <= n; i++ {
		val = n/i - i + 1
		if val > 0 {
			sum += val
		}
	}
	fmt.Println(sum)
}

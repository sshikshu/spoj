package main

import (
	"fmt"
)

func main() {
	var t, k, temp uint64
	fmt.Scanf("%d", &t)
	for ; t > 0; t-- {
		fmt.Scanf("%d", &k)
		temp = 192 + 250*(k-1)
		fmt.Println(temp)
	}
}

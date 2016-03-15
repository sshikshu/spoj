package main

import (
	"fmt"
	"math"
)

func main() {
	var n uint64
	fmt.Scanf("%d", &n)
	nLog2 := math.Log2(float64(n))
	if nLog2 == math.Trunc(nLog2) {
		fmt.Println("TAK")
	} else {
		fmt.Println("NIE")
	}
}

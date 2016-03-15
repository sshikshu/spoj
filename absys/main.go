package main

import (
	"fmt"
	"strconv"
)

func main() {
	var t uint64
	var aStr, bStr, cStr string
	fmt.Scanf("%d", &t)
	for ; t > 0; t-- {
		fmt.Scanln()
		fmt.Scanf("%s + %s = %s ", &aStr, &bStr, &cStr)

		a, errA := strconv.Atoi(aStr)
		b, errB := strconv.Atoi(bStr)
		c, errC := strconv.Atoi(cStr)

		if errA != nil {
			a = c - b
		}
		if errB != nil {
			b = c - a
		}
		if errC != nil {
			c = a + b
		}
		fmt.Printf("%d + %d = %d\n", a, b, c)
	}
}

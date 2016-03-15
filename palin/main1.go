package main

import (
	"fmt"
	"math"
)

func main1() {
	var t int
	var k, leftVal, rightVal, halfLength, pos, fullLength int
	if _, err := fmt.Scan(&t); err != nil {
		return
	}
	increasedFlag := false
	for ; t > 0; t-- {
		if _, err := fmt.Scan(&k); err != nil {
			return
		}
		fullLength = int(math.Log10(float64(k)))
		halfLength = fullLength / 2
		for pos = 0; pos < halfLength+1; pos++ {
			leftVal = k / int(math.Pow10(fullLength-pos)) % 10
			rightVal = k / int(math.Pow10(pos)) % 10
			k += (leftVal - rightVal) * int(math.Pow10(pos))
			if leftVal > rightVal {
				increasedFlag = true
			} else {
				increasedFlag = false
			}
		}
		if !increasedFlag {
			num := int(math.Pow10(halfLength))
			if k/num%10 == 9 {
				k = int(math.Pow10(fullLength+1) + 1)
			}
			k += int(math.Pow10(halfLength))
			if fullLength%2 == 1 {
				k += int(math.Pow10(halfLength + 1))
			}
		}
		fmt.Println(k)
	}
}

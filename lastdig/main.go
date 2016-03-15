package main

import (
	"fmt"
)

func main() {
	var t, a, b, lastDigit int
	fmt.Scanf("%d", &t)
	for i := 0; i < t; i++ {
		fmt.Scanf("%d %d", &a, &b)
		if b == 0 {
			lastDigit = 1
		} else {
			switch a % 10 {
			case 0:
				lastDigit = 0
			case 1:
				lastDigit = 1
			case 2:
				lastDigit = []int{6, 2, 4, 8}[b%4]
			case 3:
				lastDigit = []int{1, 3, 9, 7}[b%4]
			case 4:
				lastDigit = []int{6, 4}[b%2]
			case 5:
				lastDigit = 5
			case 6:
				lastDigit = 6
			case 7:
				lastDigit = []int{1, 7, 9, 3}[b%4]
			case 8:
				lastDigit = []int{6, 8, 4, 2}[b%4]
			case 9:
				lastDigit = []int{1, 9}[b%2]
			}
		}
		fmt.Println(lastDigit)
	}
}

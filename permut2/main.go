package main

import (
	"fmt"
)

func main() {
	var n, temp int
	for {
		isNonAmbiguous := false
		fmt.Scanf("%d", &n)
		if n == 0 {
			break
		}
		permutation := make([]int, n)
		inversePermutation := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scanf("%d", &temp)
			temp--
			permutation[i] = temp
			inversePermutation[temp] = i
		}

		for i, val := range permutation {
			if val != inversePermutation[i] {
				isNonAmbiguous = true
				break
			}
		}
		if isNonAmbiguous {
			fmt.Println("not ambiguous")
		} else {
			fmt.Println("ambiguous")
		}
	}
}

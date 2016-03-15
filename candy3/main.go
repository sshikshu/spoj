package main

import (
	"fmt"
)

func main() {
	var sum, temp, n, j, t int64
	fmt.Scanf("%d", &t)
	for ; t > 0; t-- {
		sum = 0
		fmt.Scanln()
		fmt.Scanf("%d", &n)
		for j = 0; j < n; j++ {
			fmt.Scanf("%d", &temp)
			sum += temp
			sum %= n
		}
		if sum == 0 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}

	}
}

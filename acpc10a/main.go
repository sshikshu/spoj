package main

import (
	"fmt"
)

func main() {
	var a1, a2, a3 int
	for {
		fmt.Scanf("%d %d %d", &a1, &a2, &a3)
		if a1 == 0 && a2 == 0 && a3 == 0 {
			break
		}
		if a3-a2 == a2-a1 {
			fmt.Printf("AP %d\n", 2*a3-a2)
		} else {
			fmt.Printf("GP %d\n", a3*a3/a2)
		}
	}
}

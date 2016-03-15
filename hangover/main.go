package main

import (
	"fmt"
)

func main() {
	var c float32
	hangovers := make([]float32, 500)
	for i := 1; i < len(hangovers); i++ {
		hangovers[i] = hangovers[i-1] + float32(1)/float32(i+1)
	}
	for {
		fmt.Scanf("%f", &c)
		if c == 0.00 {
			break
		}
		for i, hangover := range hangovers {
			if hangover > c {
				fmt.Println(i, "card(s)")
				break
			}
		}
	}
}

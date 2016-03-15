package main

import (
	"fmt"
	"strings"
)

func main() {
	var columns, rows int
	var text string
	var code []string
	for {
		fmt.Scanf("%d", &columns)
		if columns == 0 {
			break
		}
		fmt.Scanf("%v", &text)
		code = strings.Split(text, "")
		rows = len(text) / columns
		for i := 0; i < columns; i++ {
			for j := 0; j < rows; j += 2 {
				fmt.Print(code[i+j*columns])
				if j+1 >= rows {
					break
				}
				fmt.Print(code[(j+2)*columns-i-1])
			}
		}
		fmt.Println()
	}
}

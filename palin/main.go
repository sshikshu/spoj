package main

import (
	"fmt"
	"strconv"
)

func main() {
	var t, length, halfLength, pos int
	var temp string
	var k []int
    var increasedFlag bool
	if _, err := fmt.Scan(&t); err != nil {
		return
	}

	for ; t > 0; t-- {
        increasedFlag = false
		fmt.Scanln(&temp)
		length = len(temp)
		halfLength = (length + 1) / 2
		k = make([]int, length)
		for i := 0; i < halfLength; i++ {
			tempLeft, _ := strconv.Atoi(temp[i : i+1])
			tempRight, _ := strconv.Atoi(temp[length-i-1 : length-i])
			k[i] = tempLeft
			k[length-i-1] = tempLeft
			if tempLeft > tempRight {
				increasedFlag = true
			} else if tempLeft < tempRight {
				increasedFlag = false
			}
		}
		pos = halfLength - 1
		if !increasedFlag && length%2 == 1 {
			if k[pos] == 9 {
				k[pos] = 0
				pos--
			} else {
				k[pos]++
				increasedFlag = true
			}
		}

		if !increasedFlag {
			for ; pos >= 0; pos-- {
				if k[pos] == 9 {
					k[pos] = 0
					k[length-pos-1] = 0
				} else {
					k[pos]++
					k[length-pos-1]++
					increasedFlag = true
					break
				}
			}
		}

		if increasedFlag {
			for _, n := range k {
				fmt.Print(n)
			}
		} else {
			fmt.Print(1)
			for i := 0; i < length-1; i++ {
				fmt.Print(0)
			}
			fmt.Print(1)
		}
		fmt.Println()
	}
}

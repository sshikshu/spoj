package main

import (
	"fmt"
	"strconv"
)

//use string
var memoStorage map[string]uint64

func codeSol(theCode string) uint64 {
	//fmt.Println(theCode, memoStorage[theCode])
	if theCode == "0" || memoStorage[theCode] != 0 {
		return memoStorage[theCode]
	}

	var temp uint64

	if theCode[:1] != "0" {
		temp += codeSol(theCode[1:])
	}
	if firstTwoElements, _ := strconv.Atoi(theCode[:2]); firstTwoElements < 27 && firstTwoElements > 9 {
		temp += codeSol(theCode[2:])
	}
	memoStorage[theCode] = temp
	return memoStorage[theCode]
}

func main() {
	var theCode string
	memoStorage = map[string]uint64{
		"0":  0,
		"1":  1,
		"2":  1,
		"3":  1,
		"4":  1,
		"5":  1,
		"6":  1,
		"7":  1,
		"8":  1,
		"9":  1,
		"10": 1,
		"11": 2,
		"12": 2,
		"13": 2,
		"14": 2,
		"15": 2,
		"16": 2,
		"17": 2,
		"18": 2,
		"19": 2,
		"20": 1,
		"21": 2,
		"22": 2,
		"23": 2,
		"24": 2,
		"25": 2,
		"26": 2,
	}
	for {
		fmt.Scanf("%s", &theCode)
		if theCode == "0" {
			break
		}
		fmt.Println(codeSol(theCode))
	}
}

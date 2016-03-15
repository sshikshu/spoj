package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var t, maxMechazilla, maxGodzilla, nG, nM uint64
	var godzilla, mechazilla []string
	reader := bufio.NewReader(os.Stdin)
	fmt.Scanf("%d", &t)
	for ; t > 0; t-- {
		fmt.Scanln()
		fmt.Scanf("%d %d", &nG, &nM)
		godzillaArmy, _ := reader.ReadString('\n')
		mechazillaArmy, _ := reader.ReadString('\n')
		godzilla = strings.Split(godzillaArmy, " ")
		mechazilla = strings.Split(mechazillaArmy, " ")
		for ; nG > 0; nG-- {
			temp, _ := strconv.ParseUint(godzilla[nG-1], 10, 64)
			if temp > maxGodzilla {
				maxGodzilla = temp
			}
		}
		for ; nM > 0; nM-- {
			temp, _ := strconv.ParseUint(mechazilla[nM-1], 10, 64)
			if temp > maxMechazilla {
				maxMechazilla = temp
				if maxMechazilla > maxGodzilla {
					break
				}
			}
		}
		if maxGodzilla < maxMechazilla {
			fmt.Println("MechaGodzilla")
		} else {
			fmt.Println("Godzilla")
		}
	}
}

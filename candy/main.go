package main

import "fmt"

func main() {
	var packets, sum, candies int
	for {
		fmt.Scanf("%d", &packets)
		if packets < 0 {
			break
		}
		sum = 0
		candies = 0
		packetsList := make([]int, packets)
		for i := 0; i < packets; i++ {
			fmt.Scanf("%d", &packetsList[i])
			sum += packetsList[i]
		}

		if sum%packets != 0 {
			fmt.Println("-1")
		} else {
			mean := sum / packets
			for _, packet := range packetsList {
				if packet-mean > 0 {
					candies += packet - mean
				}
			}
			fmt.Println(candies)
		}
	}
}

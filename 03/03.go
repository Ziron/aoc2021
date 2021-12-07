package main

import (
	"bufio"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	const BITLEN = 12

	var counts [BITLEN]int

	for scanner.Scan() {

		var line = scanner.Text()

		for i := 0; i < BITLEN; i++ {
			if line[i] == '0' {
				counts[i]--
			} else if line[i] == '1' {
				counts[i]++
			} else {
				panic("Invalid bit string")
			}
		}

	}

	var gamma_rate int
	var epsilon_rate int

	for i := 0; i < BITLEN; i++ {
		if counts[i] > 0 {
			gamma_rate = (gamma_rate << 1) | 1
			epsilon_rate <<= 1
		} else if counts[i] < 0 {
			gamma_rate <<= 1
			epsilon_rate = (epsilon_rate << 1) | 1
		} else {
			panic("Invalid count")
		}
	}

	println(gamma_rate)
	println(epsilon_rate)
	println(gamma_rate * epsilon_rate)

}

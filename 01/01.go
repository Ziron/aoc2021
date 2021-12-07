package main

import (
	"bufio"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var last int64 = 9223372036854775807
	incCount := 0
	for scanner.Scan() {
		number, _ := strconv.ParseInt(scanner.Text(), 10, 0)

		if number > last {
			incCount++
		}
		last = number
	}
	println(incCount)
}

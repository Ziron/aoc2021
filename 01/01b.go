package main

import (
	"bufio"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var intmax int64 = 9223372036854775807

	lastlast := intmax
	last := intmax
	lastsum := intmax
	incCount := 0
	for scanner.Scan() {
		number, _ := strconv.ParseInt(scanner.Text(), 10, 0)

		if lastlast == intmax {
			lastlast = number
			continue
		}
		if last == intmax {
			last = number
			continue
		}

		sum := number + lastlast + last
		if sum > lastsum {
			incCount++
		}
		lastlast = last
		last = number
		lastsum = sum
	}
	println(incCount)
}

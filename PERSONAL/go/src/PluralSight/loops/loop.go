package main

import (
	"fmt"
)

func main() {
	coursesInProg := []string{"DDD", "HHH", "AAA"}
	coursesCompleted := []string{"DDD", "ZZZ", "XXX"}

	for _, i := range coursesInProg{
		for _, j := range coursesCompleted {
			if i == j {
				fmt.Println("\nFOUND A CLASH.", i, "is in both lists")
			}
		}
	}
}
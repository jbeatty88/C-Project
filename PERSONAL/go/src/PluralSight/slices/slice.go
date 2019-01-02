package main

import (
	"fmt"
)

func main() {
	// Slice declaration 1  := make([]<type>, <len>, <capacity>)
	// myCourses := make([]string, 5, 10) // slice of strings, len of 5, max size 10

	// Slice declaration 2 (SHORTHAND) := []<type> {VALUES}
	myCourses := []string{"Docker", "Puppet", "Python"}

	fmt.Printf("Lendth is: %d. \nCapacity is: %d", len(myCourses), cap(myCourses))
	fmt.Println("\n\n")
	
	mySlice := []int{1,2,3,4,5,6,7,8,9,10}
	fmt.Println(mySlice[4])

	// left is inclusive, right is exclusive [:5] === 0-5
	sliceOfSlice := mySlice[2:5]
}
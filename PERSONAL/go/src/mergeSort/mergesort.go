package main

import (
	"fmt"
	"math/rand"
	"time"
)

func datagen(size int) []int {
	// Variable to return with random data
	slice := make([]int, size, size)
	// Generate random numbers based on Unix Epoch time
	rand.Seed(time.Now().UnixNano())
	// Append to the variable slice however many times was passes as arg
	for i := 0; i < size; i++ {
		// Append it variable
		slice[i] = rand.Intn(999) - rand.Intn(999)
	}
	return slice
}

func mergeSort(items []int) []int {
	// Get the number of items to be sorted
	var num = len(items)

	// If there is only one item
	if num == 1 {
		// Just return it
		return items
	}
	// Set the middle variable counter to the number of items / 2
	middle := int(num / 2)
	// Variables
	var (
		left = make([]int, middle)
		right = make([]int, num - middle)
	)
	// Iterate through the data passed to this func
	for i := 0; i < num; i++ {
		// If we are on the first half
		if i < middle {
			// Copy current data item to left variable
			left[i] = items[i]
		// If we are on the second half
		} else {
			// Compy current data to right variable
			right[i - middle] = items[i]
		}
	}
	// Pass our left and right objs to merge and return what it returns
	return merge(mergeSort(left), mergeSort(right))
}

func merge(left, right []int) (result []int) {
	// Allocate space for the result
	result = make([]int, len(left) + len(right))

	i := 0
	// While there are data items on both sides
	for len(left) > 0 && len(right) > 0 {
		// If the first item of left is less than first item right
		if left[0] < right[0] {
			// Copy it to result variable
			result[i] = left[0]
			// Remove that first data item from left variable
			left = left[1:]
		// If the first item of left is greater than right
		} else {
			// Add the lesser one to result variable
			result[i] = right[0]
			// Remove that data item from the right variable
			right = right[1:]
		}
		i++
	}
	// Iterate through the left variable
	for j := 0; j < len(left); j++ {
		// Copy values from left to result
		result[i] = left[j]
		i++
	}
	// Iterate through right variable
	for j := 0; j < len(right); j++ {
		// Copy valuse from right to result
		result[i] = right[j]
		i++
	}
	return
}

func main() {
	slice := datagen(10)
	fmt.Println(slice)
	mergeSort(slice)
	fmt.Println(slice)
}

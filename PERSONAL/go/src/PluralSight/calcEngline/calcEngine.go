package main

import (
	"fmt"
)

func main() {
	calculate(15, 3)

}

func printResults(maths int) {
	fmt.Println(maths)
}

func adder(left, right int) (int) {
	result := left + right
	printResults(result)
	return result
}

func subtractor(left, right int) int {
	result := left - right
	printResults(result)
	return result
}

func multiplyer(left, right int) int {
	result := left * right
	printResults(result)
	return result
}

func divider(left, right int) int {
	switch(right) {
	case 0:
		fmt.Println("CANNOT DIVIDE BY 0")
		return 0
	default:
		result := left / right
		printResults(result)
		return result
	}
}

func calculate(leftVal, rightVal int) {
	adder(leftVal, rightVal)
	subtractor(leftVal, rightVal)
	multiplyer(leftVal, rightVal)
	divider(leftVal, rightVal)
}
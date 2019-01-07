package main

import (
	"fmt"
)

func main(){
	greet("Josh")
}

func greet(name string) {
	fmt.Printf("Hello %s\n", name)
}

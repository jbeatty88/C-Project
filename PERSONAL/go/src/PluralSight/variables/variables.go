package main

import(
	// similar to <iostream> type functions
	"fmt"
	// Get the types for the variables
	"reflect"
)
/*
//THIS IS THE LONG HIGHLY ACCURATE VARIABLE DECLARATION WAY
var (
	name, course  string
	module        float64
)
*/

// THIS IS MODERATLEY ACCURATE, GO INFERS THE TYPES
var (
	// Lazy (but correct) syntax
	//name, course, module = "Josh", "GoLang Basics", 3.2

	// Better more clear Syntax
	name    = "Josh"
	course  = "GoLang Basics"
	module  = 3.2
)

func main() {
	// Sec 1: Basic variable declaration outside of function(GLOBAL) and determining types
	fmt.Println("#######SECTION 1########\n")
	fmt.Println("Name is", name, "and is of type:", reflect.TypeOf(name))
	fmt.Println("Module is", module, "and is of type:", reflect.TypeOf(module))
	
	// Sec 2: Variables declared INSIDE functions and type casting
	fmt.Println("\n######SECTION 2#######")
	// Go infers type
	// Variables declared inside function MUST be used
	a :=  10.00000000  // float64
	b := 3             // int

	fmt.Println("\nA is type", reflect.TypeOf(a), "and B is type", reflect.TypeOf(b))

	c := int(a) + b  // Only works after a type cast

	fmt.Println("\nC has value:", c, "and is of type", reflect.TypeOf(c))

	// Sec 3: Pointers
	fmt.Println("\n#######SECTION 3########\n")
	ptr := &module
	fmt.Println("Memory address of *module* is", ptr, "\nAnd the value currently at that address is", *ptr)

	// Sec 4: Passing by Value (Makes a copy and leaves original variable unchanged)
	fmt.Println("\n#######SECTION 4#######\n")
	changeCourse(course)
	fmt.Println("\nfrom", course)

	// Sec 5: Passing by Reference (Changes original variable)
	fmt.Println("\n#######SECTION 5#######\n")
	changeName(&name)
	fmt.Println("This should be NATTHAYA:", name)
	
}

func changeCourse(course string) string {
	course = "JAVA JIM"

	fmt.Println("Changing course to", course)
	return course
}

func changeName(name *string) string {
	*name = "Natthaya"

	fmt.Println("Changed name to", *name)
	return *name
		
}

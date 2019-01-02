package main

import (
	"fmt"
)

func main() {
	// map[keytype]valuetype

	// Declaration using make
	leagueTitle := make(map[string]int)
	leagueTitle["Sunderland"] = 6
	leagueTitle["Newcastle"] = 4

	// Short had declaration on map
	// recentHead2Head := map[string]int {
	// 	"Sunderland": 5,
	// 	"NewCastle": 0,
	// }

	// Iterating through a map
	testMap := map[string]int {
		"A": 1,
		"B": 2,
		"C": 3,
		"D": 4,
		"E": 5,
	}

	for key, value := range testMap {
		fmt.Printf("\n%v value is: %v.", key, value)
	}

	// Modifying maps
	fmt.Println(testMap["A"])
	testMap["A"] = 100 // Updating values
	fmt.Println(testMap["A"])

	testMap["F"] = 1973 // Inserting into a map

	fmt.Println(testMap)

	delete(testMap, "F") // Deleting a whole item from map
	fmt.Println(testMap)

}
package main

import (
       "fmt"
       "math/rand"
       "time"
)

func datagen(size int) []int {
     slice := make([]int, size, size)
     rand.Seed(time.Now().UnixNano())
     for i := 0; i < size; i++ {
     	 slice[i] = rand.Intn(999) - rand.Intn(999)
     }
     return slice
}

func insertsort(items []int) {
     var n = len(items)
     for i := 1; i < n; i++ {
     	 j := i
	 for j > 0 {
	     if items[j-1] > items[j] {
	     	items[j-1], items[j] = items[j], items[j-1]
	     }
	     j = j - 1
	 }
     }
}

func main(){
     slice := datagen(20)

     fmt.Println("INSERTION SORT")
     fmt.Println("BEFORE: " , slice)
     insertsort(slice)
     fmt.Println("AFTER:  ", slice)
}

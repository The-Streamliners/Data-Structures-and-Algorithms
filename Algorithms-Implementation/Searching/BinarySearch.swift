//
//  BinarySearch.swift
//
//
//  Created by Pratik on 01/10/21.
//

import Foundation

/**
 Generic implementation of Binary Search
*/
func findIndexUsingBinarySearch<Generic:Comparable> (arrayOfData array:Array<Generic>,searchNumber search:Generic) -> Int? {
    var lIndex = 0 //First element index
    var rIndex = (array.count - 1) //Last element index
    
    for _ in lIndex...rIndex {
        let cIndex = (lIndex + rIndex) / 2 //Center index
        
        if (array[cIndex] == search) {
            return cIndex
        } else if (cIndex > rIndex) {
            return nil
        } else {
            if (array[cIndex] > search) {
                rIndex = cIndex - 1
            } else {
                lIndex = cIndex + 1
            }
        }
    }
    return nil
}

var searchingArray = [2,4,6,8,10]
if let index = findIndexUsingBinarySearch(arrayOfData: searchingArray,searchNumber: 6) {
    print("Search item found at index : ", index)
} else {
    print("Search item not found")
}


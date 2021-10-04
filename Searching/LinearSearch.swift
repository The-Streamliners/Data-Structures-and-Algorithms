//
//  LinearSearch.swift
//
//
//  Created by Pratik on 04/10/21.
//

import Foundation

/**
 Generic implementation of Linear Search
*/
func findIndexUsingLinearSearch<Generic:Equatable> (arrayOfData array:Array<Generic>,searchNumber search:Generic) -> Int? {
    for (index, value) in array.enumerated() where (value == search) {
        return index
    }
    return nil
}

var searchingArray = [2,4,6,8,10]
if let index = findIndexUsingLinearSearch(arrayOfData: searchingArray, searchNumber: 6) {
    print("Search item found at index : ", index)
} else {
    print("Search item not found")
}



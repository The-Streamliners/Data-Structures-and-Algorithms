//
//  FibonacciNumbers.swift
//
//
//  Created by Pratik on 04/10/21.
//

import Foundation

/**
 Implementation of Fibonacci numbers
*/

func findFibonnaciSeries(from n: Int) -> [Int] {
    /// Recursive method call untill condition true
    func recursive(number: Int) -> Int {
        guard number > 1 else {
            return number
        }
        return recursive(number: number - 1) + recursive(number: number - 2)
    }

    var arrayOfData = [Int]()
    //loop start from 0 to (number - 1) and store result into arrayOfData
    for i in 0..<n {
        let recursiveResult = recursive(number: i)
        arrayOfData.append(recursiveResult)
    }
    //series array return
    return arrayOfData
}

let series = findFibonnaciSeries(from: 10)
print(series)


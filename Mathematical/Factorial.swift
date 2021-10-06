//
//  Factorial.swift
//
//
//  Created by Pratik on 04/10/21.
//

import Foundation

/**
 Factorial number
*/

func findFactorial(of num: Int) -> Int {  
    if num > 1 {  
        return num * findFactorial(of: num - 1)  
    } else {  
        return 1  
    }  
}  
  
let number = 6  
let result = findFactorial(of: number)  
print(result)
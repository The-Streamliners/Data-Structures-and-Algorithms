//
//  Palindrome.swift
//  Palindrome
//
//  Created by Stevhen on 18/10/21.
//

import Foundation

func isPalindrome(_ word: String) -> Bool {
    return String(word.lowercased().reversed()) == word.lowercased()
}

func isPalindromeSecondMethod( _ value: String) -> Bool {
    if value.count >= 2 else {
        return true
    }

    let end = value.index(value.endIndex, offsetBy: -1)

    if value[value.startIndex] == value[end] {
        let start = value.index(value.startIndex, offsetBy: 1)
        return isPalindrome(String(value[start ..< end]))
    } else {
        return false
    }
}

//Example
let palindromes: [String] = [
    "Racecar",
    "Hannah",
    "Level",
    "Noon",
    "Radar",
    "Rotator"
]

for word in palindromes {
    print(isPalindrome(word))
}

for word in palindromes {
    print(isPalindromeSecondMethod(word))
}

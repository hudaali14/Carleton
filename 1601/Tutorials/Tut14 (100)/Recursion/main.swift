//
//  main.swift
//  Recursion
//
//  Created by Huda Ali on 2020-03-10.
//  Copyright © 2020 COMP1601. All rights reserved.
//

import Foundation

func getInput() -> String {
    let keyboard = FileHandle.standardInput
    let inputData = keyboard.availableData
    let strData = String(data: inputData, encoding: String.Encoding.utf8)!
    return strData.trimmingCharacters(in: CharacterSet.newlines)
}

func isPalindrome(input: String) -> Bool {
    if input == String(input.reversed()){
        return true;
    }else{
        return false
    }
}


var s1 = "Lou"
var s2 = ""
s2.insert("L", at: s2.endIndex)
s2.insert("o", at: s2.endIndex)
print("\(s1) == \(s2) is \(s1==s2)")
s2.insert("u", at: s2.endIndex)
print("\(s1) == \(s2) is \(s1==s2)")

var ball :Ball = Ball()
print("The ball is " + ball.getColour())

// prompt user
print("Please enter your name" + " + Return ")
var inputString = getInput();
print("Hello " + inputString)

while true{
    print("Please enter string" + " + Return ")
    let strData = getInput()
    if strData == "quit"{
        break
    }
    let inputString = isPalindrome(input: strData)
    print("isPaildrome(\(strData)) -> \(inputString)" + " + Return ")
}

//
//  main.swift
//  Assignment3
//
//  Created by Huda Ali on 2020-03-16.
//  Copyright © 2020 COMP1601. All rights reserved.
//

import Foundation

let pi = Double.pi      // Pi value
let g = -9.81           // Acceleration because of gravity

// Gets user inputs from keyboard
func getInput() -> String {
    let keyboard = FileHandle.standardInput
    let inputData = keyboard.availableData
    let strData = String(data: inputData, encoding: String.Encoding.utf8)!
    return strData.trimmingCharacters(in: CharacterSet.newlines)
}

// Exits program if quit is entered
func quitInput(input: String) -> Void {
    if(input == "quit"){
        exit(0);
    }
}

while(true){
    print("Type 'quit' at any time to quit the program");
    
    print("Please enter the intital height (in meters):");
    let height = getInput()
    quitInput(input: String(height))
    
    print("Please enter the intital angle of release (in degrees from 0 to 90):");
    let angle = getInput()
    quitInput(input: String(angle))
    
    print("Please enter the intital velocity (in meters per second):");
    let velocity = getInput()
    quitInput(input: String(velocity))
    
    print("Please enter the number of divisions per second (e.g 100):");
    let divisions = getInput()
    quitInput(input: String(divisions))
    
    let angleD = Double(angle) ?? 0
    let velocityD = Double(velocity) ?? 0
    let heightD = Double(height) ?? 0
    
    var x = Double(0)                           // Theorectical X value
    var y = Double(0)                           // Theorectical Y value
    let increment = 1/(Double(divisions) ?? 0)  // Divisions per second
    var flag = false;                           // Flag to check whether y has reached below zero
    
    // instance of Projectile class initialized with value obtained from user
    let  projectile: Projectile = Projectile(angle: angleD, velocity: velocityD, height: heightD, divisions: increment)
    
    // Headers
    print("              Theoretical                    Euler Approximation")
    print("TIME       Horizontal       Vertical       Horizontal         Vertical")
    
    while(y >= 0){
        
        // Calculate y value first in case it falls below zero
        projectile.yPosition(y: &y)
        
        // If we reached past zero then calculate the time it takes to get to zero
        if(y < 0){
            let a = (1/2) * g
            let b = velocityD * sin(angleD * (pi/180))
            let c = heightD
            let t = ((-b)-sqrt(pow(b, 2)-(4*a*c)))/(2*a)
            projectile.setDivisions(increment: t-(projectile.getTime()-increment))
            projectile.setTime(time: t)
            projectile.yPosition(y: &y)
            flag = true;
            
        }
        
        // Calculate rest of values
        projectile.xPosition(x: &x)
        projectile.xEulerPosition()
        projectile.yEulerPosition()
        
        // Print values
        print(String(format: "%06.3f      %07.2f           %07.3f  |     %07.2f            %07.3f", ((projectile.getTime()*1000).rounded()/1000), ((x*1000).rounded()/1000), abs(((y*1000).rounded()/1000)), ((projectile.getEulerX()*1000).rounded()/1000), ((projectile.getEulerY()*1000).rounded()/1000)))
        
        // Advance time
        projectile.advanceDelta(deltaT: increment)
        
        // If flag is true then we've reached the end and y has reached zero
        if(flag){
            break;
        }
    }
}

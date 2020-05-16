//
//  Projectile.swift
//  Assignment3
//
//  Created by Huda Ali on 2020-03-16.
//  Copyright © 2020 COMP1601. All rights reserved.
//

import Foundation

class Projectile{
    let pi = Double.pi      // Pi value
    let g = -9.81           // Acceleration because of gravity
    var vx = Double(0)      // Horizontal velocity
    var vy = Double(0)      // Vertical velocity
    var eulerX = Double(0)  // Euler x approximation
    var eulerY = Double(0)  // Euler y approximation
    var t = Double(0)       // Time
    
    var angle: Double      // Angle of release
    var velocity: Double   // Velocity
    var height: Double     // Height
    var divisions: Double  // Divisions per second
    
    // Constructor
    init(angle: Double, velocity: Double, height: Double, divisions: Double) {
        self.angle = angle
        self.velocity = velocity
        self.height = height
        self.divisions = divisions
    }
    
    // Getter for Time
    func getTime()-> Double{
        return t
    }
    
    // Getter for Euler approximation of x
    func getEulerX()-> Double{
        return eulerX
    }
    
    // Getter for Euler approximation of y
    func getEulerY()-> Double{
        return eulerY
    }
    
    // Advance time by delta t seconds
    func advanceDelta(deltaT: Double){
        t += deltaT;
    }
    
    // Set time
    func setTime(time: Double){
        t = time
    }
    
    // Set divisions
    func setDivisions(increment: Double){
        divisions = increment
    }
    
    // Calculate horizontal position at time t
    func xPosition(x: inout Double){
        x = ((1/2) * 0 * pow(t,2)) + (velocity * cos(angle * (pi/180)) * t)
    }
    
    // Calculate vertical position at time t
    func yPosition(y: inout Double){
        y = ((1/2) * (g) * pow(t,2)) + (velocity * sin(angle * (pi/180)) * t) + height
    }
    
    // Calculate euler's approximation horizontal position
    func xEulerPosition(){
        
        // At initial time calculate initital values
        if(t==0){
            vx = velocity * cos(angle * (pi/180))
            xPosition(x: &eulerX)
        
        // Use old values to approximate for new ones
        }else{
            eulerX = eulerX + (vx * divisions)
        }
    }
    
    // Calculate euler's approximation vertical position
    func yEulerPosition(){
        
        // At initial time calculate initital values
        if(t==0){
            vy = (velocity * sin(angle * (pi/180))) - (g * divisions)
            yPosition(y: &eulerY)
        
        // Use old values to approximate for new ones
        }else{
            vy = vy + (g * divisions)
            eulerY = eulerY + (vy * divisions)
        }
    }
    
}


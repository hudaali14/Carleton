//
//  DrawView.swift
//  TicTacToe
//
//  Created by Huda Ali on 2020-04-04.
//  Copyright © 2020 COMP1601. All rights reserved.
//

import Foundation
import UIKit

class DrawView: UIView {
    
    var currentLine: Line? // Current second portion of x being drawn
    var currentLine2: Line? // Current first portion of x being drawn
    var currentCircle: Circle? // Current circle being drawn
    var finishedLines = [Line]() // Array of crosses played
    var finishedCircles = [Circle]() //Array of all circles played
    var boxes = [false, false, false, false, false, false, false, false, false] //Whether a spot has been played or not
    var nums = 0; //Number of spots played
    
    @IBInspectable var finishedLineColor: UIColor = UIColor.black {
        didSet {
            setNeedsDisplay()
        }
    }
    @IBInspectable var currentLineColor: UIColor = UIColor.red {
        didSet {
            setNeedsDisplay()
        }
    }
    @IBInspectable var lineThickness: CGFloat = 10 {
        didSet {
            setNeedsDisplay()
        }
    }
    
    //Lines for game
    let line1 = Line(begin: CGPoint(x:10,y:250), end: CGPoint(x:400,y:250));
    let line2 = Line(begin: CGPoint(x:10,y:500), end: CGPoint(x:400,y:500));
    let line3 = Line(begin: CGPoint(x:125,y:75), end: CGPoint(x:125,y:675));
    let line4 = Line(begin: CGPoint(x:275,y:75), end: CGPoint(x:275,y:675));
    
    
    func strokeLine(line: Line){
        //Use BezierPath to draw lines
        let path = UIBezierPath();
        path.lineWidth = lineThickness;
        path.lineCapStyle = CGLineCap.round;
        
        path.move(to: line.begin);
        path.addLine(to: line.end);
        path.stroke(); //actually draw the path
    }
    
    func strokeCircle(circle: Circle){
        //Use BezierPath to draw circle
        let path = UIBezierPath(ovalIn: CGRect(x: circle.centre.x - circle.radius,
                                               y: circle.centre.y - circle.radius,
                                               width: circle.radius*2,
                                               height: circle.radius*2))
        path.lineWidth = 10;
        path.fill()
        path.stroke(); //actually draw the path
    }
    
    override func draw(_ rect: CGRect) {
        
        //draw the finished lines
        finishedLineColor.setStroke() //finished lines in black
        for line in finishedLines{
            strokeLine(line: line);
        }
        
        // Specify a border (stroke) color.
        UIColor.black.setStroke()
        
        //draw the circle
        for circle in finishedCircles{
           strokeCircle(circle: circle);
        }
        
        //Lines for game
        strokeLine(line: line1);
        strokeLine(line: line2);
        strokeLine(line: line3);
        strokeLine(line: line4);
    }
    
    //Override Touch Functions
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        print(#function) //for debugging;
        
        // If game is complete then reset game
        if(nums == 9){
            finishedCircles = [];
            finishedLines = [];
            boxes = [false, false, false, false, false, false, false, false, false]
            nums = 0;
            setNeedsDisplay(); //this view needs to be updated
        
        // Else display X and O tokens
        }else{
            tokens(touches);
        }
    }
    
    override func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
        //print(#function)
        let touch = touches.first!
        let location = touch.location(in: self);
        currentLine?.end = location;
        setNeedsDisplay()
    }
    
    override func touchesEnded(_ touches: Set<UITouch>, with event: UIEvent?) {
        print(#function)
        if var newLine = currentLine {
            let touch = touches.first!;
            let location = touch.location(in: self);
            newLine.end = location;
            //add to the array of lines
            finishedLines.append(newLine);
        }
        currentLine = nil;
        setNeedsDisplay()
    }
    
    override func touchesCancelled(_ touches: Set<UITouch>?, with event: UIEvent?) {
        print(#function)
        currentLine = nil;
        setNeedsDisplay();
    }
    
    // Displays X and Y tokens
    func tokens(_ touches: Set<UITouch>){
        let touch = touches.first!
        let location = touch.location(in: self);
        
        
        // There is alot of repeated lines of code in this portion
        // but since each box is dependent of one another and we need to check
        // whether each location has already been taken
        // so putting a portion of the code in a function wouldn't change the redunancy
        // This portion checks if the box has already been taken
        if(location.y > line1.begin.y){
            if(location.y > line2.begin.y){
                if(location.x > line3.begin.x){
                    if(location.x > line4.begin.x){
                        if(boxes[8] == true){
                            return;
                        }
                        boxes[8] = true;
                    }else{
                        if(boxes[7] == true){
                            return;
                        }
                        boxes[7] = true;
                    }
                }else{
                    if(boxes[6] == true){
                        return;
                    }
                    boxes[6] = true;
                }
            }else{
                if(location.x > line3.begin.x){
                    if(location.x > line4.begin.x){
                        if(boxes[5] == true){
                            return;
                        }
                        boxes[5] = true;
                    }else{
                        if(boxes[4] == true){
                            return;
                        }
                        boxes[4] = true;
                    }
                }else{
                    if(boxes[3] == true){
                        return;
                    }
                    boxes[3] = true;
                }
            }
        }else{
            if(location.x > line3.begin.x){
                if(location.x > line4.begin.x){
                    if(boxes[2] == true){
                        return;
                    }
                    boxes[2] = true;
                }else{
                    if(boxes[1] == true){
                        return;
                    }
                    boxes[1] = true;
                }
            }else{
                if(boxes[0] == true){
                    return;
                }
                boxes[0] = true;
            }
        }
        
        // Chooses between X and O tokens
        if(nums % 2 != 0){
            let newCircle = Circle(centre: location, radius:CGFloat(15));
            finishedCircles.append(newCircle);
        }else{
            let newline1 = Line(begin: CGPoint(x:location.x-15,y:location.y-15), end: CGPoint(x:location.x+15,y:location.y+15));
            let newline2 = Line(begin: CGPoint(x:location.x+15,y:location.y-15), end: CGPoint(x:location.x-15,y:location.y+15));
            finishedLines.append(newline1);
            finishedLines.append(newline2);
        }
        
        // Increases nums and displays
        nums += 1;
        setNeedsDisplay();
    }
}

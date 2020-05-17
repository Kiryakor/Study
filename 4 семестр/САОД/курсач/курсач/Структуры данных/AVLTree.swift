//
//  AVLTree.swift
//  курсач
//
//  Created by Кирилл on 26.04.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation

//MARK: tree
public class AVLTree {
    internal var root: AVLNode?
    init() { }

    func insert(value: Flight) {
        if let root = self.root {
            self.root = root.insert(value)
        } else {
            self.root = AVLNode(value)
        }
    }
    
    func remove(value: String) {
        guard let root = self.root else { return } 
        self.root = root.remove(value)
    }
    
    func removeAllData(){
        for i in values{
            remove(value: i.number)
        }
    }

    var isEmpty: Bool { return self.root == nil }
    
    var values: [Flight] {
        guard let root = self.root else { return [] }
        var result: [Flight] = []
        root.preorderTraversal { result.append($0) }
        return result
    }
        
    func searchBM(to:String) -> [Flight]{
        var result: [Flight] = []
        for value in values{
            if value.to.searchBM(pattern: to) != nil{
                result.append(value)
            }
        }
        return result
    }
    
    func freePlace(company:String) -> Bool {
        for i in values{
            if i.number == company{
                if i.countFree > 0 { return true }
                else { return false }
            }
        }
        return false
    }
    
    func minusFreePlace(number:String){
        self.root?.preorderTraversalFree(number: number)
    }
}

internal class AVLNode{
    var height: Int = 1
    var value: Flight
    var left, right: AVLNode?
        
    var balance: Int {
        return self.leftHeight - self.rightHeight
    }
    
    var leftHeight: Int {
        return self.left?.height ?? 0
    }
    
    var rightHeight: Int {
        return self.right?.height ?? 0
    }
        
    init(_ value: Flight) {
        self.value = value
    }

    private func rotateRight() -> AVLNode {
        let b = self.left!
        self.left = b.right
        b.right = self
        self.recalculateHeight()
        b.recalculateHeight()
        return b
    }
    
    private func rotateLeft() -> AVLNode {
        let b = self.right!
        self.right = b.left
        b.left = self
        self.recalculateHeight()
        b.recalculateHeight()
        return b
    }
    
    private func rotateLeftRight() -> AVLNode {
        self.left = self.left!.rotateLeft()
        self.recalculateHeight()
        return self.rotateRight()
    }

    private func rotateRightLeft() -> AVLNode {
        self.right = self.right!.rotateRight()
        self.recalculateHeight()
        return self.rotateLeft()
    }

    private func recalculateHeight() {
        self.height = 1 + max(self.leftHeight, self.rightHeight)
    }

    internal func insert(_ value: Flight) -> AVLNode {
        defer { self.recalculateHeight() }
        if value.number < self.value.number {
            if let left = self.left {
                self.left = left.insert(value)
                return self.rebalanceIfNeeded()
            } else {
                self.left = AVLNode(value)
                return self
            }
        } else {
            if let right = self.right {
                self.right = right.insert(value)
                return self.rebalanceIfNeeded()
            } else {
                self.right = AVLNode(value)
                return self
            }
        }
    }
    
    private func removeLeftmostNode() -> AVLNode {
        guard let left = self.left else {
            assertionFailure("this only works on nodes with a left child")
            return self
        }
        defer { self.recalculateHeight() }
        if let _ = left.left {
            let result = left.removeLeftmostNode()
            self.left = left.rebalanceIfNeeded()
            return result
        }
        self.left = left.right
        return left
    }
    
    private func rebalanceIfNeeded() -> AVLNode {
        let balance = self.balance
        if balance > 1 {
            if let leftBalance = self.left?.balance, leftBalance > 0 {
                return self.rotateRight()
            } else {
                return self.rotateLeftRight()
            }
        } else if balance < -1 {
            if let rightBalance = self.right?.balance, rightBalance < 0 {
                return self.rotateLeft()
            } else {
                return self.rotateRightLeft()
            }
        }
        return self
    }
    
    internal func remove(_ value: String) -> AVLNode? {
        if value < self.value.number, let left = self.left {
            self.left = left.remove(value)
            self.recalculateHeight()
            return self.rebalanceIfNeeded()
        } else if value > self.value.number, let right = self.right {
            self.right = right.remove(value)
            self.recalculateHeight()
            return self.rebalanceIfNeeded()
        }
        if let right = self.right {
            let sucessor: AVLNode
            if let _ = right.left {
                sucessor = right.removeLeftmostNode()
                self.right = right.rebalanceIfNeeded()
                sucessor.left = self.left
                sucessor.right = self.right
            } else {
                sucessor = right
                sucessor.left = self.left
            }
            sucessor.recalculateHeight()
            return sucessor.rebalanceIfNeeded()
        } else if let left = self.left {
            return left
        }
        return nil
    }
    
    //обратный проход дерева
    internal func preorderTraversal(_ callback: (Flight) -> Void) {
        self.left?.preorderTraversal(callback)
        self.right?.preorderTraversal(callback)
        callback(self.value)
    }
    
    internal func preorderTraversalFree(number:String) {
        self.left?.preorderTraversalFree(number: number)
        self.right?.preorderTraversalFree(number: number)
        if self.value.number == number{
            self.value.countFree -= 1
            return
        }
      }
    
    internal func preorderTraversalAndSearchBM(to:String,_ callback: (Flight) -> Void) {
        self.left?.preorderTraversal(callback)
        self.right?.preorderTraversal(callback)
        print(self.value.to.searchBM(pattern: to))
        if (self.value.to.searchBM(pattern: to) != nil){
            callback(self.value)
        }
    }
}

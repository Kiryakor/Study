//
//  main.swift
//  саод
//
//  Created by Кирилл on 25.04.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation

//MARK: пассажиры
struct Passenger {
    var passport:String? //NNNN-NNNNNN проверка формата
    var place:String?
    var fio:String?
    var date:String?
    
    init() {
        self.passport = nil
        self.place = nil
        self.fio = nil
        self.date = nil
    }
    
    init(passport:String,place:String,fio:String,data:String) {
        self.passport = passport
        self.place = place
        self.fio = fio
        self.date = data
    }
    
    func checkData() -> Bool{
        let dateFormatter = DateFormatter()
        dateFormatter.dateFormat = "yyyy-MM-dd"
        guard let date = date, let _ = dateFormatter.date(from:date) else { return false}
        return true
    }
    
    func checkPassport() -> Bool{
        guard let passport = passport, passport.count == 11 else { return false }
        var count = 0
        for i in passport{
            if i != "-", count == 4 { return false }
            if !i.isNumber, count != 4 { return false }
            count += 1
        }
        return true
    }
}

//MARK: хеш таблица
class HashTable{
    var data:[Passenger] = []
    
    private var sizeData:Int{
        get{ return data.count }
    }
    
    init() { uppendNilData() }
    
    private func uppendNilData(){
        for _ in 0..<1500{ data.append(Passenger()) }
    }
    
    private func hash(newValue:String) -> Int {
        return abs(newValue.hashValue % data.count)
    }
    
    func newElement(passenger:Passenger){
        var index = hash(newValue: passenger.passport!)
        let c = 2, d = 5
        var tryCount = 0,check = true
        while check {
            index += c*tryCount + d*(tryCount^2)
            while index > sizeData { uppendNilData() }
            if data[index].passport == nil{
                data[index] = passenger
                check = false
            }
            tryCount += 1
        }
    }
    
    func removeElement(index:Int){
        guard index>0, index<sizeData else { return }
        data[index] = Passenger()
    }
}

//MARK: авиарейсы
struct Flight {
    var number:String //«AAA-NNN», где AAA – код авиакомпании (буквы латиницы), NNN – порядковый номер авиарейса (цифры);
    var company:String
    var from:String
    var to:String
    var date:String
    var time:String
    var count:Int
    var countFree:Int
    
    func checkNumber() -> Bool {
        guard number.count == 7 else { return false}
        var count = 0
        for i in number{
            if count < 3 && !i.isSymbol { return false }
            if count == 3 && i != "-" { return false }
            if count > 4 && !i.isNumber { return false }
            count += 1
        }
        return true
    }
}

//MARK: tree
// https://github.com/hfutrell/AVLTree/blob/master/AVLTree/AVLTree.swift
public class AVLTree {
    internal var root: AVLNode?
    /// creates an empty AVL Tree
    init() { }
    /// inserts a value into the tree
    /// - Parameter value: the value to be inserted
    func insert(value: Flight) {
        if let root = self.root {
            self.root = root.insert(value)
        } else {
            self.root = AVLNode(value)
        }
    }
    
    /// removes a single occurrence of a value from the tree
    /// - Parameter value: the element to be removed
    func remove(value: Flight) {
        guard let root = self.root else { return } // nothing to do
        self.root = root.remove(value)
    }
    
    /// A Boolean value that indicates whether the tree is empty
    var isEmpty: Bool { return self.root == nil }
    /// An ordered collection of the entries contained in the tree.
    
    var values: [Flight] {
        guard let root = self.root else { return [] }
        var result: [Flight] = []
        root.preorderTraversal { result.append($0) }
        return result
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
    
    internal func remove(_ value: Flight) -> AVLNode? {
        if value.number < self.value.number, let left = self.left {
            self.left = left.remove(value)
            self.recalculateHeight()
            return self.rebalanceIfNeeded()
        } else if value.number > self.value.number, let right = self.right {
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
}



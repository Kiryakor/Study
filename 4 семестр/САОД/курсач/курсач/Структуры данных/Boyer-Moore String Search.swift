//
//  Boyer-Moore String Search.swift
//  курсач
//
//  Created by Кирилл on 28.04.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation

extension String {
    func searchBM(pattern: String) -> Index? {
        let patternLength = pattern.count
        guard patternLength > 0, patternLength <= count else { return nil }

        var skipTable = [Character: Int]()
        for (i, c) in pattern.enumerated() {
            skipTable[c] = patternLength - i - 1
        }

        let p = pattern.index(before: pattern.endIndex)
        let lastChar = pattern[p]

        var i = index(startIndex, offsetBy: patternLength - 1)

        func backwards() -> Index? {
            var q = p
            var j = i
            while q > pattern.startIndex {
                j = index(before: j)
                q = index(before: q)
                if self[j] != pattern[q] { return nil }
            }
            return j
        }

        while i < endIndex {
            let c = self[i]
            if c == lastChar {
                if let k = backwards() { return k }
                let jumpOffset = max(skipTable[c] ?? patternLength, 1)
                i = index(i, offsetBy: jumpOffset, limitedBy: endIndex) ?? endIndex
            } else {
                i = index(i, offsetBy: skipTable[c] ?? patternLength, limitedBy: endIndex) ?? endIndex
            }
        }
        return nil
    }
}

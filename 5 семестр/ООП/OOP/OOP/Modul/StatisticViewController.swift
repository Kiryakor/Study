//
//  StatisticViewController.swift
//  OOP
//
//  Created by Кирилл on 25.10.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class StatisticViewController: UIViewController {

    @IBOutlet weak var statisticView: UIView!
    @IBOutlet weak var segmentControl: UISegmentedControl!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        statisticView.backgroundColor = .green
        segmentControl.addTarget(self, action: #selector(chengeValue), for: .valueChanged)
    }
    
    @objc func chengeValue(){
        switch segmentControl.selectedSegmentIndex {
        case 0:
            statisticView.backgroundColor = .green
        case 1:
            statisticView.backgroundColor = .red
        default:
            break
        }
    }
}

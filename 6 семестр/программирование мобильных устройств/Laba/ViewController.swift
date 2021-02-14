//
//  ViewController.swift
//  Laba
//
//  Created by Kirill on 12.02.2021.
//

import UIKit

class ViewController: UIViewController {

    
    @IBOutlet weak var mySwitch: UISwitch!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        mySwitch.addTarget(self, action: #selector(switchAction), for: .allEvents)
    }
    
    @objc
    func switchAction() {
        
    }
}


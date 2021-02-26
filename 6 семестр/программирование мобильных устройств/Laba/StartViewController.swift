//
//  StartViewController.swift
//  Laba
//
//  Created by Kirill on 14.02.2021.
//

import UIKit

class StartViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    @IBAction func showSecondVC(_ sender: UIButton) {
        present(SecondViewController(), animated: true, completion: nil)
    }
    
    
    @IBAction func showLighteVC(_ sender: UIButton) {
        present(LighteViewController(), animated: true, completion: nil)
    }
}

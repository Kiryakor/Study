//
//  DetailPersonController.swift
//  OOP
//
//  Created by Кирилл on 01.11.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class DetailPersonController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .edit, target: self, action: #selector(editProfile))
    }
    
    @objc func editProfile(){}
}

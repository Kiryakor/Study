//
//  PickerViewController.swift
//  OOP
//
//  Created by Кирилл on 14.11.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class PickerPresenter {
    var data = StatisticSingelton.share
    var active = 0
}

class PickerController: UIViewController, UIPickerViewDelegate, UIPickerViewDataSource  {
    
    var presenter = PickerPresenter()
    @IBOutlet weak var picker: UIPickerView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.picker.delegate = self
        self.picker.dataSource = self
        title = "Выберите район"
        
        navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .save, target: self, action: #selector(add))
    }
    
    @objc func add(){
        presenter.data.count[presenter.active] += 1
        let date = Date()
        let calendar = Calendar.current
        let weekday = calendar.component(.weekday, from: date)
        if weekday == 1{
            presenter.data.weekday[6] += 1
        }else {
            presenter.data.weekday[weekday-2] += 1
        }
        let alert = UIAlertController(title: "Пациент успешно записан", message: nil, preferredStyle: .actionSheet)
        let action = UIAlertAction(title: "ok", style: .default)
        alert.addAction(action)
        self.present(alert,animated: true)
    }
    
    func numberOfComponents(in pickerView: UIPickerView) -> Int{
        return 1
    }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return presenter.data.pickerData.count
    }
    
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        return presenter.data.pickerData[row]
    }
    
    func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        presenter.active = row
    }
}

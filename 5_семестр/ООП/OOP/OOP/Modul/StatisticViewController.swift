//
//  StatisticViewController.swift
//  OOP
//
//  Created by Кирилл on 25.10.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class StatisticViewController: UIViewController {

    enum presentDATA{
        case rayon
        case day
    }
    
    let statisticData = StatisticSingelton.share
    @IBOutlet weak var talbeView: UITableView!
    @IBOutlet weak var segmentControl: UISegmentedControl!
    var presentData: presentDATA = .rayon
    
    override func viewDidLoad() {
        super.viewDidLoad()
        talbeView.delegate = self
        talbeView.dataSource = self
        talbeView.tableFooterView = UIView()
        talbeView.rowHeight = 60
        segmentControl.addTarget(self, action: #selector(chengeValue), for: .valueChanged)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        talbeView.reloadData()
    }
    
    @objc func chengeValue(){
        switch segmentControl.selectedSegmentIndex {
        case 0:
            presentData = .rayon
        case 1:
            presentData = .day
        default:
            break
        }
        talbeView.reloadData()
    }
}

extension StatisticViewController: UITableViewDelegate, UITableViewDataSource{
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        switch presentData {
        case .day:
            return statisticData.weekday.count
        case .rayon:
            return statisticData.pickerData.count
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "celll", for: indexPath)
        switch presentData {
        case .rayon:
            cell.textLabel?.text = String(statisticData.pickerData[indexPath.row] + " - " + String(statisticData.count[indexPath.row]))
        case .day:
            cell.textLabel?.text = String(statisticData.day[indexPath.row] + " - " + String(statisticData.weekday[indexPath.row]))
        }
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
    }
}

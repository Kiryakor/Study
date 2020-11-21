//
//  StatisticViewController.swift
//  OOP
//
//  Created by Кирилл on 25.10.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class StatisticPresenter {
    enum presentDATA{
        case rayon
        case day
    }
    
    let statisticData = StatisticSingelton.share
    var presentData: presentDATA = .rayon
}

class StatisticController: UIViewController {

    @IBOutlet weak var talbeView: UITableView!
    @IBOutlet weak var segmentControl: UISegmentedControl!
    
    var presenter = StatisticPresenter()
    
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
            presenter.presentData = .rayon
        case 1:
            presenter.presentData = .day
        default:
            break
        }
        talbeView.reloadData()
    }
}

extension StatisticController: UITableViewDelegate, UITableViewDataSource{
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        switch presenter.presentData {
        case .day:
            return presenter.statisticData.weekday.count
        case .rayon:
            return presenter.statisticData.pickerData.count
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "celll", for: indexPath)
        switch presenter.presentData {
        case .rayon:
            cell.textLabel?.text = String(presenter.statisticData.pickerData[indexPath.row] + " - " + String(presenter.statisticData.count[indexPath.row]))
        case .day:
            cell.textLabel?.text = String(presenter.statisticData.day[indexPath.row] + " - " + String(presenter.statisticData.weekday[indexPath.row]))
        }
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
    }
}

//
//  DoctorsViewController.swift
//  OOP
//
//  Created by Кирилл on 25.10.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class DoctorsController: UIViewController {

    var tableView: UITableView!{
        didSet{
            tableView.delegate = self
            tableView.dataSource = self
            tableView.register(DoctorsCell.self, forCellReuseIdentifier: Constant.Cell.cellId(.dostors)())
            tableView.tableFooterView = UIView()
            tableView.rowHeight = 80
        }
    }
    
    lazy private(set) var a:Int = 5
    
    var data: [DoctorsModel] = [DoctorsModel(name: "ivan", soname: "Petrov", profession: "doctor", image: UIImage(systemName: "table")!)]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setupTable()
        
        
        let session = URLSession.shared.dataTask(with: URL(string: "")!) { (data, response, erroo) in
            guard let httpStatus = response as? HTTPURLResponse, httpStatus.statusCode == 200 else { return }
        }
    
        session.resume()
    }
}

extension DoctorsController: UITableViewDelegate, UITableViewDataSource{
    
    func setupTable() {
        tableView = UITableView(frame: view.frame)
        view.addSubview(tableView)
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        data.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: Constant.Cell.cellId(.dostors)(), for: indexPath) as! DoctorsCell
        cell.setValue(data: data[indexPath.row])
        return cell
    }
}

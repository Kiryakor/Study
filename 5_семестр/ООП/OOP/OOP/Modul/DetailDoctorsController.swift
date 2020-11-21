//
//  DetailDoctorsController.swift
//  OOP
//
//  Created by Кирилл on 01.11.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class DetailDoctorsPresenter{
    var index: Int!
    var data = DoctorsSingelton.share
    var patient = PatientSingelton.share
}

class DetailDoctorsController: UIViewController {

    @IBOutlet weak var collectionView: UICollectionView!
    @IBOutlet weak var fullName: UILabel!
    @IBOutlet weak var personImage: UIImageView!
    @IBOutlet weak var profession: UILabel!
    var presenter = DetailDoctorsPresenter()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        title = "Доктор"
        navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .edit, target: self, action: #selector(editProfiel))
    }
    
    override func viewWillAppear(_ animated: Bool) {
        collectionView.reloadData()
        fullName.text = presenter.data.data[presenter.index].fullName
        personImage.image = presenter.data.data[presenter.index].image
        profession.text = presenter.data.data[presenter.index].profession
    }
    
    @objc func editProfiel(){
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        let vc = storyboard.instantiateViewController(withIdentifier: "EditPeopleViewController") as! EditDoctorsController
        vc.presenter.index = self.presenter.index
        navigationController?.pushViewController(vc,animated: true)
    }
}

extension DetailDoctorsController: UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout{
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        presenter.data.data[presenter.index].doctorHistory.count
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "detailCell", for: indexPath) as! BaseCollectionCell
        cell.setupUI(data: presenter.data.data[presenter.index].doctorHistory[indexPath.row] as! PeopleModel)
        cell.layer.cornerRadius = 10
        cell.clipsToBounds = true
        cell.backgroundColor = #colorLiteral(red: 0.8039215803, green: 0.8039215803, blue: 0.8039215803, alpha: 1)
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize{
        let size = (view.bounds.width - 42) / 2
        return CGSize(width: size, height: size)
    }
}

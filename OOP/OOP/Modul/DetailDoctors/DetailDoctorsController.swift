//
//  DetailDoctorsController.swift
//  OOP
//
//  Created by Кирилл on 01.11.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class DetailDoctorsController: UIViewController {

    @IBOutlet weak var collectionView: UICollectionView!
    @IBOutlet weak var fullName: UILabel!
    @IBOutlet weak var personImage: UIImageView!
    @IBOutlet weak var profession: UILabel!
    @IBOutlet weak var workLabel: UILabel!
    var index: Int!
    var data = DoctorsSingelton.share
    
    override func viewDidLoad() {
        super.viewDidLoad()
        title = "Доктор"
        fullName.text = data.data[index].fullName
        personImage.image = data.data[index].image
        profession.text = data.data[index].profession
        navigationItem.rightBarButtonItems = [UIBarButtonItem(barButtonSystemItem: .edit, target: self, action: #selector(editProfiel)),
                                              UIBarButtonItem(barButtonSystemItem: .add, target: self, action: #selector(addProfiel))]
    }
    
    @objc func editProfiel(){}
    @objc func addProfiel(){
        //MARK: - запись нового чела
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        let vc = storyboard.instantiateViewController(withIdentifier: "writePacientVC") as! WriteNewPatientController
        navigationController?.pushViewController(vc,animated: true)
    }
}

extension DetailDoctorsController: UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout{
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        10
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "detailCell", for: indexPath)
        cell.backgroundColor = .red
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize{
        let size = (view.bounds.width - 42) / 2
        return CGSize(width: size, height: size)
    }
}

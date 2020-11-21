//
//  EditPeopleViewController.swift
//  OOP
//
//  Created by Кирилл on 08.11.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class EditDoctorsPresenter {
    var data = DoctorsSingelton.share
    var index:Int!
}

class EditDoctorsController: UIViewController {

    var presenter = EditDoctorsPresenter()
    
    @IBOutlet weak var nameTextField: UITextField!
    @IBOutlet weak var sonameTextField: UITextField!
    @IBOutlet weak var proffessionTextField: UITextField!
    @IBOutlet weak var professionLabel: UILabel!
    @IBOutlet weak var peopleImageView: UIImageView!
    var imageTapGestureRecognizer: UITapGestureRecognizer!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        title = "Редактирование данных"
        imageTapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(tapPersonImageView))
        peopleImageView.addGestureRecognizer(imageTapGestureRecognizer)
        nameTextField.text = presenter.data.data[presenter.index].name
        sonameTextField.text = presenter.data.data[presenter.index].soname
        proffessionTextField.text = presenter.data.data[presenter.index].profession
        peopleImageView.image = presenter.data.data[presenter.index].image
        navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .save, target: self, action: #selector(saveAction))
    }
    
    @objc func tapPersonImageView(){
        alertImage()
    }
    
    @objc func saveAction(){
        presenter.data.data[presenter.index].image = peopleImageView.image!
        presenter.data.data[presenter.index].name = nameTextField.text!
        presenter.data.data[presenter.index].soname = sonameTextField.text!
        presenter.data.data[presenter.index].profession = proffessionTextField.text!
        self.navigationController?.popViewController(animated: true)
    }
}

//MARK: Load Photo
extension EditDoctorsController: UIImagePickerControllerDelegate, UINavigationControllerDelegate{
    private func alertImage(){
        let alert = UIAlertController(title: nil, message: "Выберите способ загрузки израбражения", preferredStyle: .alert)
        let cameraAction = UIAlertAction(title: "Сamera", style: .default) { (action) in
            self.chooseImage(sourse: .camera)
        }

        let photoLibAction = UIAlertAction(title: "Галерея ", style: .default) { (action) in
            self.chooseImage(sourse: .photoLibrary)
        }
        let cancelAction = UIAlertAction(title: "Cancel", style: .cancel, handler: nil)
        alert.addAction(cameraAction)
        alert.addAction(photoLibAction)
        alert.addAction(cancelAction)
        self.present(alert,animated: true,completion: nil)
    }
    
    private func chooseImage(sourse:UIImagePickerController.SourceType){
        if UIImagePickerController.isSourceTypeAvailable(sourse){
            let imagePicker = UIImagePickerController()
            imagePicker.delegate = self
            imagePicker.allowsEditing = true
            imagePicker.sourceType = sourse
            self.present(imagePicker,animated: true,completion: nil)
        }
    }
    
    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [UIImagePickerController.InfoKey : Any]) {
        peopleImageView!.image = info[UIImagePickerController.InfoKey.editedImage] as? UIImage
        peopleImageView?.contentMode = .scaleAspectFit
        peopleImageView.clipsToBounds = true
        dismiss(animated: true, completion: nil)
    }
}

//
//  EditPatientViewController.swift
//  OOP
//
//  Created by Кирилл on 08.11.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class EditPatientViewController: UIViewController {

    @IBOutlet weak var peopleImageView: UIImageView!
    @IBOutlet weak var infoTextField: UITextField!
    @IBOutlet weak var sonameTextField: UITextField!
    @IBOutlet weak var nameTextField: UITextField!
    var imageTapGestureRecognizer: UITapGestureRecognizer!
    
    var data = PatientSingelton.share
    var index:Int!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        title = "Изменение данных"
    }
    
    override func viewWillAppear(_ animated: Bool) {
        imageTapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(tapPersonImageView))
        peopleImageView.addGestureRecognizer(imageTapGestureRecognizer)
        peopleImageView.image = data.data[index].image
        infoTextField.text = data.data[index].profession
        nameTextField.text = data.data[index].name
        sonameTextField.text = data.data[index].soname
        navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .save, target: self, action: #selector(saveAction))
    }
    
    @objc func tapPersonImageView(){
        alertImage()
    }
    
    @objc func saveAction(){
        data.data[index].image = peopleImageView.image!
        data.data[index].name = nameTextField.text!
        data.data[index].soname = sonameTextField.text!
        self.navigationController?.popViewController(animated: true)
    }
}

//MARK: Load Photo
extension EditPatientViewController: UIImagePickerControllerDelegate, UINavigationControllerDelegate{
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

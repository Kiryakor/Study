//
//  AddNewPeopleController.swift
//  OOP
//
//  Created by Кирилл on 31.10.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

enum StateAddPeople {
    case patient
    case doctor
}

class AddNewPeopleController: UIViewController {
    
    @IBOutlet weak var addImageView: UIImageView!
    @IBOutlet weak var nameTextField: UITextField!
    @IBOutlet weak var somaneTextField: UITextField!
    @IBOutlet weak var professionTextField: UITextField!
    @IBOutlet weak var someHelpersLabel: UILabel!
    var imageTapGestureRecognizer: UITapGestureRecognizer!
    
    var doctorSingelton = DoctorsSingelton.share
    var patientSingelton = PatientSingelton.share
    var stateAddPeople: StateAddPeople!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        imageTapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(tapPersonImageView))
        addImageView.addGestureRecognizer(imageTapGestureRecognizer)
        
        switch stateAddPeople {
        case .doctor:
            someHelpersLabel.text = "Профессия"
            professionTextField.isHidden = false
        case .patient:
            someHelpersLabel.text = "Что-то для человека"
            professionTextField.isHidden = false
        case .none:
            someHelpersLabel.text = ""
            professionTextField.isHidden = true
        }
    }
    
    @IBAction func saveButton(_ sender: UIBarButtonItem) {
        guard nameTextField.text != "", somaneTextField.text != "", professionTextField.text != "" else { return }
        switch stateAddPeople {
        case .doctor:
            doctorSingelton.data.append(PeopleModel(name: nameTextField.text!, soname: somaneTextField.text!, profession: professionTextField.text!, image: addImageView.image!, data: Date()))
        case .patient:
            patientSingelton.data.append(PeopleModel(name: nameTextField.text!, soname: somaneTextField.text!, profession: professionTextField.text!, image: addImageView.image!, data: Date()))
        case .none:
            break
        }
        navigationController?.popViewController(animated: true)
    }
    
    @objc func tapPersonImageView(){
        alertImage()
    }
}

//MARK: Load Photo
extension AddNewPeopleController: UIImagePickerControllerDelegate, UINavigationControllerDelegate{
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
        addImageView!.image = info[UIImagePickerController.InfoKey.editedImage] as? UIImage
        addImageView?.contentMode = .scaleAspectFit
        addImageView.clipsToBounds = true
        dismiss(animated: true, completion: nil)
    }
}

//
//  ViewController.swift
//  Practika
//
//  Created by Кирилл on 09.07.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    //MARK:Var
    @IBOutlet weak var mainImageView: UIImageView!
    @IBOutlet weak var degreeSlider: UISlider!
    @IBOutlet weak var saveButton: UIButton!
    @IBOutlet weak var degreeLabel: UILabel!
    var mainImageTapGestureRecognizer:UITapGestureRecognizer!

    //MARK:Lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
        setup()
    }
    
    //MARL:Action
    @IBAction func saveButton(_ sender: UIButton) {
        Sharing.share(on: self,image: mainImageView.image)
    }
    
    @objc func didChangeSlider(){
        degreeLabel.text = String(Int(degreeSlider.value))
    }
    
    @objc func tapMainImageView(){
        alertImage()
    }
}

extension ViewController{
    private func setup(){
        degreeLabel.text = "\(Int(degreeSlider.value))"
        degreeSlider.addTarget(self, action: #selector(didChangeSlider), for: .valueChanged)
        
        mainImageTapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(tapMainImageView))
        mainImageView.addGestureRecognizer(mainImageTapGestureRecognizer)
    }
}

//MARK: Load Photo
extension ViewController: UIImagePickerControllerDelegate, UINavigationControllerDelegate{
    private func alertImage(){
        let alert = UIAlertController(title: nil, message: "Выберите способ загрузки израбражения", preferredStyle: .alert)
        let cameraAction = UIAlertAction(title: "camera", style: .default) { (action) in
            self.chooseImage(sourse: .camera)
        }
        let photoLibAction = UIAlertAction(title: "photo", style: .default) { (action) in
            self.chooseImage(sourse: .photoLibrary)
        }
        let cancelAction = UIAlertAction(title: "cancel", style: .cancel, handler: nil)
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
    
    //для установление фото из загруженной фото
    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [UIImagePickerController.InfoKey : Any]) {
        mainImageView.image = info[UIImagePickerController.InfoKey.editedImage] as? UIImage
        mainImageView.contentMode = .scaleAspectFill
        mainImageView.clipsToBounds = true
        dismiss(animated: true, completion: nil)
    }
}

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
    var startPossitionImageView:CGAffineTransform = CGAffineTransform()
    var flagImageStart:Bool = false
    
    //MARK:Lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
        setup()
    }
    
    //MARK:Action
    @IBAction func saveButton(_ sender: UIButton) {
        let image = makeScreenshot()
        Sharing.share(on: self,image: image)
    }
    
    @objc func EndChangeSlider(){
        UIImageView.animate(withDuration: 1, animations: {
            self.mainImageView.transform = self.mainImageView.transform.rotated(by: CGFloat(self.degreeSlider.value) * .pi / 180 )
        })
    }

    @objc func ChangeSlider(){
        degreeLabel.text = String(Int(degreeSlider.value))
    }
    
    @objc func tapMainImageView(){
        if flagImageStart{
            UIImageView.animate(withDuration: 1, animations: {
                self.mainImageView.transform = self.startPossitionImageView
            })
            UISlider.animate(withDuration: 1) {
                self.degreeSlider.value = 0
            }
            degreeLabel.text = "0"
            DispatchQueue.main.asyncAfter(deadline: .now() + .seconds(1)) {
                self.alertImage()
            }
        }else{
            alertImage()
            flagImageStart = true
        }
    }
}

//MARK: Helpers func
extension ViewController{
    private func setup(){
        degreeLabel.text = "\(Int(degreeSlider.value))"
        degreeSlider.addTarget(self, action: #selector(EndChangeSlider), for: .touchUpInside)
        degreeSlider.addTarget(self, action: #selector(ChangeSlider), for: .valueChanged)
        
        mainImageTapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(tapMainImageView))
        mainImageTapGestureRecognizer.numberOfTapsRequired = 2
        mainImageView.addGestureRecognizer(mainImageTapGestureRecognizer)
        
        startPossitionImageView = self.mainImageView.transform
        
        saveButton.alpha = 0
        saveButton.isHidden = false
    }
    
    private func makeScreenshot() -> UIImage{
        UIGraphicsBeginImageContextWithOptions(CGSize(width: view.bounds.width,height: view.bounds.width),false,0)
        self.view.drawHierarchy(in: view.bounds, afterScreenUpdates: true)
        let image:UIImage = UIGraphicsGetImageFromCurrentImageContext()!
        UIGraphicsEndImageContext()
        
        return image
    }
}

//MARK: Load Photo
extension ViewController: UIImagePickerControllerDelegate, UINavigationControllerDelegate{
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
        mainImageView.image = info[UIImagePickerController.InfoKey.editedImage] as? UIImage
        mainImageView.contentMode = .scaleAspectFit
        mainImageView.clipsToBounds = true
        dismiss(animated: true, completion: nil)
        DispatchQueue.main.asyncAfter(deadline: .now() + .seconds(1)) {
            UIButton.animate(withDuration: 1) {
                self.saveButton.alpha = 1
                self.saveButton.isHidden = false
            }
        }
    }
}

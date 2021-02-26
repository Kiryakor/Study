//
//  ViewController.swift
//  Laba
//
//  Created by Kirill on 12.02.2021.
//

import UIKit
import AVFoundation

class LighteViewController: UIViewController,
UIImagePickerControllerDelegate,
UINavigationControllerDelegate {

    
    @IBOutlet weak var mySwitch: UISwitch!
    @IBOutlet weak var myImage: UIImageView!
    let picker = UIImagePickerController()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        mySwitch.addTarget(self, action: #selector(switchAction), for: .allEvents)
        picker.delegate = self
    }
    
    @objc
    func switchAction() {
        guard
            let device = AVCaptureDevice.default(for: AVMediaType.video),
            device.hasTorch
        else { return }
        
        do {
            try device.lockForConfiguration()
            device.torchMode = mySwitch.isOn ? .on : .off
            device.unlockForConfiguration()
        } catch {
            print(error.localizedDescription)
        }
    }
    
    @IBAction func cameraAction(_ sender: UIButton) {
        picker.sourceType = .camera
        self.present(picker, animated: true, completion: nil)
    }
    
    
    @IBAction func gallaryAction(_ sender: UIButton) {
        picker.sourceType = .photoLibrary
        self.present(picker, animated: true, completion: nil)
    }
    
    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [UIImagePickerController.InfoKey : Any]) {
        myImage.image = info[UIImagePickerController.InfoKey.originalImage] as? UIImage
        dismiss(animated: true, completion: nil)
    }
}


//
//  BaseCollectionCell.swift
//  OOP
//
//  Created by Кирилл on 10.11.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class BaseCollectionCell: UICollectionViewCell {
    
    var image: UIImageView = {
        var image = UIImageView()
        image.translatesAutoresizingMaskIntoConstraints = false
        return image
    }()

    var fullName:UILabel = {
        var label =  UILabel()
        label.translatesAutoresizingMaskIntoConstraints = false
        return label
    }()

    var date:UILabel = {
        var label =  UILabel()
        label.translatesAutoresizingMaskIntoConstraints = false
        return label
    }()
    
    func setupUI(data:DoctorModel) {
        image.image = data.image
        fullName.text = data.fullName
        addSubview(image)
        addSubview(fullName)
        addSubview(date)
        
        NSLayoutConstraint.activate([
            image.centerXAnchor.constraint(equalTo: centerXAnchor),
            image.topAnchor.constraint(equalTo: topAnchor, constant: 8),
            image.heightAnchor.constraint(equalToConstant: 100),
            image.widthAnchor.constraint(equalToConstant: 100),
            fullName.centerXAnchor.constraint(equalTo: centerXAnchor),
            fullName.topAnchor.constraint(equalTo: image.bottomAnchor, constant: 8),
            date.centerXAnchor.constraint(equalTo: centerXAnchor),
            date.topAnchor.constraint(equalTo: image.bottomAnchor, constant: 25)
        ])
        
        let formatter1 = DateFormatter()
        formatter1.dateStyle = .long
        date.text = formatter1.string(from: data.data)
    }
}

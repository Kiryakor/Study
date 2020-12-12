//
//  DoctorsCell.swift
//  OOP
//
//  Created by Кирилл on 25.10.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class BasicCell: UITableViewCell {

    var img: UIImageView = {
        var img = UIImageView()
        img.translatesAutoresizingMaskIntoConstraints = false
        return img
    }()
    
    var fullName: UILabel = {
        var fullName = UILabel()
        fullName.translatesAutoresizingMaskIntoConstraints = false
        return fullName
    }()
    
    var profession: UILabel = {
        var profession = UILabel()
        profession.translatesAutoresizingMaskIntoConstraints = false
        return profession
    }()

    override func awakeFromNib() {
        super.awakeFromNib()
        setupUI()
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)
        setupUI()
    }
}

extension BasicCell{
    private func setupUI() {
        addSubview(img)
        NSLayoutConstraint.activate([
            img.leadingAnchor.constraint(equalTo: leadingAnchor,constant: 16),
            img.topAnchor.constraint(equalTo: topAnchor,constant: 8),
            img.bottomAnchor.constraint(equalTo: bottomAnchor,constant: -8),
            img.widthAnchor.constraint(equalToConstant: 60),
        ])
        
        addSubview(fullName)
        NSLayoutConstraint.activate([
            fullName.leadingAnchor.constraint(equalTo: img.trailingAnchor, constant: 8),
            fullName.centerYAnchor.constraint(equalTo: centerYAnchor,constant: 0)
        ])
        
        
        addSubview(profession)
        NSLayoutConstraint.activate([
            profession.leadingAnchor.constraint(equalTo: img.trailingAnchor, constant: 8),
            profession.centerYAnchor.constraint(equalTo: centerYAnchor,constant: -20)
        ])
    }
    
    func setValue(data: DoctorModel) {
        img.image =  data.image
        fullName.text = data.fullName
        profession.text = data.profession
    }
}

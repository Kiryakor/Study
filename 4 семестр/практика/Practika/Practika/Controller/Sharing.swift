//
//  Sharing.swift
//  Practika
//
//  Created by Кирилл on 09.07.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class Sharing {
    static func share(on viewController: UIViewController,image: UIImage?) {
        var toShare = [Any]()
        if let image = image { toShare.append(image) }
        guard toShare.count > 0 else { return }
        let activityViewController = UIActivityViewController(activityItems: toShare, applicationActivities: nil)
        activityViewController.popoverPresentationController?.sourceView = viewController.view
        viewController.present(activityViewController, animated: true, completion: nil)
  }
}

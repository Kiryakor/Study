//
//  LocationViewController.swift
//  Laba
//
//  Created by Kirill on 18.02.2021.
//

import UIKit
import CoreLocation
import MapKit

class LocationViewController: UIViewController,
CLLocationManagerDelegate {
    
    @IBOutlet weak var map: MKMapView!
    var locationManager: CLLocationManager!
    var isCheck = true
    
    override func viewDidLoad() {
        super.viewDidLoad()

        locationManager = CLLocationManager()
        locationManager.delegate = self;
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        locationManager.requestAlwaysAuthorization()
        locationManager.startUpdatingLocation()
        

        view.backgroundColor = .gray
    }

    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        
        let location = locations.last! as CLLocation
        
        let center = CLLocationCoordinate2D(latitude: location.coordinate.latitude, longitude: location.coordinate.longitude)
        let region = MKCoordinateRegion(center: center, span: MKCoordinateSpan(latitudeDelta: 0.01, longitudeDelta: 0.01))
        let annoation = MKPointAnnotation()
        annoation.coordinate = center
        annoation.title = "ТУТ Я"
        if isCheck {
            self.map.addAnnotation(annoation)
            isCheck = false
        }
        self.map.setRegion(region, animated: true)
    }
}

import UIKit

let str = "{\"names\": [\"Bob\", \"Tim\", \"Tina\"]}"
let data = Data(str.utf8)

do {
    // make sure this JSON is in the format we expect
    if let json = try JSONSerialization.jsonObject(with: data, options: []) as? [String: Any] {
        // try to read out a string array
        if let names = json["names"] as? [String] {
            print(names)
        }
    }
} catch let error as NSError {
    print("Failed to load: \(error.localizedDescription)")
}

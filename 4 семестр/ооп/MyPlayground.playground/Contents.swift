import Foundation

struct ListNews:Decodable {
    var code:Int
    var list:[ListNewsInfo]
}

struct ListNewsInfo:Decodable {
    var id:Int
    var title:String
    var date:String
    var shortDescription:String
}

func load(url:String,complition:@escaping(ListNews)->Void)  {
    guard let url:URL = URL(string: url) else {
        print("error")
        return
    }
        
    URLSession.shared.dataTask(with: url) { (data, response, error) in
        print(response)
        guard error == nil, let data = data else {
            print("error")
            return
        }
        guard let BigData = try? JSONDecoder().decode(ListNews.self, from: data) else {
            print("error")
            return
        }
        print(BigData)
        complition(BigData)
    }
}

load(url: "http://testtask.sebbia.com/v1/news/categories") { (t) in
    print(t)
}

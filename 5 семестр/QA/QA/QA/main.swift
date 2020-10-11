
class Main {
    func checkData(data:String) -> Bool {
        for (index, value) in data.enumerated(){
            if (index == 0 || index == data.count - 1),(!value.isNumber){
                return false
            }
            if value.isNumber || value == "+" || value == "*" || value == "/" || value == "-"{
                continue
            } else{
                return false
            }
        }
        return true
    }

    func parseData(data: String, complition: @escaping([Int],[String]) -> Void) {
        var number:[Int] = []
        var action:[String] = []
        var timeNumber = ""
        for i in data{
            if !i.isNumber {
                action.append(String(i))
                if timeNumber != ""{
                    number.append(Int(timeNumber)!)
                    timeNumber = ""
                }
            } else {
                timeNumber += String(i)
            }
        }
        if timeNumber != ""{
            number.append(Int(timeNumber)!)
            timeNumber = ""
        }
        complition(number,action)
    }

    func hardAction(number: [Int],action: [String],complition: @escaping([Int],[String]) -> Void){
        var number = number
        var action = action
        var i = 0
        let check = true
        while check {
            if action[i] == "*"{
                number[i] = number[i] * number[i+1]
                number.remove(at: i+1)
                action.remove(at: i)
                i = 0
            }else if action[i] == "/"{
                number[i] = number[i] / number[i+1]
                number.remove(at: i+1)
                action.remove(at: i)
                i = 0
            }
            i += 1
            if action.count <= i{ break }
        }
        complition(number,action)
    }

    func simpleAction(number: [Int],action: [String]) -> String {
        var number = number
        var action = action
        var i = 0
        while !action.isEmpty {
            if action[i] == "+"{
                number[i] = number[i] + number[i+1]
                number.remove(at: i+1)
                action.remove(at: i)
                i = 0
            }else if action[i] == "-"{
                number[i] = number[i] - number[i+1]
                number.remove(at: i+1)
                action.remove(at: i)
                i = 0
            }
            i += 1
        }
        return String(number[0])
    }



    func start(){
        let data = readLine()!

        if checkData(data: data){
            parseData(data: data) { number, action in
                hardAction(number: number, action: action) { number, action in
                    print(simpleAction(number: number, action: action))
                }
            }
        }else{
            print("Ошибка при вводе данных")
        }

    }
}

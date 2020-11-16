import Foundation

let serialQueue = DispatchQueue(label: "my_serial_queue",attributes: .concurrent)

//Распределить N задач по разным потокам
DispatchQueue.concurrentPerform(iterations: 10) { (_) in
    print(Thread.current)
}


//Отслеживать выполнение задачи
var item = DispatchWorkItem {
    print("task")
}
serialQueue.async(execute: item)
item.cancel() // можно отменить только пока она не начала выполняться
//item.notify выполняется, если дже произошла отмена


//с помощью Operation можно отменять задачу во время выполнения
//можно добавить наблюдателя на какое-то свойство(отмена дейстия к примеру)


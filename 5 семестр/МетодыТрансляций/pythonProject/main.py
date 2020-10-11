from docx2python import docx2python
from enum import Enum
import csv

class ParseEnum(Enum):
    """Перечисление для отслеживания таблицы, которая парсится в данный момент"""
    header = 1
    body = 2
    bottom = 3
    notGood = 4

class Header:
    """Класс для хранения свойств первой таблицы"""
    def __init__(self, water="", date="", station="", depth="", temperature="", alpha="", author=""):
        self.water = water
        self.date = date
        self.station = station
        self.depth = depth #глубина
        self.temperature = temperature
        self.alpha = alpha
        self.author = author

class Takson:
    """Класс для хранения свойств 2 и 3 таблицы"""
    def __init__(self, takson, counter, bioMassa, percentCounter, percentBioMassa):
        self.takson = takson
        self.counter = counter
        self.bioMassa = bioMassa
        self.percentCounter = percentCounter
        self.percentBioMassa = percentBioMassa

class Data:
    """Класс для ханения данных одной полной таблицы"""
    def __init__(self, head, body, bottom):
        self.head = head
        self.body = body
        self.bottom = bottom

def parse1(data, header):
    """Метод для парсинг первой таблицы"""
    if "Водоем:" in data:
        a = data.find("Дата")
        b = data.find("Станция")
        header.water = data[7:a].strip()
        header.date = data[a+5:b].strip()
        header.station = data[b+8:].strip()
    elif "Глубина:" in data:
        a = data.find("Температура")
        b = data.find("Прозрачность")
        header.depth = data[8:a].strip()
        header.temperature = data[a+12:b].strip()
        header.alpha = data[b+13:].strip()
    elif "Исполнитель:" in data:
        header.author = data[12:].strip()


def parse3(data):
    """Метод для парсинг 2 и 3 таблицы"""
    if i[0][0] != "Отдел" and i[0][0] != "Таксон":
        return Takson(data[0][0], data[1][0], data[2][0], data[3][0], data[4][0])
    return 0

#Путь к файлу для чтения с расширением .docx
doc_result = docx2python('mt.docx')
parseData = []
parseState = ParseEnum.notGood
for j in doc_result.body:
    header = Header()
    bottom = []
    body = []

    for i in j:
        if i[0][0] == "":
            continue

        if "Водоем:" in i[0][0]:
            parseState = ParseEnum.header
        elif "Таксон" == i[0][0]:
            parseState = ParseEnum.body
        elif "Отдел" == i[0][0]:
            parseState = ParseEnum.bottom
        elif "Всего" == i[0][0]:
            takson = parse3(i)
            if takson != 0:
                bottom.append(takson)
            parseState = ParseEnum.notGood

        if parseState == ParseEnum.header:
            parse1(i[0][0], header)
        elif parseState == ParseEnum.body or parseState == ParseEnum.bottom:
            takson = parse3(i)
            if takson != 0 and parseState == ParseEnum.body:
                body.append(takson)
            elif takson != 0 and parseState == ParseEnum.bottom:
                bottom.append(takson)
        elif parseState == ParseEnum.notGood:
            pass
        else:
            print("Error in parseState")

    if header.author != "":
        parseData.append(Data(header, body, bottom))

#MARK: - записать в файл .csv
with open('header.tsv', 'wt') as out_file:
    tsv_writer = csv.writer(out_file, delimiter='\t')
    counter = 0
    for i in parseData:
        tsv_writer.writerow([counter, i.head.water, i.head.date, i.head.station, i.head.depth, i.head.temperature, i.head.alpha, i.head.author])
        counter += 1

with open('body.tsv', 'wt') as out_file:
    tsv_writer = csv.writer(out_file, delimiter='\t')
    counter = 0
    for i in parseData:
        for j in i.body:
            tsv_writer.writerow([counter, j.takson, j.counter, j.bioMassa, j.percentCounter, j.percentBioMassa])
        counter += 1

with open('bottom.tsv', 'wt') as out_file:
    tsv_writer = csv.writer(out_file, delimiter='\t')
    counter = 0
    for i in parseData:
        for j in i.bottom:
            tsv_writer.writerow([counter, j.takson, j.counter, j.bioMassa, j.percentCounter, j.percentBioMassa])
        counter += 1
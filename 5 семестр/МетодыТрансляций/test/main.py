from docx2python import docx2python
from enum import Enum

class ParseEnum(Enum):
    table1 = 1
    table2 = 2
    table3 = 3
    notGood = 4

class Header:
    def __init__(self, water, date, station, depth, temperature, alpha, author):
        self.water = water
        self.date = date
        self.station = station
        self.depth = depth #глубина
        self.temperature = temperature
        self.alpha = alpha
        self.author = author

class Takson:
    def __init__(self, takson, counter, bioMassa, percentCounter, percentBioMassa):
        self.takson = takson
        self.counter = counter
        self.bioMassa = bioMassa
        self.percentCounter = percentCounter
        self.percentBioMassa = percentBioMassa

def parse1(data):
    if "Водоем:" in data:
        pass
    elif "Глубина:" in data:
        pass
    elif "Исполнитель:" in data:
        pass
    else:
        print("Error in parse1 def")

def parse2(data):
    if i[0][0] != "Таксон":
        #print(data)
        pass

parseState = ParseEnum.notGood

doc_result = docx2python('MT.docx')
for j in doc_result.body:
    for i in j:
        if i[0][0] == "":
            continue

        if "Водоем:" in i[0][0]:
            parseState = ParseEnum.table1
            #тут парсим блок 1
        if "Таксон" == i[0][0]:
            parseState = ParseEnum.table2
            # тут парсим блок 2
        if "Отдел" == i[0][0]:
            parseState = ParseEnum.table3
            # тут парсим блок 3
        if "Всего" == i[0][0]:
            parseState = ParseEnum.notGood
            print(i)

        if parseState == ParseEnum.table1:
            parse1(i[0][0])
        elif parseState == ParseEnum.table2:
            parse2(i)
        elif parseState == ParseEnum.table3:
            pass
        elif parseState == ParseEnum.notGood:
            pass
        else:
            print("Error in parseState")
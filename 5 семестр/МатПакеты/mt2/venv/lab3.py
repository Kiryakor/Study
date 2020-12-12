from scipy import stats
import numpy
import math
import matplotlib.pyplot

# входные данные
x = numpy.array([-2, -1., 0, 1, 2, 3, 5])
y = numpy.array([14, 17, 10, 4, 6, 19, 101])
arraySize = x.size
keff_count = 3
alpha = 0.05

# посчитали X и Y из лекции
x1 = numpy.array([
    [1., x[0], x[0]**2, x[0]**3],
    [1., x[1], x[1]**2, x[1]**3],
    [1., x[2], x[2]**2, x[2]**3],
    [1., x[3], x[3]**2, x[3]**3],
    [1., x[4], x[4]**2, x[4]**3],
    [1., x[5], x[5]**2, x[5]**3],
    [1., x[6], x[6]**2, x[6]**3],
])

y1 = y.transpose()

# нашли коэф
keff = numpy.dot(numpy.dot(numpy.linalg.inv(numpy.dot(x1.transpose(), x1)), x1.transpose()), y1)
# их вывод на экран
print(keff)
print(numpy.polyfit(x,y,3))

# считаем Y с крышкой (вместо x - наша выборка и наши коэффициенты)
ySktushkoy = keff[0] + keff[1] * x + keff[2]*(x**2) + keff[3]*(x**3)

#RSS
RSS = sum((y-ySktushkoy)**2)

#y - среднее
Ymiddle = sum(y) / arraySize

# TSS
TSS = sum((y - Ymiddle)**2)

# R^2
R2 = 1- RSS / TSS

# Считаем сигна квадрат и сигрма 1 квадрат
sigma_2 = TSS / (arraySize-1)
sigma1_2 = RSS / (arraySize-keff_count-1)

# F наблюдаемов
obsF = sigma_2 / sigma1_2

# F критическое
expF = stats.f.ppf(1-alpha,arraySize-1,arraySize-keff_count-1)

# (X^t * X)^-1
xtx1 = numpy.linalg.inv(numpy.dot(x1.transpose(), x1))

# T нблюдаемое
obsT = [ abs(keff[i]) / (numpy.sqrt(RSS/(arraySize-keff_count-1)) * xtx1[i][i]) for i in range(4)]

# T критическое
expT = stats.t.ppf(1-(alpha/2),arraySize-keff_count-1)

# график
xplot = numpy.arange(-3.,6,0.01)
yplot = keff[0] + keff[1]*xplot + keff[2]*(xplot**2) + keff[3]*(xplot**3)
matplotlib.pyplot.plot(x,y,'or')
matplotlib.pyplot.plot(xplot,yplot,'k')
matplotlib.pyplot.xlabel(r'$ось X$')
matplotlib.pyplot.ylabel(r'$ось Y$')
frst = "+" if keff[1]>0 else ""
scnd = "+" if keff[2]>0 else ""
frd = "+" if keff[3]>0 else ""
matplotlib.pyplot.title(r'$y = {{{}}} {{{}}} {{{}}}x {{{}}} {{{}}}x^2 {{{}}} {{{}}}x^3 $'.format(
    round(keff[0],2),
    frst,
    round(keff[1],2),
    scnd,
    round(keff[2],2),
    frd,
    round(keff[3]),2),
)
matplotlib.pyplot.grid()
matplotlib.pyplot.show()
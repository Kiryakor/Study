from scipy import stats
import numpy
import math
import matplotlib.pyplot
# входные данные
x = numpy.array([-2.5, -1., -0.5, 0., 1., 1.5, 3.])
y = numpy.array([-9., 10., 2., 5., 0., 2., 36.])
n = x.size
k = 3
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
a = numpy.dot(numpy.dot(numpy.linalg.inv(numpy.dot(x1.transpose(),x1)), x1.transpose()), y1)
# их вывод на экран
print(a[3],'\t',a[2],'\t',a[1],'\t',a[0])

# считаем Y с крышкой (вместо x - наша выборка и наши коэффициенты)
ySktushkoy = a[0] + a[1] * x + a[2]*(x**2) + a[3]*(x**3)

#RSS
RSS = sum((y-ySktushkoy)**2)

#y - среднее
Ysrednee = sum(y) / n

# TSS
TSS = sum((y - Ysrednee)**2)

# R^2
R2 = 1- RSS/TSS

# Считаем сигна квадрат и сигрма 1 квадрат
sigma_2 = TSS/(n-1)
sigma1_2 = RSS / (n-k-1)

# F наблюдаемов
obsF = sigma_2 / sigma1_2

# F критическое
expF = stats.f.ppf(1-alpha,n-1,n-k-1)

# (X^t * X) ^ -1
xtx1 = numpy.linalg.inv(numpy.dot(x1.transpose(), x1))

# T нблюдаемое
obsT = [0, 0, 0, 0]
for i in range(4):
    obsT[i] = abs(a[i]) / (numpy.sqrt(RSS/(n-k-1)) * xtx1[i][i])

# T критическое
expT = stats.t.ppf(1-(alpha/2),n-k-1)

# график
xplot = numpy.arange(-3.,3.5,0.01)
yplot = a[0] + a[1]*xplot + a[2]*(xplot**2) + a[3]*(xplot**3)
# draw

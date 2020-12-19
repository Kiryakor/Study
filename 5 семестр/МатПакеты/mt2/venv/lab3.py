from scipy import stats
import numpy
import math
import matplotlib.pyplot

x = numpy.array([-2, -1., 0, 1, 2, 3, 5])
y = numpy.array([14, 17, 10, 4, 6, 19, 101])
arraySize = x.size
keff_count = 3
alpha = 0.05

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

keff = numpy.dot(numpy.dot(numpy.linalg.inv(numpy.dot(x1.transpose(), x1)), x1.transpose()), y1)
print(keff)
print(numpy.polyfit(x,y,keff_count)[::-1])

ySktushkoy = keff[0] + keff[1] * x + keff[2]*(x**2) + keff[3]*(x**3)

RSS = sum((y-ySktushkoy)**2)

Ymiddle = sum(y) / arraySize

TSS = sum((y - Ymiddle)**2)

sigma_2 = TSS / (arraySize-1)
sigma1_2 = RSS / (arraySize-keff_count-1)

nabludaemoeF = sigma_2 / sigma1_2

kriticheskoeF = stats.f.ppf(1-alpha,arraySize-1,arraySize-keff_count-1)

print(nabludaemoeF)
print(kriticheskoeF)
if nabludaemoeF > kriticheskoeF:
    print("H1")
else:
    print("Ho")

xtx1 = numpy.linalg.inv(numpy.dot(x1.transpose(), x1))

nabludaemoeT = [ abs(keff[i]) / (numpy.sqrt(RSS/(arraySize-keff_count-1) * xtx1[i][i])) for i in range(4)]

kriticheskoeT = stats.t.ppf(1-(alpha/2),arraySize-keff_count-1)

print("")
print(nabludaemoeT)
print(kriticheskoeT)

ySktushkoy = keff[0] + keff[1] * x + keff[3]*(x**3)
keff_count = 2

RSS = sum((y-ySktushkoy)**2)

Ymiddle = sum(y) / arraySize

TSS = sum((y - Ymiddle)**2)

R2 = 1 - RSS / TSS

sigma_2 = TSS / (arraySize-1)
sigma1_2 = RSS / (arraySize-keff_count-1)

nabludaemoeF = sigma_2 / sigma1_2

kriticheskoeF = stats.f.ppf(1-alpha,arraySize-1,arraySize-keff_count-1)
print("")
print(nabludaemoeF)
print(kriticheskoeF)
if nabludaemoeF > kriticheskoeF:
    print("H1")
else:
    print("Ho")

xplot = numpy.arange(-3.,6,0.01)
matplotlib.pyplot.plot(x,y,'or')
yplot = keff[0] + keff[1]*xplot + keff[2]*(xplot**2) + keff[3]*(xplot**3)
matplotlib.pyplot.plot(xplot,yplot,'k')

yplot = keff[0] + keff[1]*xplot + keff[3]*(xplot**3)
matplotlib.pyplot.plot(xplot,yplot,'b')

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
    color="b"
)
frst = "+" if keff[1]>0 else ""
frd = "+" if keff[3]>0 else ""
matplotlib.pyplot.suptitle(r'$y = {{{}}} {{{}}} {{{}}}x {{{}}} {{{}}}x^3 $'.format(
    round(keff[0],2),
    frst,
    round(keff[1],2),
    frd,
    round(keff[3]),2),
    color="g"
)
matplotlib.pyplot.grid()
matplotlib.pyplot.show()
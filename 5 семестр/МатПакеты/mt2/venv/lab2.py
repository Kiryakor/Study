from scipy import stats
import numpy
import math

# Центры интервалов, на которые разбиты значения случайной величины:
step = 0.15
bins = numpy.arange(0.075, 1.05, step)

# Частоты попадания случайной величины в заданные интервалы:
counts = [14, 19, 14, 12, 14, 17, 10]

# Общее число наблюдений:
n = sum(counts)

# Вероятности попаданий значений случайной величины в интервалы:
p = []
for i in counts:
    p.append(float(i) / n)

# Длина интервалов (одинаковая для всех интервалов по условию)
h = 0.15

# Матожидание выборки
m = 0
for i in range(bins.size):
    m = m + bins[i] * p[i]

# Дисперсия выборки
d = 0
for i in range(bins.size):
    d = d + ((bins[i] - m) ** 2) * p[i]

# Оценка параметров распределения методом моментов
a = m - math.sqrt(3 * d)
b = m + math.sqrt(3 * d)

# Теоретические вероятности попадания в интервалы
expP = []
for i in range(bins.size):
    expP.append(stats.uniform.cdf(bins[i] + h / 2, a, b) - stats.uniform.cdf(bins[i] - h / 2, a, b))

# Теоретические частоты попадания в интервалы
expCount = []
for i in expP:
    expCount.append(i * n)

# Мера расхождения между данными и моделью по критерию К.Пирсона
u = stats.chisquare(counts, expCount, 2)
print(u[0])

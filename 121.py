import math
import turtle


def xt(t):
    return 16 * math.sin(t) ** 3


def yt(t):
    return 13 * math.cos(t) - 5 * math.cos(2 * t) - 2 * math.cos(3 * t) - math.cos(4 * t)


# Инициализация черепахи и настроек
t = turtle.Turtle()
t.speed(0)  # Максимальная скорость черепахи
turtle.colormode(255)  # Установка цветовой модели в RGB
turtle.Screen().bgcolor(0, 0, 0)  # Установка фона в черный цвет

# Начало рисования
t.penup()  # Поднимаем перо, чтобы избежать линии от начала
t.goto(0, 0)  # Устанавливаем начальную позицию
t.pendown()  # Опускаем перо

for i in range(2550):
    angle = i * 0.01  # Уменьшена шаговая величина для более плавного движения
    x = xt(angle) * 20  # Масштабируем X
    y = yt(angle) * 20  # Масштабируем Y
    t.pencolor((255 - i % 255, i % 255, (255 + i // 2) % 255))  # Установка цвета пера
    t.goto(x, y)  # Перемещаем черепаху

# Завершаем
t.hideturtle()  # Скрываем черепаху
turtle.done()  # Завершаем графический цикл

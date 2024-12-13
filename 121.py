import streamlit as st

st.title("Визуализация кода")
st.write("Результат работы программы:")

import math
import turtle

def xt(t):
    return 16 * math.sin(t) ** 3


def yt(t):
    return 13 * math.cos(t) - 5 * math.cos(2 * t) - 2 * math.cos(3 * t) - math.cos(4 * t)



t = turtle.Turtle()
t.speed(0)
turtle.colormode(255)
turtle.Screen().bgcolor(0, 0, 0)

t.penup()
t.goto(0, 0)
t.pendown()

for i in range(2550):
    angle = i * 0.01
    x = xt(angle) * 20
    y = yt(angle) * 20
    t.pencolor((255 - i % 255, i % 255, (255 + i // 2) % 255))
    t.goto(x, y)

t.hideturtle()
turtle.done()

st.write("Готово!")
import streamlit as st
import matplotlib.pyplot as plt
import numpy as np

st.title("Визуализация кода в Streamlit")
st.write("Результат работы программы:")

# Определение функций
def xt(t):
    return 16 * np.sin(t) ** 3

def yt(t):
    return 13 * np.cos(t) - 5 * np.cos(2 * t) - 2 * np.cos(3 * t) - np.cos(4 * t)

# Создание данных для графика
t_values = np.linspace(0, 2 * np.pi, 2550)  # Шаг для плавного графика
x_values = xt(t_values) * 20
y_values = yt(t_values) * 20

# Построение графика
plt.figure(figsize=(8, 8), facecolor="black")
plt.plot(x_values, y_values, color="red", lw=1)

# Оформление графика
plt.axis("off")  # Убираем оси
plt.gca().set_aspect("equal", adjustable="box")  # Сохраняем пропорции
plt.tight_layout()

# Отображение графика в Streamlit
st.pyplot(plt)
st.write("Готово!")

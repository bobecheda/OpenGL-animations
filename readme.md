# 🎬 OpenGL Animations Project

## 📌 Overview
This project demonstrates the implementation of multiple 2D animations using OpenGL on a Windows environment. The animations were developed using **C++**, **GLFW**, and **GLEW**, and compiled using **MinGW-w64**.

The goal of this assignment is to showcase understanding of basic animation concepts such as transformation, motion, rotation, and color manipulation in OpenGL.

---

## 🛠️ Technologies Used

- C++
- OpenGL
- GLFW (Window and input handling)
- GLEW (OpenGL extension loader)
- MinGW-w64 (Compiler)

---

## 🎯 Animations Implemented

### 1️⃣ Pulsing Square
- A square that continuously grows and shrinks.
- Demonstrates **scaling transformation**.

🎥 Video Demo:



https://github.com/user-attachments/assets/61234440-a564-47f1-863b-43ac233aa94e



---

### 2️⃣ Rotating Windmill
- A windmill with blades rotating around a central point.
- Demonstrates **rotation transformation**.

🎥 Video Demo:




https://github.com/user-attachments/assets/69a7eeb4-9a86-4a29-a866-eec270f7ce32


---

### 3️⃣ Bouncing Ball
- A ball that moves up and down within boundaries.
- Demonstrates **translation and collision detection**.

🎥 Video Demo:



https://github.com/user-attachments/assets/d3cf8561-da51-43cb-a20c-4869cf08f77b



---

### 4️⃣ Moving Car 
- A car moving horizontally across the screen.
- Includes rotating wheels with visible spokes.
- Demonstrates:
  - Translation (car movement)
  - Rotation (wheel motion)

🎥 Video Demo:



https://github.com/user-attachments/assets/36335bdd-8a32-4d4c-8212-c24a401072b1



---

## ▶️ How to Compile and Run

### Step 1: Open Command Prompt

Navigate to your project folder:

```bash
cd path_to_your_project


g++ filename.cpp -o output ^
-lglfw3 -lglew32 -lopengl32 -lgdi32

example :  g++ bouncing_ball.cpp -o ball ^ -lglfw3 -lglew32 -lopengl32 -lgdi32

##run
./output
example : ./ball

OpenGL-Animations/
│
├── pulsing_square.cpp
├── rotating_windmill.cpp
├── bouncing_ball.cpp
├── moving_car.cpp
├── README.md

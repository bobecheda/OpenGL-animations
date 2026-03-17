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
<video width="600" controls>
  <source src="../visuals/pulsing_square.mp4" type="video/mp4">
</video>


---

### 2️⃣ Rotating Windmill
- A windmill with blades rotating around a central point.
- Demonstrates **rotation transformation**.

🎥 Video Demo:
<video width="600" controls>
  <source src="../visuals/rotating_windmill.mp4" type="video/mp4">
</video>


---

### 3️⃣ Bouncing Ball
- A ball that moves up and down within boundaries.
- Demonstrates **translation and collision detection**.

🎥 Video Demo:
<video width="600" controls>
  <source src="bouncing_ball.mp4" type="video/mp4">
</video>


---

### 4️⃣ Moving Car 
- A car moving horizontally across the screen.
- Includes rotating wheels with visible spokes.
- Demonstrates:
  - Translation (car movement)
  - Rotation (wheel motion)

🎥 Video Demo:
<video width="600" controls>
  <source src="../visuals/moving_car.mp4" type="video/mp4">
</video>


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

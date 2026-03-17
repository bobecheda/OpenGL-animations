#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

int main()
{
    if (!glfwInit())
    {
        std::cout << "GLFW init failed";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Bouncing Ball", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    float x = 0.0f, y = 0.0f;
    float speedX = 0.01f, speedY = 0.015f;
    float radius = 0.1f;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        x += speedX;
        y += speedY;

        if (x + radius > 1.0f || x - radius < -1.0f)
            speedX = -speedX;

        if (y + radius > 1.0f || y - radius < -1.0f)
            speedY = -speedY;

        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.5f, 0.0f);

        glVertex2f(x, y);

        for (int i = 0; i <= 100; i++)
        {
            float theta = 2.0f * 3.1416f * i / 100;
            float dx = radius * cos(theta);
            float dy = radius * sin(theta);
            glVertex2f(x + dx, y + dy);
        }

        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
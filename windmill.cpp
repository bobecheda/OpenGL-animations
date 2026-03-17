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

    GLFWwindow* window = glfwCreateWindow(800, 600, "Rotating Windmill", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    float angle = 0.0f;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        angle += 0.5f;

        // Draw center
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.8f, 0.2f, 0.2f);

        glVertex2f(0.0f, 0.0f);

        for (int i = 0; i <= 100; i++)
        {
            float theta = 2.0f * 3.1416f * i / 100;
            float x = 0.1f * cos(theta);
            float y = 0.1f * sin(theta);
            glVertex2f(x, y);
        }
        glEnd();

        // Rotate blades
        glPushMatrix();
        glRotatef(angle, 0.0f, 0.0f, 1.0f);

        for (int i = 0; i < 4; i++)
        {
            glRotatef(90.0f, 0.0f, 0.0f, 1.0f);

            glBegin(GL_TRIANGLES);
            glColor3f(0.2f, 0.6f, 0.9f);

            glVertex2f(0.0f, 0.0f);
            glVertex2f(0.6f, 0.1f);
            glVertex2f(0.6f, -0.1f);

            glEnd();
        }

        glPopMatrix();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
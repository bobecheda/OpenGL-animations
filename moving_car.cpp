#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

int main()
{
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "Enhanced Moving Car", NULL, NULL);
    if (!window) return -1;

    glfwMakeContextCurrent(window);
    glewInit();

    // Animation variables
    float carX = -1.2f;
    float speed = 0.0005f;     
    float wheelAngle = 0.0f;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Update movement
        carX += speed;
        wheelAngle -= 5.0f;

        if (carX > 1.2f)
            carX = -1.2f;

        // 🔹 Draw road line
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-1.0f, -0.3f);
        glVertex2f(1.0f, -0.3f);
        glEnd();

        // Move car
        glPushMatrix();
        glTranslatef(carX, 0.0f, 0.0f);

        // 🔹 Car body
        glBegin(GL_QUADS);

        // Base
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.4f, -0.2f);
        glVertex2f(0.4f, -0.2f);
        glVertex2f(0.4f, 0.1f);
        glVertex2f(-0.4f, 0.1f);

        // Top
        glColor3f(0.0f, 0.5f, 1.0f);
        glVertex2f(-0.2f, 0.1f);
        glVertex2f(0.2f, 0.1f);
        glVertex2f(0.1f, 0.3f);
        glVertex2f(-0.1f, 0.3f);

        glEnd();

        // 🔹 Wheels (enhanced)
        for (int w = -1; w <= 1; w += 2)
        {
            glPushMatrix();
            glTranslatef(0.25f * w, -0.2f, 0);
            glRotatef(wheelAngle, 0, 0, 1);

            // Wheel fill (gray)
            glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.3f, 0.3f, 0.3f);
            glVertex2f(0, 0);

            for (int i = 0; i <= 100; i++)
            {
                float theta = 2 * 3.1416f * i / 100;
                glVertex2f(0.1f * cos(theta), 0.1f * sin(theta));
            }
            glEnd();

            // Wheel outline (white)
            glBegin(GL_LINE_LOOP);
            glColor3f(1.0f, 1.0f, 1.0f);

            for (int i = 0; i <= 100; i++)
            {
                float theta = 2 * 3.1416f * i / 100;
                glVertex2f(0.1f * cos(theta), 0.1f * sin(theta));
            }
            glEnd();

            // Spokes (to show rotation clearly)
            glBegin(GL_LINES);
            glColor3f(1.0f, 1.0f, 1.0f);

            glVertex2f(0, 0); glVertex2f(0.1f, 0);
            glVertex2f(0, 0); glVertex2f(-0.1f, 0);
            glVertex2f(0, 0); glVertex2f(0, 0.1f);
            glVertex2f(0, 0); glVertex2f(0, -0.1f);

            glEnd();

            glPopMatrix();
        }

        glPopMatrix();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
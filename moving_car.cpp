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
    float sunAngle = 0.0f;

    float cloudX1 = -1.0f;   // ✅ NEW
    float cloudX2 = 0.5f;    // ✅ NEW

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Update movement
        carX += speed;
        wheelAngle -= 5.0f;
        sunAngle += 1.0f;

        cloudX1 += 0.0002f;   // ✅ NEW
        cloudX2 += 0.00015f;  // ✅ NEW

        if (carX > 1.2f)
            carX = -1.2f;

        if (cloudX1 > 1.2f) cloudX1 = -1.2f;   // ✅ NEW
        if (cloudX2 > 1.2f) cloudX2 = -1.2f;   // ✅ NEW

        // 🔹 Draw road line
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-1.0f, -0.3f);
        glVertex2f(1.0f, -0.3f);
        glEnd();

        // 🔹 Draw Sun
        glPushMatrix();
        glTranslatef(0.7f, 0.7f, 0.0f);

        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(0, 0);
        for (int i = 0; i <= 100; i++)
        {
            float theta = 2 * 3.1416f * i / 100;
            glVertex2f(0.15f * cos(theta), 0.15f * sin(theta));
        }
        glEnd();

        glRotatef(sunAngle, 0, 0, 1);

        glBegin(GL_LINES);
        glColor3f(1.0f, 0.8f, 0.0f);
        for (int i = 0; i < 12; i++)
        {
            float angle = 2 * 3.1416f * i / 12;
            float x1 = 0.15f * cos(angle);
            float y1 = 0.15f * sin(angle);
            float x2 = 0.25f * cos(angle);
            float y2 = 0.25f * sin(angle);

            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
        }
        glEnd();
        glPopMatrix();

        // ☁️ Cloud 1 (NEW)
        glPushMatrix();
        glTranslatef(cloudX1, 0.6f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);

        for (float offset = -0.1f; offset <= 0.1f; offset += 0.1f)
        {
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(offset, 0);
            for (int i = 0; i <= 50; i++)
            {
                float theta = 2 * 3.1416f * i / 50;
                glVertex2f(offset + 0.08f * cos(theta), 0.08f * sin(theta));
            }
            glEnd();
        }
        glPopMatrix();

        // ☁️ Cloud 2 (NEW)
        glPushMatrix();
        glTranslatef(cloudX2, 0.8f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);

        for (float offset = -0.12f; offset <= 0.12f; offset += 0.12f)
        {
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(offset, 0);
            for (int i = 0; i <= 50; i++)
            {
                float theta = 2 * 3.1416f * i / 50;
                glVertex2f(offset + 0.1f * cos(theta), 0.1f * sin(theta));
            }
            glEnd();
        }
        glPopMatrix();

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

        // 🔹 Wheels
        for (int w = -1; w <= 1; w += 2)
        {
            glPushMatrix();
            glTranslatef(0.25f * w, -0.2f, 0);
            glRotatef(wheelAngle, 0, 0, 1);

            glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.3f, 0.3f, 0.3f);
            glVertex2f(0, 0);

            for (int i = 0; i <= 100; i++)
            {
                float theta = 2 * 3.1416f * i / 100;
                glVertex2f(0.1f * cos(theta), 0.1f * sin(theta));
            }
            glEnd();

            glBegin(GL_LINE_LOOP);
            glColor3f(1.0f, 1.0f, 1.0f);

            for (int i = 0; i <= 100; i++)
            {
                float theta = 2 * 3.1416f * i / 100;
                glVertex2f(0.1f * cos(theta), 0.1f * sin(theta));
            }
            glEnd();

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
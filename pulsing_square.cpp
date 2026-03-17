#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    if (!glfwInit())
    {
        std::cout << "GLFW initialization failed";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Pulsing Square", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    float scale = 1.0f;
    float scaleSpeed = 0.01f;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        scale += scaleSpeed;

        if (scale > 1.5f || scale < 0.5f)
        {
            scaleSpeed = -scaleSpeed;
        }

        glPushMatrix();

        glScalef(scale, scale, 1.0f);

        glBegin(GL_QUADS);

        glColor3f(0.2f, 0.7f, 0.3f);

        glVertex2f(-0.2f, -0.2f);
        glVertex2f(0.2f, -0.2f);
        glVertex2f(0.2f, 0.2f);
        glVertex2f(-0.2f, 0.2f);

        glEnd();

        glPopMatrix();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
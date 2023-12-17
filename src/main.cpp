#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <developer/developer.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{
    // Initialize the GLFW
    glfwInit();

    // Configure the GLFW using windowHint
    // OpenGL major version 3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // OpenGL minor version 3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Use the core version of the OpenGL
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // GLFW initialized using OpenGL 3.3 CORE


    // Create a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello Window!", NULL, NULL);
    if (window == NULL){
        std::cout << "Failed to create a GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);


    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    // Set ip openGL
    glViewport(0, 0, 800, 600);
    /*
        Note that processed coordinates in OpenGL are between -1 and 1 so we effectively map from
        the range (-1 to 1) to (0, 800) and (0, 600).
    */
    // Handle window resizing  
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // rendering commands here

        // Clear the screen with the color red RGBA 1, 0, 0, 1
        // RGBA (red, green, blue, alpha)
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        // check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    

    glfwTerminate();
    return 0;
}


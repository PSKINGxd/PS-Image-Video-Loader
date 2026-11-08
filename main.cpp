#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "header/Image.h" //Library for Image
#include "header/Video.h" //Library for Video

struct state{
    //color
    float r = 0.3f;
    float g = 0.4f;
    float b = 0.6f;
};

int main(){
    //variable
    state s;

    //Class for Image & Video
    Image image;
    Video video;
    
    int width = 800;
    int height = 640;

    //GLFW & GLEW
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(width, height, "Example", NULL, NULL);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    glewInit();

    //==== initialize ====
    //image
    image.init(width, height);
    image.load("image.png");

    //video
    video.load("video.mp4");
    video.play(); // This is necessary to play the video

    //=====================

    //renderer
    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();

        glClearColor(s.r, s.g, s.b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //image.draw(0, 0); //give the arguments for current image x & y
        video.draw(width, height);

        /*You Cannot Over Driven both the Image & the Video at the same time*/

        glfwSwapBuffers(window);
    }

    image.shutdown();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
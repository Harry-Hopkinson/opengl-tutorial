#include <iostream>
#include <E:\Programming\opengl-tutorial\include\glad.h>
#include <GLFW/glfw3.h>
#include <E:\Programming\opengl-tutorial\src\Triangle\Window.h>
#include <E:\Programming\opengl-tutorial\src\Triangle\utils.cpp>

class Shaders {
  // build and compile shader program
  int success;
  char errorInfo[512] = "";
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  unsigned int shaderProgram = glCreateProgram();
  public:
      void vertexShaderFunc() {
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);

        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, errorInfo);
            std::cout << "ERROR::VERTEX::SHADER::COMPILATION_FAILED\n" << errorInfo << "\n";
        }
      }
      void fragmentShadersFunc() {
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
    
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragmentShader, 512, NULL, errorInfo);
            std::cout << "ERROR::FRAGMENT::SHADER::COMPILATION_FAILED\n" << errorInfo << "\n";
        }
      }
      void linkShadersFunc() {
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
    
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, errorInfo);
            std::cout << "ERROR::PROGRAM::LINKING_FAILED\n" << errorInfo << "\n";
        }
      }
      void deleteShaders() {
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
      }
};
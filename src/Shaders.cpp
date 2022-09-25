#include <E:\Programming\opengl-tutorial\include\glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Shaders {
  const char* vertexShaderSource = 
    "#version 450 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\n\0";
 
  const char* fragmentShaderSource = 
    "#version 450 core\n"
    "out vec4 FragmentColor;\n"
    "void main()\n"
    "{\n"
    "   FragmentColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";
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
};
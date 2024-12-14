#include <iostream>
#include <glew.h>
#include "Header/display.h"
#include "Header/mesh.h"
#include "Header/shader.h"
#include "Header/texture.h"
#include "Header/transform.h"
#include "Header/camera.h"

int main()
{
  Display display(800, 600, "Hello World");
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) 
  {
    std::cerr << "Failed to initialize GLEW" << std::endl;
    return -1;
  }
  Vertex vertices[] = {
    Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)), 
    Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)), 
    Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)),
  };

  unsigned int indices[] = {0, 1, 2};

  Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices)/ sizeof(indices[0]));
  Mesh mesh2("./res/monkey3.obj");
  Shader shader("./res/basicShader");
  Texture texture("./res/bricks.jpg");
  Camera camera(glm::vec3(0, 0, 5), 70.0f, (float)display.GetWidth()/(float)display.GetHeight(), 0.01f, 100.0f);
  Transform transform;

  float counter = 0.0f;

  while (!display.IsClosed())
  {
    display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

    float sinCounter = sinf(counter);
    float cosCounter = cosf(counter);

    transform.GetPos().x = sinCounter;
    transform.GetRot().x = cosCounter * 5;
    transform.GetRot().y = cosCounter * 5;
    transform.GetRot().z = cosCounter * 5;
    //transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));

    shader.Bind();
    texture.Bind(0);
    shader.Update(transform, camera);
    mesh2.Draw();
    display.Update();
    counter+= 0.0001f;
  }
}

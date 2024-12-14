#ifndef SHADER_H
#define SHADER_H 

#include <string>
#include <glew.h>
#include "transform.h"
#include "camera.h"

class Shader
{
public:
  Shader(const std::string& fileName);
  void Bind();
  void Update(const Transform& transform, const Camera& camera);
  virtual ~Shader();

protected:
private:
  static const unsigned int NUM_SHADER = 2;

  Shader(const Shader& other) {}
  void operator=(const Shader& other){}

  enum
  {
    TRANSFORM_U,
    NUM_UNIFROMS
  };

  GLuint m_program;
  GLuint m_shader[NUM_SHADER];
  GLuint m_uniforms[NUM_UNIFROMS];
};

#endif // !SHADER_H

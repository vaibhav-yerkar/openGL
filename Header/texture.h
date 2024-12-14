#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <glew.h>

class Texture
{
public:
  Texture(const std::string& fileName);

  void Bind(unsigned int unit);

  virtual ~Texture();
protected:
private:
  Texture(const Texture& other);
  void operator=(const Texture& other);

  GLuint m_texture;
};

#endif // !TEXTURE_H


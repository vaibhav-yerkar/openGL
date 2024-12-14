#ifndef DISPLAY_H
#define DISPLAY_H 

#include <string>
#include <SDL.h>

class Display
{
public:
  Display(int width, int height, const std::string& title);
    
  void Update();
  bool IsClosed();
  void Clear(float r, float g, float b, float a);

  int GetWidth(){ return m_width; }
  int GetHeight(){ return m_height; }

  virtual ~Display(); 

protected:
private:
  Display(const Display& other);
  void operator=(const Display& other);

  SDL_Window* m_window;
  SDL_GLContext m_glContext;
  bool m_isClosed;
  int m_width;
  int m_height;
};

#endif // !DISPLAY_H

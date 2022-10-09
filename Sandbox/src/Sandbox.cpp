#include <Leaf.h>
class Sandbox : public Leaf::Application {
 public:
  Sandbox() {}
  ~Sandbox() {}
};


Leaf::Application* Leaf::CreateApplication() { return new Sandbox(); }
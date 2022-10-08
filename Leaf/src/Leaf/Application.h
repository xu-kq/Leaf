#pragma once
namespace Leaf{
class __declspec(dllexport) Application{
 public:
  Application();
  virtual ~Application();
  void run();
};

// To be defined in Client.
Application* CreateApplication();
}
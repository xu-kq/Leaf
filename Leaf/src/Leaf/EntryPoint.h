#pragma once
//#ifdef Leaf_PLATFORM_WINDOWS

extern Leaf::Application* Leaf::CreateApplication();

int main(int argc, char** argv) {
  std::cout << "Leaf Engine" << std::endl;
  auto app = Leaf::CreateApplication();
  app->run();

  return 0;
}

//#endif
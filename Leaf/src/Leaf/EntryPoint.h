#pragma once

extern Leaf::Application* Leaf::CreateApplication();

int main(int argc, char** argv) {
  Leaf::Log::Init();
  LEAF_CORE_WARN("Initialized Log!");
  int a = 5;
  LEAF_INFO("Hello! var={0}", a);

  auto app = Leaf::CreateApplication();
  app->run();

  return 0;
}

//#endif
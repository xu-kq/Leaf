#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

#include <GLFW/glfw3.h>

namespace Leaf {
  Application::Application() {
    m_Window = std::unique_ptr<Window>(Window::Create());
  }

  Application::~Application() {}

  void Application::run() {

    WindowResizeEvent e(1280, 720);

    if (e.IsInCategory(EventCategoryApplication)) {
      LEAF_TRACE(e);
    }

    while (m_Running) {
      LEAF_TRACE(e);
      glClearColor(0.341, 0.980, 1, 1);
      glClear(GL_COLOR_BUFFER_BIT);
      m_Window->OnUpdate();
    }

    if (e.IsInCategory(EventCategoryInput)) {
      LEAF_TRACE(e);
    }
    while (true)
      ;
  }
}  // namespace Leaf
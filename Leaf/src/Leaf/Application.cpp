#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"
namespace Leaf {
Application::Application() {}
Application::~Application() {}
void Application::run() {
   WindowResizeEvent e(1280, 720);
   if(e.IsInCategory(EventCategoryApplication)) {
     LEAF_TRACE(e);
   }
   if(e.IsInCategory(EventCategoryInput)){
     LEAF_TRACE(e);
   }
  while (true)
    ;
}
}  // namespace Leaf
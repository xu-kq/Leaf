#pragma once

#include <sstream>

#include "Event.h"

namespace Leaf {
class LEAF_API WindowResizeEvent : public Event {
 public:
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
  EVENT_CLASS_TYPE(WindowResize)
  WindowResizeEvent(unsigned int width, unsigned int height)
      : m_Width(width), m_Height(height) {}

  unsigned int GetWidth() const { return m_Width; }
  unsigned int GetHeight() const { return m_Height; }

  std::string ToString() const override {
    std::stringstream ss;
    ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
    return ss.str();
  }

 private:
  unsigned int m_Width, m_Height;
};

class LEAF_API WindowCloseEvent : public Event {
 public:
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
  EVENT_CLASS_TYPE(WindowClose)
  WindowCloseEvent() = default;
};

class LEAF_API AppTickEvent : public Event{
 public:
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
  EVENT_CLASS_TYPE(AppTick)
  AppTickEvent() = default;
};

class LEAF_API AppUpdateEvent : public Event {
 public:
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
  EVENT_CLASS_TYPE(AppUpdate)
  AppUpdateEvent() = default;
};

class LEAF_API AppRenderEvent : public Event {
 public:
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
  EVENT_CLASS_TYPE(AppRender)
  AppRenderEvent() = default;
};
}  // namespace Leaf
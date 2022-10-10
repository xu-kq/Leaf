#pragma once
#include "Event.h"

namespace Leaf {
class LEAF_API MouseMovedEvent : public Event {
 public:
  EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
  EVENT_CLASS_TYPE(MouseMoved)
  MouseMovedEvent(float x, float y) {}

  float GetX() const { return m_MouseX; }
  float GetY() const { return m_MouseY; }

  std::string ToString() const override {
    std::stringstream ss;
    ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
    return ss.str();
  }

 private:
  float m_MouseX, m_MouseY;
};

class MouseScrolledEvent : public Event {
 public:
  EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
  EVENT_CLASS_TYPE(MouseScrolled)
  MouseScrolledEvent(float xOffset, float yOffset)
      : m_XOffset(xOffset), m_YOffset(yOffset) {}
  float GetXOffset() const { return m_XOffset; }
  float GetYOffset() const { return m_YOffset; }
  std::string ToString() const override {
    std::stringstream ss;
    ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
    return ss.str();
  }

 private:
  float m_XOffset, m_YOffset;
};

class LEAF_API MouseButtonEvent : public Event {
 public:
  EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
  int GetMouseButton() const { return m_Button; }

 protected:
  MouseButtonEvent(int button) : m_Button(button) {}
  int m_Button;
};

class LEAF_API MouseButtonPressedEvent : public MouseButtonEvent {
 public:
  EVENT_CLASS_TYPE(MouseButtonPressed)
  MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

  std::string ToString() const override {
    std::stringstream ss;
    ss << "MosueButtonPressedEvent: " << m_Button;
  }
};

class LEAF_API MouseButtonReleasedEvent : public MouseButtonEvent {
 public:
  EVENT_CLASS_TYPE(MouseButtonReleased)
  MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

  std::string ToString() const override {
    std::stringstream ss;
    ss << "MosueButtonReleasedEvent: " << m_Button;
  }
};
}  // namespace Leaf
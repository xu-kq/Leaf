#pragma once
#include <sstream>
#include "Event.h"
namespace Leaf {
class LEAF_API KeyEvent : public Event {
 public:
  EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
  int GetKeyCode() const { return m_KeyCode; }

 protected:
  KeyEvent(int keycode) : m_KeyCode(keycode) {}
  int m_KeyCode;
};

class LEAF_API KeyPressedEvent : public KeyEvent {
 public:
  EVENT_CLASS_TYPE(KeyPressed)
  KeyPressedEvent(int keycode, int repeatCount)
      : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

  int GetRepeatCount() const { return m_RepeatCount; }
  std::string ToString() const override {
    std::stringstream ss;
    ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount
       << " repeats)";
    return ss.str();
  }

 private:
  int m_RepeatCount;
};

class LEAF_API KeyReleasedEvent : public KeyEvent {
 public:
  EVENT_CLASS_TYPE(KeyReleased)
  KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

  std::string ToString() const override {
    std::stringstream ss;
    ss << "KeyReleasedEvent: " << m_KeyCode;
    return ss.str();
  }

};
}  // namespace Leaf
// Copyright 2014 Tanel Lebedev

#ifndef SRC_EXPLICIT_SCOPED_LOCK_H_
#define SRC_EXPLICIT_SCOPED_LOCK_H_

#include <string>
#include <sstream>

#include "Poco/Logger.h"

namespace kopsik {

class ExplicitScopedLock : public Poco::Mutex::ScopedLock {
   public:
    ExplicitScopedLock(
      const std::string context,
      Poco::Mutex& mutex) :
        Poco::Mutex::ScopedLock(mutex),
        context_(context) {
      std::stringstream text;
      text << context_ << " locking";
      logger().trace(text.str());
    }

    ~ExplicitScopedLock() {
      std::stringstream text;
      text << context_ << " unlocking";
      logger().trace(text.str());
    }

   private:
    Poco::Logger &logger() { return Poco::Logger::get("lock"); }

    std::string context_;
};

}  // namespace kopsik

#endif  // SRC_EXPLICIT_SCOPED_LOCK_H_

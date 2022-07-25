#ifndef JSITESTHOSTOBJECT_H
#define JSITESTHOSTOBJECT_H

#include <jsi/jsi.h>

namespace margelo {

using namespace facebook;

class JSI_EXPORT JSITestHostObject: public jsi::HostObject {
public:
  explicit JSITestHostObject() {}

public:
  jsi::Value get(jsi::Runtime&, const jsi::PropNameID& name) override;
  std::vector<jsi::PropNameID> getPropertyNames(jsi::Runtime& rt) override;
};

} // namespace margelo

#endif /* JSITESTHOSTOBJECT_H */

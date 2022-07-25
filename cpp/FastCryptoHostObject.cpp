#include "FastCryptoHostObject.h"
#include <jsi/jsi.h>

namespace margelo {

using namespace facebook;

// TODO: Create macros for this so we don't have to repeat ourselves for each JSI func?

std::vector<jsi::PropNameID> FastCryptoHostObject::getPropertyNames(jsi::Runtime& runtime) {
	std::vector<jsi::PropNameID> result;

	result.push_back(jsi::PropNameID::forUtf8(runtime, "test"));

	return result;}

jsi::Value FastCryptoHostObject::get(jsi::Runtime& runtime, const jsi::PropNameID& propNameId) {
	auto propName = propNameId.utf8(runtime);

	if (propName == "test") {
		return jsi::Value(runtime, jsi::String::createFromUtf8(runtime, "Hello, World!"));
	}

	return jsi::Value::undefined();}
} // namespace margelo

#import "JSITestModule.h"

#import <React/RCTBridge+Private.h>
#import <React/RCTUtils.h>
#import <jsi/jsi.h>

#import "../cpp/JSITestHostObject.h"

@implementation JSITestModule

RCT_EXPORT_MODULE(JSITest)

RCT_EXPORT_BLOCKING_SYNCHRONOUS_METHOD(install)
{
    NSLog(@"Installing JSI bindings for jsi-test...");
    RCTBridge* bridge = [RCTBridge currentBridge];
    RCTCxxBridge* cxxBridge = (RCTCxxBridge*)bridge;
    if (cxxBridge == nil) {
        return @false;
    }

    using namespace facebook;

    auto jsiRuntime = (jsi::Runtime*) cxxBridge.runtime;
    if (jsiRuntime == nil) {
        return @false;
    }
    auto& runtime = *jsiRuntime;

    auto hostObject = std::make_shared<margelo::JSITestHostObject>();
    auto object = jsi::Object::createFromHostObject(runtime, hostObject);
    runtime.global().setProperty(runtime, "__JSITestProxy", std::move(object));

    NSLog(@"Successfully installed JSI bindings for jsi-test!");
    return @true;
}

@end

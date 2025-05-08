#pragma once

#include <AppSpecsJSI.h>

#include <jni.h>

namespace facebook::react {

class NativeModule : public NativeModuleCxxSpec<NativeModule> {

public:
    NativeModule(std::shared_ptr<CallInvoker> jsInvoker);

    ~NativeModule();

    jsi::Object observeNativeUpdater(jsi::Runtime &rt, jsi::Function observer);

private:
    jobject myEmmitterGlobalReference_;

};

}
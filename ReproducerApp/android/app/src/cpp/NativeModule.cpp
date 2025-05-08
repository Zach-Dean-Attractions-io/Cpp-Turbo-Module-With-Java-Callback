#include "NativeModule.h"
#include <android/log.h>
#include <fbjni/fbjni.h>
#include <jsi/jsi.h>
#include "jni.h"

using namespace facebook;
using namespace facebook::react;

NativeModule::NativeModule(std::shared_ptr<CallInvoker> jsInvoker) : NativeModuleCxxSpec(std::move(jsInvoker)) {}

jsi::Object NativeModule::observeNativeUpdater(jsi::Runtime &rt, jsi::Function observer) {

    __android_log_print(ANDROID_LOG_DEBUG, "TestProject", "NativeModule | observeNativeUpdater");

    // Obtain JNIEnv
    JNIEnv *env = facebook::jni::Environment::current();

    // Create new instance of MyEmitter
    jclass myEmitterClass = env->FindClass("com/reproducerapp/MyEmitter");
    jmethodID constructor = env->GetMethodID(myEmitterClass, "<init>", "()V");
    jobject myEmitterInstance = env->NewObject(myEmitterClass, constructor);

    // Assign it to a global reference to keep it in memory
    myEmmitterGlobalReference_ = env->NewGlobalRef(myEmitterInstance);

    return jsi::Object(rt);
}

NativeModule::~NativeModule() {

    __android_log_print(ANDROID_LOG_DEBUG, "TestProject", "NativeModule | Destructor");

    JNIEnv *env = facebook::jni::Environment::current();

    env->DeleteGlobalRef(myEmmitterGlobalReference_);
    myEmmitterGlobalReference_ = nullptr;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_reproducerapp_MyEmitter_notifyNative() {

    __android_log_print(ANDROID_LOG_DEBUG, "TestProject", "NativeModule | notifyNative");
}

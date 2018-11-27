//
// Created by lei on 2018/11/26.
//

#include <com_demo_dynamicjni_DynamicTest.h>
#ifdef __cplusplus
extern "C" {
#endif


static const char *className = "com/demo/dynamicjni/DynamicTest";

static JNINativeMethod gJni_Methods_DynamicTest[] = {
      {"doTwo", "(II)I", (void*)addTwoNumber},
};

JNIEXPORT jint JNICALL addTwoNumber(JNIEnv *env, jobject, jint param1, jint param2) {
    return 1000 * (param1 + param2);
}


static int jniRegisterNativeMethods(JNIEnv* env, const char* className, const JNINativeMethod* gMethods, int numMethods)
{
    jclass clazz;
    clazz = (env)->FindClass( className);
    if (clazz == NULL) {
        return -1;
    }
    int result = 0;
    if ((env)->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        result = -1;
    }
    (env)->DeleteLocalRef(clazz);
    return result;
}

jint JNI_OnLoad(JavaVM* vm, void* reserved){
    JNIEnv* env = NULL;
    jint result = -1;
    if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        return result;
    }
    jniRegisterNativeMethods(env, className, gJni_Methods_DynamicTest, sizeof(gJni_Methods_DynamicTest) / sizeof(JNINativeMethod));
    return JNI_VERSION_1_4;
}
#ifdef __cplusplus
}
#endif
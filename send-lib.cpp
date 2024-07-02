#include <jni.h>
#include <string>
#include "Person.h"
#include <android/log.h>


/*
 * C++ File
 *      ✅ 1. Send Int
 *      ✅ 2. Send String
 *      ✅ 3. Send Float
 *      ✅ 4. Send Char
 *      ✅ 5. Send Array
 *      ✅ 6. Send Object
 *
 * */


extern "C" JNIEXPORT jstring Java_com_programming_cmaketest_MainActivity_getString(JNIEnv* env,jobject /* this */) {
    std::string urls = "https://breakingbadapi.com/documentation";
    return env->NewStringUTF(urls.c_str());
}

extern "C" JNIEXPORT jint Java_com_programming_cmaketest_MainActivity_getInt(JNIEnv* env, jobject) {
    int num = 100;
    return static_cast<jint>(num);
}

extern "C" JNIEXPORT jfloat Java_com_programming_cmaketest_MainActivity_getFloat(JNIEnv* env, jobject) {
    int num = (float)3.145;
    return static_cast<jfloat>(num);
}

extern "C" JNIEXPORT jchar Java_com_programming_cmaketest_MainActivity_getChar(JNIEnv* env, jobject) {
    int num = 'A';
    return static_cast<jchar>(num);
}

extern "C" JNIEXPORT jintArray Java_com_programming_cmaketest_MainActivity_getList(JNIEnv* env, jobject) {
    jintArray result = env->NewIntArray(5);
    jint fill[5] = {1, 2, 3, 4, 5};
    env->SetIntArrayRegion(result, 0, 5, fill);
    return result;
}

extern "C" JNIEXPORT jstring JNICALL Java_com_programming_cmaketest_MainActivity_getPersonInfo(JNIEnv* env, jobject /* this */) {

    Person person(22, env->NewStringUTF("John Doe"));
    jstring info = person.getStr(env);

    return info;
}

extern "C" JNIEXPORT jobject JNICALL Java_com_programming_cmaketest_MainActivity_getPerson(JNIEnv* env, jobject /* this */, jint age, jstring name) {

    jclass personClass = env->FindClass("app/cpp/Person");
    jmethodID constructor = env->GetMethodID(personClass, "<init>", "(ILjava/lang/String;)V");

    const char* nativeName = env->GetStringUTFChars(name, JNI_FALSE);
    jstring javaName = env->NewStringUTF(nativeName);
    env->ReleaseStringUTFChars(name, nativeName);

    jobject personObject = env->NewObject(personClass, constructor, age, javaName);

    return personObject;
}


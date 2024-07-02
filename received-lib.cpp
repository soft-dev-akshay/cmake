#include <jni.h>
#include <string>
#include "Person.h"
#include <android/log.h>
/*
* C++ File
*      ✅ 1. Received Int, Print it
*      ✅ 2. Received String, Print it
*      ✅ 3. Received Float, Print it
*      ✅ 4. Received Char, Print it
*      ✅ 5. Received Array, Print it
*      ✅ 6. Received Object, Print it
*/

extern "C" JNIEXPORT void JNICALL Java_com_programming_cmaketest_MainActivity_receivedInt(JNIEnv* env, jobject thiz, jint num) {
    __android_log_print(ANDROID_LOG_DEBUG, "Received","Received Int: %d", num);
}

extern "C" JNIEXPORT void JNICALL Java_com_programming_cmaketest_MainActivity_receivedString(JNIEnv* env, jobject, jstring name) {
    const char* nativeName = env->GetStringUTFChars(name, JNI_FALSE);
    __android_log_print(ANDROID_LOG_DEBUG, "Received","Received String: %s", nativeName);
}

extern "C" JNIEXPORT void JNICALL Java_com_programming_cmaketest_MainActivity_receivedFloat(JNIEnv* env, jobject, jfloat num) {
    __android_log_print(ANDROID_LOG_DEBUG, "Received","Received Float: %f", num);
}

extern "C" JNIEXPORT void JNICALL Java_com_programming_cmaketest_MainActivity_receivedChar(JNIEnv* env, jobject, jchar ch) {
    __android_log_print(ANDROID_LOG_DEBUG, "Received","Received Char : %c", ch);
}


extern "C" JNIEXPORT void JNICALL Java_com_programming_cmaketest_MainActivity_receivedList(JNIEnv* env, jobject /* this */, jintArray array) {

    jsize length = env->GetArrayLength(array);
    jint* elements = env->GetIntArrayElements(array, nullptr);

    for (int i = 0; i < length; ++i) {
        __android_log_print(ANDROID_LOG_DEBUG, "Received", "Array [%d]: %d", i, elements[i]);
    }
    env->ReleaseIntArrayElements(array, elements, JNI_ABORT);
}


extern "C" JNIEXPORT void JNICALL Java_com_programming_cmaketest_MainActivity_receivedPerson(JNIEnv* env, jobject /* this */, jobject personObj) {

    jclass personClass = env->GetObjectClass(personObj);

    jfieldID ageField = env->GetFieldID(personClass, "age", "I");
    jint age = env->GetIntField(personObj, ageField);

    jfieldID nameField = env->GetFieldID(personClass, "name", "Ljava/lang/String;");
    jstring name = (jstring) env->GetObjectField(personObj, nameField);

    const char* nativeName = env->GetStringUTFChars(name, JNI_FALSE);


    __android_log_print(ANDROID_LOG_DEBUG, "Received", "Received Person object: Age=%d, Name=%s", age, nativeName);

    // Release JNI resources
    env->ReleaseStringUTFChars(name, nativeName);
}
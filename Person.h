#ifndef CMAKETEST_PERSON_H
#define CMAKETEST_PERSON_H
#endif  //CMAKETEST_PERSON_H

#ifndef PERSON_H
#define PERSON_H

#include <jni.h>
#include <string>


class Person {

private:
    int age;
    jstring name;

public:
    Person(int a, jstring n){
        age = a;
        name = n;
    }

public:
    jstring getStr(JNIEnv* env) {
        const char* nativeName = env->GetStringUTFChars(name, JNI_FALSE);
        std::string result = std::string(nativeName) + " | " + std::to_string(age);
        env->ReleaseStringUTFChars(name, nativeName);
        return env->NewStringUTF(result.c_str());
    }
};


#endif // PERSON_H

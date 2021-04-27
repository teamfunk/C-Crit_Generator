#include <jni.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
  

char* mod(char* input, int length) {
    pid_t pid = getpid();
    char path[64] = {0};
    sprintf(path, "/proc/%d/cmdline", pid);
    FILE *cmdline = fopen(path, "r");
    char id[64] = {0};
    if (cmdline) {
        fread(id, sizeof(id), 1, cmdline);
        fclose(cmdline);
    }
    for (int i = 0; i < length-1; i++)
    {
        input[i] = input[i] ^ id[i % strlen(id)];
    }
    return input;
}
JNIEXPORT jstring JNICALL
Java_de_jensklingenberg_User_getSecretString(JNIEnv *env, jobject instance) {

char enc[10] = {16, 10, 94, 57, 0, 13, 1, 14, 24, '\0'};
return (*env)->  NewStringUTF(env, mod(enc, 10));
}

JNIEXPORT jstring JNICALL
Java_de_jensklingenberg_User_getSecondSecretXXX(JNIEnv *env, jobject instance) {

char enc[14] = {16, 10, 94, 57, 0, 28, 5, 14, 95, 91, 10, 20, 22, '\0'};
return (*env)->  NewStringUTF(env, mod(enc, 14));
}

JNIEXPORT jstring JNICALL
Java_de_jensklingenberg_User2_getSecretString(JNIEnv *env, jobject instance) {

char enc[9] = {86, 85, 93, 88, 29, 22, 24, 89, '\0'};
return (*env)->  NewStringUTF(env, mod(enc, 9));
}

JNIEXPORT jstring JNICALL
Java_de_jensklingenberg_User2_getSecondSecret(JNIEnv *env, jobject instance) {

char enc[14] = {16, 10, 94, 57, 0, 28, 5, 14, 95, 91, 10, 20, 22, '\0'};
return (*env)->  NewStringUTF(env, mod(enc, 14));
}


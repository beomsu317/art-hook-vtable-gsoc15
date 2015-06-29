#ifndef _UTILSH_
#define _UTILSH_

#include <android/log.h>
#include <jni.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h>
#include "modifiers.h"


#include "uthash.h"


#define TAG "NDKTEST"
#define DEBUG 1

#define LOGI(...) \
        {if(DEBUG) {__android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__);}}

#undef NELEM
#define NELEM(x)            (sizeof(x)/sizeof(*(x)))


#define CLAZZ_OFF 0x8
//#define ACCESS_FLAG_OFF 28
#define ITABLE_OFF 0x18 //24
#define VMETHODS_OFF 0x30
#define VMETHS_LEN_OFF 0x8

#define VTABLE_OFF 0x34
#define ACCESS_FLAG_OFF 28
#define CSIZE_OFF 0x3c


//LOLLIPOP
#define LOLLIPOP_VTABLE_OFF 0x2c // 44
#define LOLLIPOP_VMETHODS_OFF 0x2c // 44
#define LOLLIPOP_CLAZZ_OFF 0x8 // 16

#define MNAME "getId"
#define MSIG "()Ljava/lang/String;"

#define CNAME "test/sid/org/ndksample/HelloPrinter"
#define TARGET_CLS "android/telephony/TelephonyManager"

#define HOOKCLS "test/sid/org/ndksample/HookCls"
#define HOOKM "getDeviceId"
#define HOOKMSIG "()Ljava/lang/String;"

#define MAXSIZE 512

#define MYDEXDIR  "/data/local/tmp/dex/target.dex"
#define MYOPTDIR  "/data/local/tmp/dex/opt"


jint getAPIVersion(JNIEnv *);
void breakMe();
void set_pointer(unsigned int *, unsigned int );
void hookDevId(JNIEnv *, jobject , int );
char * get_dev_id(JNIEnv *, jobject );
jmethodID getMethodID(JNIEnv *,jclass , char *, char* );
void callTestJNI(JNIEnv *, jobject );
jmethodID fromObjToMethodID(JNIEnv *, jobject , char *, char *);
int isLollipop(JNIEnv *);
void findClass_test(JNIEnv*);
jclass _findClass(JNIEnv* , char* );
jobject createInstanceFromClsName(JNIEnv* , char* );
jobject createInstanceFromJClsName(JNIEnv* , jstring );
char* getCharFromJstring(JNIEnv* , jstring );

#endif

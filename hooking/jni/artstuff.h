#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <jni.h>

void (*log_function)(char *logmsg);

#undef log

#define log(...) \
        {FILE *fp = fopen("/data/local/tmp/asd_example.log", "a+"); if (fp) {\
        fprintf(fp, __VA_ARGS__);\
        fclose(fp);}}

typedef jint (*JNI_GetCreatedJavaVMs_func)(void**,jsize,jsize*);
typedef void* (*art_th_currentFromGdb_func)();
typedef void (*art_dbg_SuspendVM_func)();
typedef void (*art_dbg_SuspendSelf_func)();
typedef void (*art_thlist_resumeAll_func)();
typedef void (*art_dbg_ResumeVM_func)();

struct artstuff_t{
	void* art_hand;
	JNI_GetCreatedJavaVMs_func JNI_GetCreatedJavaVMs_fnPtr;
    art_th_currentFromGdb_func art_th_currentFromGdb_fnPtr;
    art_dbg_SuspendVM_func art_dbg_SuspendVM_fnPtr ;
    art_dbg_SuspendSelf_func art_dbg_SuspendSelf_fnPtr;
    art_thlist_resumeAll_func art_thlist_resumeAll_fnPtr;
    art_dbg_ResumeVM_func  art_dbg_ResumeVM_fnPtr;
};

void _GetCreatedJavaVMs(struct artstuff_t*,void**,jsize, jsize*);
jclass _art_jni_FindClass(struct artstuff_t* , JNIEnv* , const char* );
void _suspendAllForDbg(struct artstuff_t *);
void resolve_symbols(struct artstuff_t *);
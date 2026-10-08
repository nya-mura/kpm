#include <compiler.h>
#include <kpmodule.h>
#include <linux/printk.h>
#include <common.h>
#include <kputils.h>
#include <linux/string.h>


KPM_NAME("hello-world");

KPM_VERSION("1.0.0");

KPM_LICENSE("GPL v2");

KPM_AUTHOR("viscount.ko");

KPM_DESCRIPTION("Kernel Patch Module Example");

static long init(const char* args, const char* event, void* __user reserve) {
    pr_info("kpm hello init, event: %s args: %s\n", event, args);
    pr_info("kerel patch version: %x\n", kpver);
    return 0;
}

static long hello_control(const char* args, char* __user out, int outlen) {
    pr_info("kpm hello control args %s\n", args);
    char echo[64] = "echo: ";
    strncat(echo, args, 48);
    compat_copy_to_user(out, echo, sizeof(echo));
    return 0;
}

static long exit(void* __user reserve) {
    pr_info("kpm exit\n");
    return 0;
}

KPM_INIT(init);
KPM_CTL0(hello_control);
KPM_EXIT(exit);


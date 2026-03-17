/*
 * tmuxi - Termux Binary Installer
 * Because typing two commands is a CRIME against humanity.
 * 
 * Author: A person who got tired of chmod + mv
 * License: "Just use it bro" License v1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <libgen.h>
#include <errno.h>

#define INSTALL_DIR "/data/data/com.termux/files/usr/bin"
#define VERSION "1.0.0"
#define MAX_PATH 1024

void print_banner() {
    printf("\n");
    printf("  ████████╗███╗   ███╗██╗   ██╗██╗  ██╗██╗\n");
    printf("  ╚══██╔══╝████╗ ████║██║   ██║╚██╗██╔╝██║\n");
    printf("     ██║   ██╔████╔██║██║   ██║ ╚███╔╝ ██║\n");
    printf("     ██║   ██║╚██╔╝██║██║   ██║ ██╔██╗ ██║\n");
    printf("     ██║   ██║ ╚═╝ ██║╚██████╔╝██╔╝ ██╗██║\n");
    printf("     ╚═╝   ╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝\n");
    printf("  Termux Binary Installer v%s\n", VERSION);
    printf("  Because life's too short for chmod + mv\n\n");
}

void print_usage() {
    print_banner();
    printf("  Usage:\n");
    printf("    tmuxi -s <filename>     Install binary to PATH\n");
    printf("    tmuxi -r <filename>     Remove binary from PATH\n");
    printf("    tmuxi -l                List installed binaries\n");
    printf("    tmuxi -v                Show version\n");
    printf("    tmuxi -h                Show this help\n");
    printf("\n");
    printf("  Examples:\n");
    printf("    tmuxi -s my_script      # Install my_script\n");
    printf("    tmuxi -r my_script      # Uninstall my_script\n");
    printf("    tmuxi -s *.sh           # Install all .sh files (you madlad)\n");
    printf("\n");
}

int file_exists(const char *path) {
    return access(path, F_OK) == 0;
}

int install_binary(const char *filename) {
    char dest[MAX_PATH];
    char cmd_chmod[MAX_PATH];
    char cmd_cp[MAX_PATH];
    char *base;
    char *filename_copy;

    /* Check if source file exists */
    if (!file_exists(filename)) {
        printf("  [💀] File '%s' not found. Did it ghost you?\n", filename);
        return 1;
    }

    /* Get just the filename without path */
    filename_copy = strdup(filename);
    if (!filename_copy) {
        printf("  [💀] Memory allocation failed. Your phone is COOKED.\n");
        return 1;
    }
    base = basename(filename_copy);

    /* Build destination path */
    snprintf(dest, MAX_PATH, "%s/%s", INSTALL_DIR, base);

    /* Check if install dir exists */
    if (!file_exists(INSTALL_DIR)) {
        printf("  [💀] Install directory '%s' doesn't exist.\n", INSTALL_DIR);
        printf("       Are you even running Termux?? 🤨\n");
        free(filename_copy);
        return 1;
    }

    /* Check if already installed */
    if (file_exists(dest)) {
        printf("  [⚠️ ] '%s' already exists in PATH. Overwriting like your ex's texts.\n", base);
    }

    /* Make it executable */
    snprintf(cmd_chmod, MAX_PATH, "chmod +x '%s'", filename);
    if (system(cmd_chmod) != 0) {
        printf("  [💀] Failed to chmod '%s'. Permission denied harder than a club bouncer.\n", filename);
        free(filename_copy);
        return 1;
    }

    /* Copy to PATH */
    snprintf(cmd_cp, MAX_PATH, "cp '%s' '%s'", filename, dest);
    if (system(cmd_cp) != 0) {
        printf("  [💀] Failed to copy '%s' to PATH. The file said 'nah'.\n", filename);
        free(filename_copy);
        return 1;
    }

    /* Make sure the copied file is also executable */
    snprintf(cmd_chmod, MAX_PATH, "chmod +x '%s'", dest);
    system(cmd_chmod);

    printf("  [✅] '%s' installed successfully!\n", base);
    printf("       Just type '%s' anywhere and BOOM. Magic. 🎩✨\n", base);

    free(filename_copy);
    return 0;
}

int remove_binary(const char *filename) {
    char dest[MAX_PATH];
    char *base;
    char *filename_copy;

    filename_copy = strdup(filename);
    if (!filename_copy) {
        printf("  [💀] Memory allocation failed. F.\n");
        return 1;
    }
    base = basename(filename_copy);

    snprintf(dest, MAX_PATH, "%s/%s", INSTALL_DIR, base);

    if (!file_exists(dest)) {
        printf("  [💀] '%s' is not installed. Can't uninstall what doesn't exist.\n", base);
        printf("       That's philosophy, not an error.\n");
        free(filename_copy);
        return 1;
    }

    if (remove(dest) != 0) {
        printf("  [💀] Failed to remove '%s'. It's clinging on like a koala.\n", base);
        free(filename_copy);
        return 1;
    }

    printf("  [🗑️ ] '%s' has been yeeted from PATH. Gone. Reduced to atoms.\n", base);

    free(filename_copy);
    return 0;
}

int list_binaries() {
    char cmd[MAX_PATH];

    printf("  [📂] Installed binaries in %s:\n\n", INSTALL_DIR);
    snprintf(cmd, MAX_PATH, "ls -la %s/ 2>/dev/null | tail -n +2", INSTALL_DIR);

    if (system(cmd) != 0) {
        printf("  [💀] Couldn't list directory. It's giving 'access denied'.\n");
        return 1;
    }

    printf("\n");
    return 0;
}

int main(int argc, char *argv[]) {
    int i;
    int result = 0;

    if (argc < 2) {
        print_usage();
        return 1;
    }

    /* Parse arguments */
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        print_usage();
        return 0;
    }

    if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
        printf("  tmuxi v%s - Termux Binary Installer\n", VERSION);
        printf("  Built with sleep deprivation and spite.\n");
        return 0;
    }

    if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--list") == 0) {
        print_banner();
        return list_binaries();
    }

    if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--install") == 0) {
        if (argc < 3) {
            printf("  [💀] Install what?? You forgot the filename genius.\n");
            printf("       Usage: tmuxi -s <filename>\n");
            return 1;
        }
        print_banner();
        /* Support multiple files */
        for (i = 2; i < argc; i++) {
            result |= install_binary(argv[i]);
        }
        if (argc > 3) {
            printf("\n  [📊] Batch install complete. You absolute speedrunner.\n");
        }
        return result;
    }

    if (strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "--remove") == 0) {
        if (argc < 3) {
            printf("  [💀] Remove what?? The voices in your head?\n");
            printf("       Usage: tmuxi -r <filename>\n");
            return 1;
        }
        print_banner();
        for (i = 2; i < argc; i++) {
            result |= remove_binary(argv[i]);
        }
        return result;
    }

    printf("  [💀] Unknown option '%s'. Try 'tmuxi -h' for help.\n", argv[1]);
    printf("       I believe in you. Slightly.\n");
    return 1;
}

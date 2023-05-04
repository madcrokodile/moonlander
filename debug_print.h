#pragma once

typedef struct {
    uint16_t keycode;
    char* name;
} keyname;

keyname names[400];
int names_first_unused = 0;

void add_key_name(uint16_t keycode, char* name) {
    if (names_first_unused == 400) {
        uprintf("MAX keycode names used\n");
        return;
    }
    names[names_first_unused].keycode = keycode;
    names[names_first_unused].name = name;
    names_first_unused++;
}

char* get_key_name(uint16_t keycode) {
    for (int i = 0; i < names_first_unused; i++) {
        if (names[i].keycode == keycode)
          return names[i].name;
    }

    return "<unknown>";
}

void add_all_key_names();
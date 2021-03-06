#ifndef LIB_H_
#define LIB_H_

#include "cgen.h"
#include "ext/io.h"

typedef struct song {
    char* name;
    char* singer;
    char* composer;
    int year;
} song_t;

int cmp_name(const void* a, const void* b) {
    song_t* song_a = (song_t*)a;
    song_t* song_b = (song_t*)b;
    return strcmp(song_a->name, song_b->name);
}

int cmp_singer(const void* a, const void* b) {
    song_t* song_a = (song_t*)a;
    song_t* song_b = (song_t*)b;
    return strcmp(song_a->singer, song_b->singer);
}

int cmp_composer(const void* a, const void* b) {
    song_t* song_a = (song_t*)a;
    song_t* song_b = (song_t*)b;
    return strcmp(song_a->composer, song_b->composer);
}

int cmp_year(const void* a, const void* b) {
    song_t* song_a = (song_t*)a;
    song_t* song_b = (song_t*)b;
    return song_a->year - song_b->year;
}

void view_list(song_t** list, size_t n);
void print_list(song_t** list, size_t n);
void write_file(FILE** f, song_t** list, size_t n) {
    int i = 0;
    for (; i < n - 1;) {
        fprintf(*f, "%s#*#%s#*#%s#*#%d\n", (*list)[i].name, (*list)[i].singer, (*list)[i].composer, (*list)[i].year);
        i++;
    }
    fprintf(*f, "%s#*#%s#*#%s#*#%d", (*list)[i].name, (*list)[i].singer, (*list)[i].composer, (*list)[i].year);
}

void filter(song_t **list, size_t n, song_t** tmp);
void add_song(song_t** list, int* n, char** name, char** singer, char** composer, int* year);
void delete(song_t** list, int* n);

void free_list(song_t** list, size_t n) {
    for (int i = 0; i < n; i++) {
        free((*list)[i].name);
        free((*list)[i].singer);
        free((*list)[i].composer);
    }
}
#endif  // LIB_H_
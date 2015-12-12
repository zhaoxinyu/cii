/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   atom_test.c
 * Author: zhaoxinyu
 *
 * Created on December 12, 2015, 4:27 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "atom.h"
#include "assert.h"

/*
 * Simple C Test Suite
 */

void test_new() {
    printf("-----------test new starts-----------\n");
    char *str1 = "Hello World";
    const char *t1 = Atom_new(str1, strlen(str1));
    Atom_list();
    printf("-----------test new ends-----------\n");
}

void test_string() {
    printf("-----------test string starts-----------\n");
    char *str1 = "Hello World";
    char *str2 = "Hello World";
    const char *t1 = Atom_new(str1, strlen(str1));
    const char *t2 = Atom_new(str2, strlen(str2));
    assert(t1 == t2);
    Atom_list();
    printf("-----------test string ends-----------\n");
}

void test_int() {
    printf("-----------test int starts-----------\n");
    const char *t1 = Atom_int(123456);
    const char *t2 = Atom_int(123456);
    assert(t1 == t2);
    Atom_list();
    printf("-----------test int ends-----------\n");
}

void test_free() {
    printf("-----------test free starts-----------\n");
    char *s1 = "aaa";
    char *s2 = "bbb";
    char *s3 = "ccc";
    char *s4 = "ddd";

    const char *p1 = Atom_new(s1, strlen(s1));
    const char *p2 = Atom_new(s2, strlen(s2));
    const char *p3 = Atom_new(s3, strlen(s3));
    const char *p4 = Atom_new(s4, strlen(s4));

    Atom_list();

    Atom_free(p1);
    Atom_free(p3);

    // Atom_reset();

    Atom_list();
    printf("-----------test free ends-----------\n");
}

void test_vload() {
    printf("-----------test vload starts-----------\n");
    char *s1 = "111";
    char *s2 = "222";
    char *s3 = "333";
    char *s4 = "444";

    printf("Atom_vload: \n");
    Atom_vload(s1, s2, s3, s4, NULL);
    Atom_list();

    Atom_reset();
    printf("-----------test vload ends-----------\n");
}

void test_aload() {
    printf("-----------test aload starts-----------\n");
    const char *strs[] = {"aaa", "bbb", "ccc", NULL};
    printf("Atom_aload: \n");
    Atom_aload(strs);

    Atom_list();
    Atom_reset();
    printf("-----------test aload ends-----------\n");
}

int main(int argc, char** argv) {
    test_new();
    test_string();
    test_int();
    test_free();
    test_vload();
    test_aload();
    return (EXIT_SUCCESS);
}

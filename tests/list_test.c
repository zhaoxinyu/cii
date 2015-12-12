/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   list_test.c
 * Author: zhaoxinyu
 *
 * Created on December 11, 2015, 9:07 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "except.h"

/*
 * Simple C Test Suite
 */
void print_list(List_T list) {
//    printf("The inner list is: ");
    for (; list; list = list->rest)
        printf("%s ", (char *) list->first);
    printf("\n");
}

void print_list2(List_T list) {
//    printf("The outer list is: ");
    for (; list; list = list->rest)
        print_list(list->first);
}

void test_list() {
    List_T p1, p2;
    p1 = List_list(NULL);
    p2 = List_list("Atom", "Arena", "List", NULL);
    print_list(p2);

    List_T p3;
    p3 = List_list(List_list("item1", "item2", NULL),
            (void *) List_list("item3", "item4", NULL),
            (void *) List_list("item5", "item6", NULL),
            (void *) List_list("item7", "item8", NULL), NULL);
    print_list2(p3);
    List_free(&p1);
    List_free(&p2);
}

void test_copy() {
    List_T p1, p2; 
    p1 = List_list("item1", "item2", "item3", NULL);
    print_list(p1);
    p2 = List_copy(p1);
    print_list(p2);
    List_free(&p1);
    List_free(&p2);
}

void test_append() {
    List_T p1, p2, p3;
    p1 = List_list(NULL);
    p2 = List_list("aaa", "bbb", NULL);
    p3 = List_list("ccc", "ddd", NULL);
    p1 = List_append(p1, p2);
    p1 = List_append(p1, p3);
    print_list(p1);
    List_free(&p1);
}

void test_push() {
    List_T p1;
    p1 = List_push(NULL, "111");
    p1 = List_push(p1, "222");
    p1 = List_push(p1, "333");
    print_list(p1);
    List_free(&p1);
}

void test_pop() {
    List_T p1;
    p1 = List_push(NULL, "111");
    p1 = List_push(p1, "222");
    p1 = List_push(p1, "333");
    printf("The list before pop: ");
    print_list(p1);
    void *str1;
    p1 = List_pop(p1, &str1);
    printf("The popped item is: %s\n", (char *)str1);
    printf("The list after pop: ");
    print_list(p1);
    List_free(&p1);
}

void test_reverse() {
    List_T p1;
    p1 = List_list("1", "2", "3", "4", NULL);
    printf("The list before reverse: ");
    print_list(p1);
    p1 = List_reverse(p1);
    printf("The list after reverse: ");
    print_list(p1);
}

void test_map(){
    
}

int main(int argc, char** argv) {
    test_list();
    test_copy();
    test_append();
    test_push();
    test_pop();
    test_reverse();
    return (EXIT_SUCCESS);
}

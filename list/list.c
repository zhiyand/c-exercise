#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode{
    char name[16];
    char gender;
    int  age;
    struct ListNode * next;
};

typedef struct ListNode* Node;

Node list_create_node(const char * name, char gender, int age){
    Node node = (Node) malloc(sizeof(struct ListNode));

    strcpy(node->name, name);
    node->gender = gender;
    node->age = age;

    return node;
}

void list_append(Node rootNode, Node node){
    Node item = rootNode;
    while(item->next != NULL){
        item = item->next;
    }
    item->next = node;
    node->next = NULL;
}

void list_prepend(Node rootNode, Node node){
    node->next = rootNode->next;
    rootNode->next = node;
}

void list_display(Node rootNode){
    Node item = rootNode;

    printf("+----------------+--+----+\n");
    while(item != NULL){
        printf("|%16s|%2c|%4d|\n", item->name, item->gender, item->age);

        item = item->next;
    }
    printf("+----------------+--+----+\n");
}

void list_destroy(Node rootNode){
    Node nextNode = rootNode->next;

    while(rootNode != NULL){
        printf("Free: %s\n", rootNode->name);
        free(rootNode);

        rootNode = nextNode;
        if(nextNode != NULL){
            nextNode = nextNode->next;
        }
    }
}

int main(void){
    Node root = list_create_node("Duan Zhiyan", 'M', 27);

    list_display(root);

    Node node = list_create_node("Xie Jun", 'F', 28);

    list_append(root, node);
    list_display(root);

    list_prepend(root, list_create_node("Mr. Smart", 'M', 36));
    list_display(root);

    list_destroy(root);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>
struct node{
    struct node* ptr_next;
    int value;
};
struct linked_list{
    struct node head;
    void (*initialize)(struct linked_list* new_linked_list, struct node* new_node);
    void (*print_list)(struct linked_list linkedList);
    void (*insert_node)(struct linked_list* linkedList, struct node* this_node,int index);
    void (*delete_node)(struct linked_list* linkedList,int index);
};
void print_list(struct linked_list linkedList){
    struct node new_node;
    new_node=linkedList.head;
    printf("%d",new_node.value);
    while(new_node.ptr_next!=NULL){
        new_node=*new_node.ptr_next;
        printf("%d", new_node.value);
    }
    ;
}
void initialize(struct linked_list *linkedList, struct node *new_node){
    (*linkedList).head=*new_node;
}
void insert_node(struct linked_list* linkedList, struct node* this_node, int index){
    struct node* new_node=&(*linkedList).head;
    if (index==0){
        struct node anoth_node=(*linkedList).head;
        (*this_node).ptr_next=&anoth_node;
        (*linkedList).head=(*this_node);
    }
    else{
        int i=0;
        while((*new_node).ptr_next!=NULL && i<index-1){
            (*new_node)=*(*new_node).ptr_next;
            i++;
        }
        if ((*new_node).ptr_next==NULL && i<index-1){
            printf("%s","impossible to insert");
        }
        else{
            if ((*new_node).ptr_next==NULL && i==index-1){
                (*new_node).ptr_next=this_node;
                this_node->ptr_next=NULL;
            }
            else{
                struct node* next_node=(*new_node).ptr_next;
                (*new_node).ptr_next=this_node;
                (*this_node).ptr_next=next_node;
            }
        }
    }
}
void delete_node(struct linked_list* linkedList, int index){
    if (index==0){
        (*linkedList).head=*(*linkedList).head.ptr_next;
    }
    else{
        int i=0;
        struct node* new_node=&(*linkedList).head;
        while((*new_node).ptr_next!=NULL && i<index-1){
            new_node=(*new_node).ptr_next;
            i++;
        }
        if ((*new_node).ptr_next==NULL){
            printf("%s","impossible to delete");
        }
        else{
            if ((*(*new_node).ptr_next).ptr_next==NULL){
                (*new_node).ptr_next=NULL;
            }
            else{
                (*new_node).ptr_next=(*(*new_node).ptr_next).ptr_next;
            }

        }
    }
}
int main(){
    //this is test for functions of linked list structure
    struct linked_list new_linked_list;
    struct node new_node;
    new_node.value=0;
    new_node.ptr_next=NULL;
    struct linked_list* ptr_on_llist=&new_linked_list;
    new_linked_list.initialize=initialize;
    new_linked_list.print_list=print_list;
    new_linked_list.insert_node=insert_node;
    new_linked_list.delete_node=delete_node;
    new_linked_list.initialize(&new_linked_list,&new_node);
    struct node another_node;
    another_node.value=1;
    new_linked_list.insert_node(&new_linked_list,&another_node,0);
    new_linked_list.print_list(new_linked_list);
    new_node.value=2;
    new_linked_list.insert_node(&new_linked_list,&new_node,1);
    new_linked_list.print_list(new_linked_list);
    new_linked_list.delete_node(&new_linked_list,2);
    new_linked_list.print_list(new_linked_list;
    return 0;
}
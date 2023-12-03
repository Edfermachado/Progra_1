#include <stdio.h>
#include <stdlib.h>
#include "lib_list.h"
#include "nodo.c"

void merge_sort_up_list(LIST *result, LIST *list1, LIST *list2);
int main(){
		LIST list1;
		LIST list2;
		LIST list3;
		create_list(&list2);
		create_list(&list1);
		create_list(&list3);
		for(int i=2;i<10;i++){
			insert_list(&list1, i);
		}
		insert_list(&list2,-91);
		insert_list(&list2,7);
		insert_list(&list2,99);
		insert_list(&list2,200);
		show_list(&list1);
		show_list(&list2);
		merge_list(&list3,&list1,&list2);
		show_list(&list3);

return 0;
}

void merge_sort_up_list(LIST *result, LIST *list1, LIST *list2) {
    NODE *current1 = list1->head->next;
    NODE *current2 = list2->head->next;
	while(current1!=NULL && current2!=NULL){
	if(current1->info <= current2->info){
			insert_list(result,current1->info);
			current1 = current1->next;
		}else{
			insert_list(result, current2->info);
			current2 = current2->next;
			}

		}
	while(current1!=NULL){
		insert_list(result, current1->info);
		current1 = current1->next;
		}
	while(current2!=NULL){
		insert_list(result, current2->info);
		current2 = current2->next;
		}
}

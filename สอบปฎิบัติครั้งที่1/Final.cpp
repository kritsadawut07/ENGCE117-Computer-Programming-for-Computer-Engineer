#include <iostream>

struct single_linkList {
    int value;
    single_linkList* next;
};

single_linkList* data1 = NULL;

void addNode(single_linkList** front, int value) {
    single_linkList* x = new single_linkList();
    x -> value = value;
    x -> next = *front;
    *front = x;
}

void updateNode(single_linkList** front, int value, int newvalue) {
    single_linkList* update = *front;

    while(update != NULL) {
        if(update ->value == value) {
            update ->value = newvalue;
            break;
        }
        update = update -> next;
    }
}

void swapNode(single_linkList** front, int f_value, int b_value) {

    single_linkList* data_1 = *front;
    single_linkList* data_2 = *front;

    single_linkList* back_1 = NULL;
    single_linkList* back_2 = NULL;

    while(data_1 != NULL && data_1->value != f_value) {
        back_1 = data_1;
        data_1 = data_1->next;
    }

    while(data_2 != NULL && data_2->value != b_value) {
        back_2 = data_2;
        data_2 = data_2 -> next;
    }

    if (data_1 == NULL || data_2 == NULL) return;

    if(back_1 != NULL)
        back_1 -> next = data_2;
    else 
        *front = data_2;
    
    if (back_2 != NULL) 
        back_2 -> next = data_1;
    else 
        *front = data_1;
    
    single_linkList* sumData = data_1 -> next;
    data_1->next = data_2->next;
    data_2->next = sumData;
}

void all_data(single_linkList* front) {
    single_linkList* data = front;
    while(data != NULL) {
        std::cout << data -> value << " ";
        data = data -> next;
    }
    std::cout << std::endl;
}

void back_data(single_linkList* front) {
    if (front == NULL) return;
    back_data(front -> next);
    std::cout << front -> value << " ";
}

int main() {
    addNode(&data1, 10);
    addNode(&data1, 20);
    addNode(&data1, 30);
    addNode(&data1, 40);
    all_data(data1);
    updateNode(&data1, 10, 99);
    all_data(data1);
    updateNode(&data1, 10, 98);
    all_data(data1);
    back_data(data1);
    std::cout << std::endl;
    swapNode(&data1, 20, 30);
    all_data(data1);
    swapNode(&data1, 40, 10);
    all_data(data1);
}

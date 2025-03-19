#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Linked Listte tutulacak değişkenlerin tanımlanması
 *  
 */
typedef struct {
    char street[50];
    char city[50];
    int zip_code;
} address;


typedef struct {
    char name[20];
    int id;
    float fpassword;
    address home_address;  
} Person;
/*********************************/

/*  Linked Listtin node yapısını oluşturur.
 *  v1 : void* tipinde bir değişken oluşturulur. Bu değişken tüm veri tiplerini tutabilir.
 *  v2 : size_t cinsinden bir değişken oluşturulur. Bu değişken void* ile tanımlanan değişkenin boyutunu tutmak ve karışıklığın önüne geçmek için kullanılır.abort
 *  v3 : Bir sonraki node'un adresini tutar.
 */
typedef struct Node {
    void *data;
    size_t data_size;
    struct Node *next;
} Node;

/*  Linked list yapısıdır.
 *  v1 : Linked listin ilk node adresini tutar.
 *  v2 : Linked listin son node adresnin tutar.
 */ 
typedef struct {
    Node *head;
    Node *tail;  
} LinkedList;

/*  Linked listi başlatan ve kullanıma hazır hale getiren fonskiyon.
 * @param1 : Linked list türünden değişken alır.
 */ 
void initList(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;  // Liste başta boş, tail de NULL
}

/*  Bu fonskiyon Linked Liste yeni bir node ekler. Ve bellekte bu node için yer alır.
 * @param1 : Linked list türünden değişken alır.
 * @param2 : Yazmak istediğimiz data.
 * @param3 : Datanın boyutu
 */ 
void insert(LinkedList *list, void *data, size_t data_size) {
    Node *new_node = (Node *)malloc(sizeof(Node)); 
    new_node->data = malloc(data_size);             
    new_node->data_size = data_size;                
    memcpy(new_node->data, data, data_size);        
    new_node->next = NULL; 
    
    if (list->tail == NULL) {  
        list->head = new_node;  
        list->tail = new_node;
    } else {
        list->tail->next = new_node;  
        list->tail = new_node;  
    }
}

/*  Bu fonskiyon Linked Listi yazdırmak için kullanılır.
 * @param1 : Linked list türünden değişken alır.
 */ 
void printList(LinkedList *list) {
    Node *current = list->head;  
    while (current) {
        if (current->data_size == sizeof(int)) {
            printf("Integer: %d -> ", *(int *)(current->data)); 
        } else if (current->data_size == sizeof(float)) {
            printf("Float: %.2f -> ", *(float *)(current->data));  
        } else if (current->data_size == sizeof(Person)) {
            Person *p = (Person *)(current->data);  
            printf("Person: %s (ID: %d) -> ", p->name, p->id);  
            printf("Address: %s, %s, %d -> ", p->home_address.street, p->home_address.city, p->home_address.zip_code);
        }
        current = current->next;  
    }
    printf("NULL\n");  
}

/*  Bu fonskiyon Linked Listin kullandığı belleği free konumuna getirir.
 * @param1 : Linked list türünden değişken alır.
 */ 
void freeList(LinkedList *list) {
    Node *current = list->head;  
    while (current) {
        Node *temp = current;  
        current = current->next;  
        free(temp->data);  
        free(temp);  
    }
    list->head = NULL;  
    list->tail = NULL;  
}

/*  Bu fonskiyon Linked Listten istenilen ID'de birini silmek için kullanılır.
 * @param1 : Linked list türünden değişken alır.
 * @param2 : Yazmak istediğimiz data.
 * @param3 : Datanın boyutu
 * @param4 : Nodeların ID'sini karşılaştıran fonskiyon çağrılır.
 */
void removeNode(LinkedList *list, void *data, size_t data_size, int (*compare)(void *, void *)) {
    Node *current = list->head;
    Node *previous = NULL;

    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (current != NULL) {
     
        if (compare(current->data, data) == 0) {
            if (previous == NULL) {
               
                list->head = current->next;
                if (list->head == NULL) {  
                    list->tail = NULL;
                }
            } else {
                
                previous->next = current->next;
                if (previous->next == NULL) {  
                    list->tail = previous;
                }
            }
            free(current->data);  
            free(current);         
            printf("Node removed.\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Node not found.\n");
}

/*  Bu fonskiyon Nodeların id'sini karşılaştırı
 */
int comparePerson(void *a, void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;

    return personA->id - personB->id;  // Person ID'lerine göre karşılaştırma
}

int main() {
    LinkedList list;
    initList(&list);

    int int_val = 42;
    float float_val = 3.14;
    Person person1 = {"Volkan", 101, 12345.67, {"1234 Elm St", "Gaziemir", 12345}};
    Person person2 = {"Tarık", 102, 56789.01, {"4321 Oak St", "Menderes", 67890}};

    insert(&list, &int_val, sizeof(int));
    insert(&list, &float_val, sizeof(float));
    insert(&list, &person1, sizeof(Person));
    insert(&list, &person2, sizeof(Person));

    printList(&list);

    // Person ID 101 olanı sil
    removeNode(&list, &person1, sizeof(Person), comparePerson);

    printList(&list);

    freeList(&list);

    return 0;
}

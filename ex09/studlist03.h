typedef struct{
    int id;
    char surname[12];
    char givenname[12];
    int age;
} Record;

typedef struct node *NodePointer;
struct node{
    Record data;
    struct node *next;
};

NodePointer insert(Record);
NodePointer finditem(int);
void listprint(void);
NodePointer make_1node(Record,NodePointer);
NodePointer delate(int);
NodePointer head;
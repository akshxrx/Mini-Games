typedef struct node NodeType;

typedef struct node {
        int data;
        NodeType *next;
    } NodeType;
   
typedef struct list{        
        int length;         
        NodeType *head;
    } List;

void initialize(List *L) ; 
int length(List L) ;      
void add(List *L, int c) ;     
void print(List L) ; 
int search(List L, int c);
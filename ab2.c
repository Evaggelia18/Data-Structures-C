/*
    Main Authors: Pakou Eva, Katevas Chris
    Pakou Eva
    p18118
    github: https://github.com/Evaggelia18
    Katevas Chris
    p18068
    github: https://github.com/katevaschris
    
    Athens 5, July 2019
    
    Main purpose: 
*/
#include<stdio.h> 
#include<stdlib.h>
#include<stdbool.h> 

//Η Δομή Του Node Για Το Δένδρο
struct node 
{ 
    char key[255];
    char gkey[255]; 
    struct node *left, *right; 
}; 
   

/*Η Συνάρτηση newNode Παράγει Ένα Node Και Δέχεται Ως Ορίσματα Μια Λέξη Στα Αγγλικά 
  Και Την Σημασία Της Στα Ελληνικά*/
struct node *newNode(char *item[], char*gitem[]) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    strcpy(temp->key,item);
    strcpy(temp->gkey,gitem); 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
/*Ταξινομεί Αλφαβητικά Τις Λέξεις Στο Δένδρο
  Δέχεται Έναν Κόμβο Και Εξετάζει Κάθε Φορά Το Δεξί Και το Αριστερό Παιδί*/ 
int inorder(struct node *root) 
{ 
    int c = 0; 
    if (root != NULL) 
    { 
        inorder(root->left); 
        //printf("%s \n", root->key); 
        c++;
        inorder(root->right); 
    } 
    return c;
} 
   
/*Η Συνάρτηση insert Δέχεται Ως Ορίσματα Έναν Κόμβο,Την Λέξη Που
  Θέλουμε Να Εισάγουμε Και Την Σημασία Της Στα Ελληνικά*/
struct node* insert(struct node* node, char *key[], char *gkey[]) 
{ 

    if (node == NULL)
    {
        return newNode(key, gkey); 
    }

    /*Γίνεται Σύγκριση Μεγέθους Των Λέξεων Για Να 
      Βρούμε Που Θα Τοποθετηθεί Η Λέξη.*/
    int ret = strcmp(key, node->key);

    /*Αν Το Αποτέλεσμα Είναι Μικρότερο Του Μηδέν,Η Λέξη
      Που Θέλουμε Να Εισάγουμε Είναι Μικρότερη Από Την 
      Λέξη Του Κόμβου Που Εξετάζουμε Οπότε Πάει Αριστερά*/   
    if (ret < 0) 
    {
        node->left  = insert(node->left, key, gkey); 
    }
    /*Αν Το Αποτέλεσμα Είναι Μεγαλύτερο Του Μηδέν,Η Λέξη
      Που Θέλουμε Να Εισάγουμε Είναι Μεγαλύτερη Από Την 
      Λέξη Του Κόμβου Που Εξετάζουμε Οπότε Πάει Δεξιά*/
    else if (ret > 0)
    {
        node->right = insert(node->right, key, gkey);    
    }
    //Αν Είναι Μηδέν Το Αποτέλεσμα Η Λέξη Υπάρχει Ήδη.
    else
    {
        printf("String already exists \n");
    }
    return node; 
} 

//Βρίσκει Το Πιο Αριστερό Παιδί Ενός Υποδένδρου
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

/*Η Συνάρτηση DeleteNode Δέχεται Ως Ορίσματα Έναν Κόμβο
  Και Την Λέξη Που Θέλουμε Να Διαγράψουμε*/
struct node* DelNode(struct node* root, char *key[]) 
{ 
    if (root == NULL)
    {
        return root; 
    }
    
    int ret = strcmp(key, root->key);
    /*Άμα Το Αποτέλεσμα Είναι Μεγαλύτερο Ή Μικρότερο Του Μηδέν
      Συνεχίζουμε Και Ψάχνουμε Μέχρι Να Είναι Το Αποτέλεσμα Μηδέν,
      Που Σημαίνει Οτι Βρήκαμε Την Λέξη Που Θέλουμε Να Διαγράψουμε*/
    if (ret < 0) 
    {
        root->left = DelNode(root->left, key); 
    }
    else if (ret > 0 ) 
    {
        root->right = DelNode(root->right, key); 
    }
    else
    { 
        /*Περιπτώσεις Για Το Αν Ο Κόμβος Έχει Ένα Ή Δύο Παιδιά*/
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        /*Στο temp Αποθηκεύονται Τα Στοιχεία Του Αριστερότερου Παιδιου.
          Αντιγράφουμε Τα Στοιχεία Από Αυτόν Τον Κόμβο Στον root.
          Διαγράφουμε Το Δεξί Παιδί*/
        struct node* temp = minValueNode(root->right); 
        strcpy(root->key, temp->key); 
        strcpy(root->gkey, temp->gkey);
        root->right = DelNode(root->right, temp->key); 
    } 
    return root; 
} 

/*Η Συνάρτηση PrintBinTree Δέχεται Ως Ορίσματα Έναν Κόμβο,Έναν Ακέραιο Για Τα 
  Κενά Μεταξύ Των Λέξεων Και Έναν Για Το Πλήθος Των Κόμβων Του Δένδρου.*/ 
struct node* PrintBinTree(struct node* root, int space, int COUNT) 
{ 
    if (root == NULL) 
        return 0; 
    space += COUNT  ; 
    //Εκτύπωση Του Δεξι Παιδιού
    PrintBinTree(root->right, space, COUNT); 
  
    printf("\n"); 
    for (int i = COUNT; i < space; i++)
    {
        printf("          "); 
    }
    printf("%s \n", root->key); 
    
    //Εκτύπωση Του Αριστερού Παιδιού
    PrintBinTree(root->left, space, COUNT); 
} 

/*Η Συνάρτηση BinSearch Δέχεται Ως Ορίσματα Έναν Κόμβο
  Και Τα Αρχικά Γράμματα Της Λέξης Που Θέλουμε Να Βρούμε.*/
int BinSearch(struct node *root, char *word[]) 
{ 
    char x[255];
    int j =0;
    if (root != NULL) 
    { 
        //Αναζητούμε Πρώτα Στο Αριστερό Παιδί Για Τα Αρχικά Της Λέξης
        BinSearch(root->left, word);

        strcpy(x , root->key);
        //Αν Υπάρχει Το Substring word Στην Λέξη x Τότε Εκτυπώνει Την Λέξη Και Την Σημασία Της
        if(strstr(x, word) != NULL)
        {
            printf("English word: |    %s      |Tranlsation: |    %s \n", root->key, root->gkey); 
        }
        BinSearch(root->right, word); 
    } 
    return 0;
} 


int main() 
{ 
    //Αρχικοποίηση Του Δένδρου
    struct node *root = NULL; 
    root = insert(root, "gravity", "βαρύτητα");
    insert(root, "gin", "τζιν"); 
    insert(root, "gravel", "χαλίκι");
    insert(root, "mother", "μητέρα"); 
    insert(root, "black", "μαύρος"); 
    insert(root, "mirror", "καθρεύτης");
    insert(root, "cyberpunk", "σαιμπερπανκ");
    insert(root, "twotowers", "δύοπύργοι");
    char word[255];
    char gword[255];
    int COUNT = inorder(root);
    while(true)
    {
        //Μενού Επιλογής
        printf("Choose one from the following actions: \n 1:Insert element \n 2:Delete element \n 3:Search element \n 4:Print Binary tree \n 0:Exit system: ");
        int ans = 0;
        scanf("%d", &ans);
        switch (ans)
        {
            case 1:
                printf("Please insert the english word (Use only characters): ");
                scanf("%s", word);
                printf("Please insert the greek word (Use only characters): ");
                scanf("%s", gword);
                insert(root, word, gword);
                break;

            case 2:
                printf("Please delete(deletes a node) a word (Use only characters): ");
                scanf("%s", word);
                DelNode(root, word);
                break;

            case 3:
                printf("Please input chars (search based on chars): ");
                scanf("%s", word);
                ans = strlen(word);
                BinSearch(root, word);
                break;

            case 4:
                PrintBinTree(root,0, COUNT);
                break;

            default:
                exit(EXIT_SUCCESS);
                break;
        }
    } 
   
    return 0; 
}
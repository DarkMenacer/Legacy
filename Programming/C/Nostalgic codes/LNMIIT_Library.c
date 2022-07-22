/*
Write a C program for LNMIIT Library to maintain a link list of the books. The program should allow the librarian to add a book, issue a particular book to a student and display the number of issued and unissued books available in the library.

typedef struct{
  char *studentName;
  int studentID;
}Student;

struct Book{
  int ID;          // Unique ID of the book
  char *title      // Title of the book
  char *author;    // Author(s) of the book
  int isIssued;    // If the book is issued, it's value is 1, else 0 
  Student student; // Store details of the student to whom the book has been issued
  struct Book *nextBook; // Pointer to the next Book
};
You may need to create a link list of Book to store information of various books in the library. Your program shall show a menu containing 4 options and shall ask user to enter one choice (a, b, c, d). Any other choice should prompt the user and allows them to re-enter their choice. You may write a function  void Library_menu() to display the menu options.

The menu items and operations to be performed upon entering each of the choices are described below.

a. Add Book. Selecting this option will prompt the user to enter Book details (ID, title and author).  This should add a record of the book in the link list.  While inserting the details of a new book, make sure that the book with the same ID is not present in the link list. If the book with the same ID is present, prompt the user and allow them to enter the book details with a different ID. Once the insertion is done, print the message "<Book-Title>  is successfully added" (Example: How to program in C is successfully added). Again, the original menu containing the 4 options will be displayed.

b. Display. Selecting this option will provide the details of all the issued and unissued books available in the library. Again, the original menu containing the 4 options will be displayed.

c. Issue a book.  Selecting this option will prompt the user to enter the book title that he/she wants to issue. Check if the book with that title is available for issue. If multiple books with the same title are avaiable for issue, issue any available book to the student and print a message that <Book-title>, with book ID <book-ID> has been issued to <Student-name>(ID: <Student-ID>). For example: How to program in C, with book ID 1123 has been issued to xyz(ID: 112). After that again display the menu containing 4 options.

d. Exit Menu. Selecting this option will terminate the program with a ‘Good-Bye’ message
*/

#include <stdio.h>

void Menu();

struct Student{
    char *studentName;
    int studentID;
};

struct Book{
    int ID;
    char title[50];
    char author[50];
    int isIssued;
    struct Student;
    struct Book *nextBook;
}b[100];

int num = 0;
void Add_Book(){
    printf("\nPlease enter the ID,title and the author of the book respectively\n");
    scanf("%d %s %s",&b[num].ID,b[num].title,b[num].author);
    int i,flag=0;
    for(i=0;i<num;i++){
        if (b[num].ID == b[i].ID){
            printf("\nDuplicate ID Found\nPlease fill a different ID\n");
            flag = 1;
            break;
        }
    }
    if (flag!=1){
        printf("\n%s is successfully added\n",b[num].title);
        num++;
    }
    Menu();
}

void Issue(){
    printf("\nEnter the book name: ");
    
}

int main(){
    Menu();
    return 0;
}

void Menu(){
    char c;
    printf("\nPress 'a' to add a new book\nPress 'b' to know the status of the books");
    printf("\nPress 'c' to issue a book\nPress 'd' to exit the program\n");
    while(c!='d'){
        scanf("%c",&c);
        if (c=='a'){
            Add_Book();
        }
        else if (c=='b'){}
        else if (c=='c'){
            Issue();
        }
        else{
            break;
        }
    }
    if (c=='d'){
        printf("\nThank you for using the program\nGoodbye!\n");
    }
}    
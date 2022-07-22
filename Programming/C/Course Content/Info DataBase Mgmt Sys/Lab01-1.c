/*

6 September 2022

Create a file students (.txt or .dat) to store information of students of a university. The file should store student ID, NAME, and BRANCH. The following constraints should be satisfied to store the information in student table
    - Each student should have a unique student ID.
    - Insertion of a student with existing student ID should not be allowed.
    
Perform the following operation on the created student records. (NOTE: Create a menu driven program for better understanding)
    i. Insert 10 students in the student database.
    ii. Modify the NAME or BRANCH (CSE, EE, and ECE) of the student. Note that the modification of Student ID should not be allowed.
    iii. Delete the student using the Student ID.
    iv. Search the list of students using BRANCH.
    v. Search the student by their NAME.

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{
    int id;
    char name[10];
    char branch[3];
};

void Menu(int choice, FILE *fptr,struct student s[10]);

int main(){
    
    FILE *fptr = NULL;
    struct student s[10];    
    int choice = 1;
    while(choice){
        printf("Press '1' to enter 10 student entries\nPress '2' to modify name/branch\nPress '3' to delete student\nPress '4' to search list using branch\nPress '5' to search student by their name\nPress '6' to view the file\nPress '0' to exit\n");
        scanf("%d",&choice);
        fflush(stdin);
        Menu(choice,fptr,s);
    }
    return 0;
}

void Menu(int choice, FILE *fptr,struct student s[10]){
    int i,j;
    switch(choice){
        case 0:
            printf("Thank you for using the program!\nInfomation is stored in the file");
            break;
        case 1:
            fptr = fopen("student.txt","w+");
            for(i=0;i<10;++i){
                fflush(stdin);
                printf("Enter ID of %dth student: ",i+1);
                scanf("%d",&s[i].id);
                for(j=0;j<i;++j){if(s[j].id == s[i].id){printf("Duplicate ID!");exit(0);}}
                fflush(stdin);
                printf("Enter name of %dth student: ",i+1);
                scanf("%s",s[i].name);
                printf("Enter branch of %dth student: ",i+1);
                scanf("%s",s[i].branch );
                fwrite(&s[i],sizeof(struct student),1,fptr);
                fflush(stdin);
            }
            fclose(fptr);
            break;
        case 2:
            fflush(stdin);
            fptr = fopen("student.txt","w+");
            printf("Enter the ID for which data needs to be changed: ");
            int c;
            scanf("%d",&c);
            printf("Press '7' to change name or '8' to change branch: ");
            int c1;
            scanf("%d",&c1);
            printf("Enter the change: ");
            for(i=0;i<10;++i){
                if(s[i].id==c){
                    if(c1==7){scanf("%s",s[i].name);}
                    else if(c1==8){scanf("%s",s[i].branch);}
                    break;
                }
            }
            for(i=0;i<10;++i){fwrite(&s[i],sizeof(struct student),1,fptr);}
            fclose(fptr);
            break;
        case 3:
            fptr = fopen("student.txt","w+");
            struct student temp = {-1,"-DELETED-","-NA"};
            printf("Enter ID of student to be deleted: ");
            int c4;
            fflush(stdin);
            scanf("%d",&c4);
            for(i=0;i<10;++i){
                if(s[i].id == c4){s[i] = temp;} 
                fwrite(&s[i],sizeof(struct student),1,fptr);
            }
            fclose(fptr);
            break;
        case 4:
            fptr = fopen("student.txt","r");
            printf("Enter the branch you want to search for: ");
            char search[3];
            fflush(stdin);
            scanf("%s",search);
            for(i=0;i<10;++i){
                while(fread(&s[i],sizeof(struct student),1,fptr)){
                    if(!strcmp(s[i].branch,search)){printf("ID=> %d\t  NAME=> %s\tBRANCH=> %s\n",s[i].id,s[i].name,s[i].branch);}
                }
            }
            fclose(fptr);
            break;
        case 5:
            fptr = fopen("student.txt","r");
            printf("Enter the name you want to search for: ");
            fflush(stdin);
            scanf("%s",search);
            for(i=0;i<10;++i){
                while(fread(&s[i],sizeof(struct student),1,fptr)){
                    if(!strcmp(s[i].name,search)){printf("ID=> %d\t  NAME=> %s\tBRANCH=> %s\n",s[i].id,s[i].name,s[i].branch);}
                }
            }
            fclose(fptr);
            break;
        case 6:
            fptr = fopen("student.txt","r");
            for(i=0;i<10;++i){while(fread(&s[i],sizeof(struct student),1,fptr)){printf("ID=> %d\t  NAME=> %s\tBRANCH=> %s\n",s[i].id,s[i].name,s[i].branch);}}
            fclose(fptr);
            break;
        default:
            printf("Enter a valid input!TRY AGAIN\n");
            break;
    }
}